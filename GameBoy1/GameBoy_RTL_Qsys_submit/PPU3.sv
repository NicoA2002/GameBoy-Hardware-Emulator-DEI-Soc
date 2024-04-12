`timescale 1ns / 1ns

//Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

`define NO_BOOT 0

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

logic [7:0] LY, x_pos; 
logic [15:0] cur_addr;

// x-pos in range [0, 159]

// need a definition for background_fifo
// need a definition for sprite_fifo

// sprite_buf def 	- {stores at least x-pos, tile no}

// LCDC		-- lcd control flags
// STAT		-- ppu status flags

typedef enum {SCAN, V_BLANK, H_BLANK, DRAW} PPU_STATES_t;

always_ff @(posedge clk) begin
    if (rst) begin
	x_pos <= 0;
	LY <= 0;
	cur_addr // thing addr we need to start on OAM
	// happen on every frame
	// reset LY to 0
	// x-pos to 0
	// clear all buffers
    end else begin
	/* -- Following block happens on a per scanline basis (456 Cycles per line) -- */
        case (PPU_MODE)
            SCAN: begin 
	    	// go thru the OAM mem
		// 	if sprite_y in range and x > 0
		// 		add sprite data to sprite_buf
		// switch to draw_mode when we have finished mem 
		// 	-- (40 * 4 bytes have been read)
            end
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
    
