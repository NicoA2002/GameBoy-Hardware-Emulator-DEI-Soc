module Quartus_dual_port_dual_clk_ram
#(parameter DATA_WIDTH=2, parameter ADDR_WIDTH=15, parameter DEPTH = 23040)
(
	input [(DATA_WIDTH-1):0] data,
	input [(ADDR_WIDTH-1):0] read_addr, write_addr,
	input we, read_clk, write_clk,
	output reg [(DATA_WIDTH-1):0] q
);
	
	// Declare the RAM variable
	reg [DATA_WIDTH-1:0] ram[DEPTH-1:0];
	
	always @ (posedge write_clk)
	begin
		// Write
		if (we)
			ram[write_addr] <= data;
	end
	
	always @ (posedge read_clk)
	begin
		// Read 
		q <= ram[read_addr];
	end
	
endmodule
