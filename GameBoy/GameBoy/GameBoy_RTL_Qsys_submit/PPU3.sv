`timescale 1ns / 1ns

//Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

`define NO_BOOT 0

module PPU3
(
    input logic clk,
    input logic rst,
    
    /* OAM */
    input logic [15:0] ADDR,
    input logic WR,
    input logic RD,
    input logic [7:0] MMIO_DATA_out,
    output logic [7:0] MMIO_DATA_in,
    
    /* Interrupts */
    output logic IRQ_V_BLANK,	// handled by an assign block
    output logic IRQ_LCDC,
    
    output logic [1:0] PPU_MODE,
    
    /* VRAM */
    output logic PPU_RD,
    output logic [15:0] PPU_ADDR,
    input logic [7:0] PPU_DATA_in,
    
    output logic [1:0] PX_OUT,
    output logic PX_valid
);

logic [7:0] LY, LX; 

// X_POS

// need a definition for background_fifo
// need a definition for sprite_fifo

// sprite_buf def

enum {SCAN, V_BLANK, H_BLANK, DRAW} state_modes;

always_ff @(posedge clk) begin
    if (rst) begin

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
		// pixel fetcher
		// 	for bg:
		// 		grab the tile number
	    end
	    H_BLANK: begin
		// idk man do some padding to 456 cycles
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
    
