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
    
    output logic IRQ_V_BLANK,
    output logic IRQ_LCDC,
    
    output logic [1:0] PPU_MODE,
    
    output logic PPU_RD,
    output logic [15:0] PPU_ADDR,
    input logic [7:0] PPU_DATA_in,
    
    output logic [1:0] PX_OUT,
    output logic PX_valid
);

logic [7:0] LCDC, STAT, SCX, SCY, LYC, DMA, BGP, OBP0, OBP1, WX, WY; // Register alias
logic [31:0] OAM_Buf [9:0];

enum {SCAN, V_BLANK, H_BLANK, DRAW} state_modes;

always_ff @(posedge clk) begin
    if (rst) begin

    end else begin
        case (PPU_MODE)
            SCAN: begin //go through memory values of OAM, if finds puts in OAM buffer,
                
            end
            V_BLANK:

        endcase

    end




end 
        
endmodule
    
