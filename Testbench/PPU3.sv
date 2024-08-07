`timescale 1ns / 1ns

//Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

/* WARNING: DOES NOT HAVE INTERRUPTS OR ANY EXTERNAL OUTPUTS IMPLEMENTED */

module PPU3
(
    input logic clk,
    input logic rst,
    
    /* System access for PPU internal registers */
    input logic [15:0] ADDR,
    input logic WR,
    input logic RD,
    input logic [7:0] MMIO_DATA_out,
    output logic [7:0] MMIO_DATA_in,
    
    /* Interrupts */
    output logic IRQ_V_BLANK,
    output logic IRQ_LCDC,
    
    output logic [1:0] PPU_MODE,
    
    /* VRAM access for PPU */
    output logic PPU_RD,
    output logic [15:0] PPU_ADDR,
    input logic [7:0] PPU_DATA_in,
    
    output logic [1:0] PX_OUT,
    output logic PX_valid
);

`define OAM_BASE_ADDR 16'hFE00
`define OAM_END_ADDR 16'hFE9F
`define NO_BOOT 0

`define PPU_ADDR_INC(x) PPU_ADDR <= PPU_ADDR + x;

logic sprite_in_range;
logic [7:0] LY, x_pos;  // x-pos in range [0, 159]
logic [15:0] current_offset;
logic [3:0] sprites_loaded;
logic sprite_found;

logic [8:0] cycles;

// logic [1:0] PPU_MODE;

logic [7:0] sprite_y_buff [9:0];
logic [7:0] sprite_x_buff [9:0];
logic [7:0] sprite_offset_buff [9:0]; 		// stores start of sprite entries in OAM (entry + 2 => for tile no.)

logic sprite_shift_go;
logic sprite_shift_load;
logic [1:0] sprite_shift_output;
logic [7:0] sprite_tile_row [1:0];

PPU_SHIFT_REG sprite_fifo(.clk(clk), .rst(rst), .data(sprite_tile_row), .go(sprite_shift_go), .load(sprite_shift_load), .q(sprite_shift_output));

logic bg_shift_go;
logic bg_shift_load;
logic [1:0] bg_shift_output;
logic [7:0] bg_tile_row [1:0];

PPU_SHIFT_REG bg_fifo(.clk(clk), .rst(rst), .data(bg_tile_row), .go(bg_shift_go), .load(bg_shift_load), .q(bg_shift_output));

typedef enum bit [1:0] {H_BLANK, V_BLANK, SCAN, DRAW} PPU_STATES_t;

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

/* ----------------- End of declarations */

/* Register Assignment
 * 
 * 	if a register memory address is being indexed it gets updated here 
 *  -- As a warning the following may introduce timing oddities compared to other group
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
			PPU_ADDR <= `OAM_BASE_ADDR;
			PPU_MODE <= SCAN;
    end else if (LCDC[7]) begin
    	cycles <= cycles + 1;
		/* -- Following block happens on a per scanline basis (456 cycles per line) -- */
        case (PPU_MODE)
            SCAN: begin
		    	if (PPU_ADDR > `OAM_END_ADDR) 
					PPU_MODE <= DRAW;
				if (LY >= 144)
					PPU_MODE <= V_BLANK;
			end
		    DRAW: 
		    	LY <= LY;
		    	// if x_pos is off-screen switch to H_blank
		    H_BLANK: 
		    	if (cycles >= 455) begin		// we reached the end of the scanline
					LY <= LY + 1;
					x_pos <= 0;
					PPU_MODE <= SCAN;
					cycles <= 0;
				end
		    V_BLANK: 							// not technically necessary but here for completeness
				PPU_MODE <= H_BLANK;
        endcase
    end
end

assign sprite_in_range = ((LY + 16 >= PPU_DATA_in) &&
							(LY + 16 < PPU_DATA_in + (8 << LCDC[2])));
assign current_offset = PPU_ADDR - `OAM_BASE_ADDR;
/* -- OAM Scan State Machine -- */
always_ff @(posedge clk) begin
	if (rst || PPU_MODE == H_BLANK) begin
		sprites_loaded <= 0;
		sprite_found <= 0;
	end else if (PPU_MODE == SCAN) begin
		if (!cycles[0])	begin				// forces alternating clock cycles
			if (sprite_in_range && sprites_loaded < 10) begin
				sprites_loaded <= sprites_loaded + 1;
				sprite_y_buff[sprites_loaded] <= PPU_DATA_in;
				sprite_offset_buff[sprites_loaded] <= current_offset[7:0];
				sprite_found <= 1;
				`PPU_ADDR_INC(1);						// jumps to x-byte
			end else `PPU_ADDR_INC(4);						// jumps to next sprite in OAM
		end else begin
			if (sprite_found) begin
				sprite_x_buff[sprites_loaded - 1] <= PPU_DATA_in;
				`PPU_ADDR_INC(3);						// jumps to next sprite in OAM
			end
			sprite_found <= 0;
		end

	end
end 

/* BG Draw Machine */
always_ff @(posedge clk) begin
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
        
endmodule
    
module PPU_SHIFT_REG
(
    input clk,
    input rst,
    input logic [7:0] data [1:0],
    input logic go,
    input logic load,
    output logic [1:0] q
);

logic [7:0] shift_reg [0:1];

always_ff @(posedge clk)
begin
    if (rst)
    begin
        shift_reg[0] <= 0;
        shift_reg[1] <= 0;
    end
    else if (load)
    begin
        shift_reg[0] <= data[0];
        shift_reg[1] <= data[1];
    end
    else
    begin
        if (go)
        begin
            shift_reg[0][7:1] <= shift_reg[0][6:0];
            shift_reg[0][0] <= 0;
            shift_reg[1][7:1] <= shift_reg[1][6:0];
            shift_reg[1][0] <= 0;
        end
    end
end

assign q = {shift_reg[1][7], shift_reg[0][7]};
        
endmodule
    