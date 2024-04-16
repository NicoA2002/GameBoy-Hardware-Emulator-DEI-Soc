`timescale 1ns / 1ns

//Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

`define OAM_BASE_ADDR 16'hFE00
`define OAM_BASE_ADDR 16'hFE9F

`define PPU_ADDR_INC(x) PPU_ADDR <= PPU_ADDR + x;

module PPU3
(
    input logic clk,
    input logic rst,
    
    input logic [15:0] ADDR,
    input logic WR,
    input logic RD,
    input logic [7:0] MMIO_DATA_out,
    output logic [7:0] MMIO_DATA_in,
    
    /* Interrupts */
    output logic IRQ_V_BLANK,	// handled by an assign block
    output logic IRQ_LCDC,
    
    output logic [1:0] PPU_MODE,
    
    output logic PPU_RD,
    output logic [15:0] PPU_ADDR,
    input logic [7:0] PPU_DATA_in,
    
    output logic [1:0] PX_OUT,
    output logic PX_valid
);

logic sprite_in_range;
logic [7:0] LY, x_pos;  // x-pos in range [0, 159]

logic [8:0] cycles;

logic [1:0] ppu_mode;

logic [3:0] sprites_loaded;
logic [7:0] sprite_y_buff;
logic [7:0] sprite_x_buff;

typedef enum {SCAN, V_BLANK, H_BLANK, DRAW} PPU_STATES_t;
typedef enum {OAM_LOAD, OAM_CHECK} OAM_STATES_t;

/* External registers */
logic [7:0] LCDC, STAT, SCX, SCY, LYC, DMA, BGP, OBP0, OBP1, WX, WY; // Register alias

logic [7:0] FF40;
assign LCDC = FF40;

logic [7:0] FF41;
assign STAT = FF41;

logic [7:0] FF42;
assign SCY = FF42;

logic [7:0] FF43;
assign SCX = FF43;

logic [7:0] FF44;

logic [7:0] FF45;
assign LYC = FF45;

logic [7:0] FF46;
assign DMA = FF46;

logic [7:0] FF47;
assign BGP = FF47;

