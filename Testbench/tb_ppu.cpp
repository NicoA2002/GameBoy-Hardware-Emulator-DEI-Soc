#include <iostream>
#include "VPPU3.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cstdio>

// input logic [15:0] ADDR,
// input logic WR,
// input logic [7:0] MMIO_DATA_out,
// output logic [7:0] MMIO_DATA_in,

int main(int argc, const char ** argv, const char ** env) {
	char Tile_Map[1024];

	for (int i = 0; i<8; i++) Tile_Map[240 + i] = 1;

	int i, time;
	OAM_Ent ent;
	int offset, exit_code;
	char LCDC;
	VPPU3 *dut;
	int tile_req;
	offset = exit_code = 0;
	char line_buf[160] = {0};
	char line_buf_cnt = 0;

	Verilated::commandArgs(argc, argv);

	dut = new VPPU3;  	// Instantiate the ppu module

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	dut->trace(tfp, 99);
	tfp->open("ppu3.vcd");

	LCDC = 0xFF;
	0x9C00
	dut->WR = 1;
	dut->ADDR = 0xFF40;
	dut->MMIO_DATA_out = LCDC;

	for (time = 0 ; time < 10000 ; time += 10) {
    	dut->clk = ((time % 20) >= 10) ? 1 : 0; 	// Simulate a 50 MHz clock

    	dut->rst = (time == 30) ? 1 : 0;	// pulses rst 
		dut->PPU_DATA_in = 0;

		//for map 2 and 8000 addressing method, due to LCDC = FF
		tile_req = (dut->PPU_ADDR - 0x9C00)/16;
		if (tile_req == 0) dut->PPU_DATA_in = 0;
		if (tile_req == 1) dut->PPU_DATA_in = 1;

		if (dut->PX_valid) line_buf[line_buf_cnt = (line_buf_cnt + 1)%160] = dut->PX_OUT;
		if (line_buf_cnt == 159) {
			for (int i = 0; i<160; i++) printf("%d", line_buf[i]);
			printf(" \n");
		}
    	dut->eval();     			// Run the simulation for a cycle
    	tfp->dump(time); 			// Write the VCD file for this cycle
    }

	tfp->close(); // Stop dumping the VCD file
	delete tfp;

	dut->final(); // Stop the simulation
	delete dut;

	return exit_code;
}

