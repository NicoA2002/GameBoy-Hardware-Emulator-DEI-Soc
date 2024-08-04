/* This is the Cartridge Interface for SDRAM - MBC - GameBoy */
`define SDRAM_RAM_BASE 26'h2000000
module GameBoy_Cartridge
(
	input logic clk,
	input logic reset,
	
	output logic SYNC_clk,
	output logic GB_rst,
	
	/* Avalon Master for On-Chip RAM Read/Write - 16bits of memory, 8 bits wide */
	output logic [25:0] address,
	output logic read,
	output logic write,
	input logic [7:0] readdata,
	output logic [7:0] writedata,
	input logic waitrequest,
	
	/* Avalon Slave for HPS */
	input logic [25:0] hps_address,
	input logic hps_read,
	input logic hps_write,
	output logic [7:0] hps_readdata,
	input logic [7:0] hps_writedata,
	output logic hps_waitrequest,
	
	/* GameBoy Cartrdige Conduit */
	input logic [15:0] CART_ADDR,
	output logic [7:0] CART_DATA_in,
	input logic [7:0] CART_DATA_out,
	input logic CART_RD,
	input logic CART_WR,
	
	output logic [9:0] LEDR
);


logic rom_load_done;
assign LEDR = {10{rom_load_done}};

logic double_speed, double_speed_req;
always_ff @(posedge clk)
begin
	if (reset)
	begin
		rom_load_done <= 0;
		double_speed_req <= 0;
	end
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 1) && hps_write && !hps_waitrequest) rom_load_done <= hps_writedata[0];
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 2) && hps_write && !hps_waitrequest);
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 3) && hps_write && !hps_waitrequest);
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 4) && hps_write && !hps_waitrequest); 
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 5) && hps_write && !hps_waitrequest);
	else if (hps_address[25:0] == (`SDRAM_RAM_BASE - 6) && hps_write && !hps_waitrequest) double_speed_req <= hps_writedata;
end

always_comb
begin
	address = hps_address;
	read = hps_read;
	write = hps_write;
	hps_readdata = readdata;
	writedata = hps_writedata;
	hps_waitrequest = waitrequest;
	CART_DATA_in = 8'hFF;
	if (rom_load_done)
	begin
		address = {10'b0, CART_ADDR};
		read = CART_RD;
		write = 0;
		CART_DATA_in = readdata;
	end
end

logic [5:0] clk_div;
always_ff @(posedge clk)
begin
    if (reset || !rom_load_done) 
    begin
		GB_rst <= 1;
        //clk_div <= 8'h00;
        double_speed <= 0;
    end
    else
    begin
		if (clk_div[2] && !clk_div[3] && double_speed_req) double_speed <= double_speed;
		else if (!clk_div[2] && clk_div[3] && !double_speed_req) double_speed <= double_speed;
		else double_speed <= double_speed_req;
		
		if (waitrequest && ((!double_speed && clk_div[3:0] == 4'b0111) || (double_speed && clk_div[2:0] == 3'b011))) clk_div <= clk_div;
		else clk_div <= clk_div + 1;
		GB_rst <= 0;
	end
end

assign SYNC_clk = double_speed ? clk_div[2] : clk_div[3];

endmodule