logic [7:0] FF48; 
assign OBP0 = {FF48[7:2], 2'b00}; // Last 2 bits are not used

logic [7:0] FF49;
assign OBP1 = {FF49[7:2], 2'b00};

logic [7:0] FF4A;
assign WY = FF4A;

logic [7:0] FF4B;
assign WX = FF4B;

/* Register Assignment
 * 
 * 	if a register memory address is being indexed it gets updated here 
 */
always_ff @(posedge clk)
begin
    if (rst)
    begin
        FF40 <= `NO_BOOT ? 8'h91 : 0;
        FF41 <= 0;
        FF42 <= 0;
        FF43 <= 0;
        FF45 <= 0;
        FF46 <= 0;
        FF47 <= `NO_BOOT ? 8'hFC : 0;
        FF48 <= `NO_BOOT ? 8'hFF : 0;
        FF49 <= `NO_BOOT ? 8'hFF : 0;
        FF4A <= 0; 
        FF4B <= 0;  
    end
    else
    begin
        FF40 <= (WR && (ADDR == 16'hFF40)) ? MMIO_DATA_out : FF40;
		    FF41 <= (WR && (ADDR == 16'hFF41)) ? {MMIO_DATA_out[7:3], FF41[2:0]} : {FF41[7:3], LYC == LY, PPU_MODE};
		    FF42 <= (WR && (ADDR == 16'hFF42)) ? MMIO_DATA_out : FF42;
		    FF43 <= (WR && (ADDR == 16'hFF43)) ? MMIO_DATA_out : FF43;
		    FF45 <= (WR && (ADDR == 16'hFF45)) ? MMIO_DATA_out : FF45;
		    FF46 <= (WR && (ADDR == 16'hFF46)) ? MMIO_DATA_out : FF46;
		    FF47 <= (WR && (ADDR == 16'hFF47)) ? MMIO_DATA_out : FF47;
		    FF48 <= (WR && (ADDR == 16'hFF48)) ? MMIO_DATA_out : FF48;
		    FF49 <= (WR && (ADDR == 16'hFF49)) ? MMIO_DATA_out : FF49;
		    FF4A <= (WR && (ADDR == 16'hFF4A)) ? MMIO_DATA_out : FF4A;
		    FF4B <= (WR && (ADDR == 16'hFF4B)) ? MMIO_DATA_out : FF4B;
    end
end

/* 
 * If we detect a memory request we return back the current
 * state of the register
 */ 
always_comb	// doesn't wait for a posedge clk
begin
    case (ADDR)
        16'hFF40: MMIO_DATA_in = FF40;
        16'hFF41: MMIO_DATA_in = {1'b1, FF41[6:0]};
        16'hFF42: MMIO_DATA_in = FF42;
        16'hFF43: MMIO_DATA_in = FF43;
        16'hFF44: MMIO_DATA_in = FF44;
        16'hFF45: MMIO_DATA_in = FF45;
        16'hFF46: MMIO_DATA_in = FF46;
        16'hFF47: MMIO_DATA_in = FF47;
        16'hFF48: MMIO_DATA_in = FF48;
        16'hFF49: MMIO_DATA_in = FF49;
        16'hFF4A: MMIO_DATA_in = FF4A;
        16'hFF4B: MMIO_DATA_in = FF4B;
        default : MMIO_DATA_in = 8'hFF;
    endcase
end

/* -- State Switching machine -- */
always_ff @(posedge clk) begin
    if (rst) begin
			x_pos <= 0;
			cycles <= 0;
			LY <= 0;
			PPU_ADDR <= OAM_BASE_ADDR;
			ppu_mode <= SCAN;
    end else begin
    	cycles <= cycles + 1;
	/* -- Following block happens on a per scanline basis (456 cycles per line) -- */
        case (ppu_mode)
            SCAN: 
		    	if (PPU_ADDR > OAM_END_ADDR) 
					ppu_mode <= DRAW;
	    	// go thru the OAM mem
			// 	if sprite_y in range and x > 0
			// 		add sprite data to sprite_buf
			// switch to draw_mode when we have finished mem 
			// 	-- (40 * 4 bytes have been read)
	    DRAW: begin
		// sprite-staging mode:
		// 	1 - if sprite-x is in range grab it
		// 	2 - pause bg-staging
		// 	3 - fetches sprite tile from buffer 
		// 	4 - same as 2 & 3 in bg-stage mode
		//
		// bg-staging mode:
		// 	1 - grabs the current tile (use x-pos as an offset
		// 		from the base)
		//	2 - grabs the corresponding row of byte from the tile
		//		saved
		//	3 - grabs the next row so that our color can be
		//		encoded
		//	4 - decode and push the row into the FIFO
		//
		// drawing mode:
		// 	1 - apply the bg fifo mask for SCX
		// 	2 - grab pixel and do mixing
		// 	3 - push to LCD
		// 	4 - increment x-pos	
		// 	5 - check if we've hit the window
		//
		// if x-pos == 160 then move to h-blank
	    end
	    H_BLANK: begin
		// stall to 456 cycles
	    end
	    V_BLANK: begin
		// idk man do some padding to 456 lines, 10 extra lines that last 456 cycles
	    end
        endcase
    end

assign sprite_in_range = ((LY + 16 >= PPU_DATA_in) && \
				(LY + 16 < PPU_DATA_in + (8 << LCDC[2])));

/* -- OAM Scan State Machine -- */
always_ff @(posedge clk) begin
	if (rst || ppu_mode == H_BLANK) begin
		sprites_loaded <= 0;
		sprite_found <= 0;
	end else if (ppu_mode == SCAN) begin
		if (!cycles[0])					// forces alternating clock cycles
			if (sprite_in_range && sprites_loaded < 10) begin
				sprites_loaded <= sprites_loaded + 1;
				sprite_y_buff[sprites_loaded] <= PPU_DATA_in;
				sprite_found <= 1;
				PPU_ADDR_INC(1);						// jumps to x-byte
			end else
				PPU_ADDR_INC(4);						// jumps to next sprite in OAM
		else begin
			if (sprite_found) begin
				sprite_x_buff[sprites_loaded - 1] <= PPU_DATA_in;
				PPU_ADDR_INC(3);						// jumps to next sprite in OAM
			end
			sprite_found <= 0;
		end

	end
end 
        
endmodule

module FIFO #(
  parameter  DataWidth = 32,
  parameter  Depth     = 8,
  localparam PtrWidth  = $clog2(Depth)
) (
  input  logic                 clk,
  input  logic                 rstN,
  input  logic                 writeEn,
  input  logic [DataWidth-1:0] writeData,
  input  logic                 readEn,
  output logic [DataWidth-1:0] readData,
  output logic                 full,
  output logic                 empty
);

  logic [DataWidth-1:0] mem[Depth];
  logic [PtrWidth:0] wrPtr, wrPtrNext;
  logic [PtrWidth:0] rdPtr, rdPtrNext;

  always_comb begin
    wrPtrNext = wrPtr;
    rdPtrNext = rdPtr;
    if (writeEn) begin
      wrPtrNext = wrPtr + 1;
    end
    if (readEn) begin
      rdPtrNext = rdPtr + 1;
    end
  end

  always_ff @(posedge clk or negedge rstN) begin
    if (!rstN) begin
      wrPtr <= '0;
      rdPtr <= '0;
    end else begin
      wrPtr <= wrPtrNext;
      rdPtr <= rdPtrNext;
    end

    mem[wrPtr[PtrWidth-1:0]] <= writeData;
  end

  assign readData = mem[rdPtr[PtrWidth-1:0]];

  assign empty = (wrPtr[PtrWidth] == rdPtr[PtrWidth]) && (wrPtr[PtrWidth-1:0] == rdPtr[PtrWidth-1:0]);
  assign full  = (wrPtr[PtrWidth] != rdPtr[PtrWidth]) && (wrPtr[PtrWidth-1:0] == rdPtr[PtrWidth-1:0]);

endmodule
    
