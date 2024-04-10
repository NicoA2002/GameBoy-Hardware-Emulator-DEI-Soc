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

logic [7:0] LY; 

logic [31:0] OAM_buf [9:0];

enum {SCAN, V_BLANK, H_BLANK, DRAW} state_modes;

always_ff @(posedge clk) begin
    if (rst) begin

    end else begin
	/* -- Following block happens on a per scanline basis (456 Cycles per line) -- */
        case (PPU_MODE)
            SCAN: begin 
	    	// go thru the OAM mem
		// 	if sprite_y in range and x > 0
		// 		add sprite data to OAM_buf
		// switch to draw_mode when we have finished mem 
		// 	-- (40 * 4 bytes have been read)
            end
	    DRAW: begin

	    end
	    H_BLANK: begin
		// idk man do some padding
	    end
	    V_BLANK: begin
		// idk man do some padding
	    end

        endcase

    end




end 
        
endmodule
    
