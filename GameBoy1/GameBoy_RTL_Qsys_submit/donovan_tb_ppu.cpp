#include <iostream>
#include "VPPU3.h"
#include <verilated.h>
#include <verilated_vcd_c.h>

typedef enum {H_BLANK, V_BLANK, SCAN, DRAW} PPU_STATES_t;

#define BG_MAP_1_BASE_ADDR 0x9800
#define BG_MAP_1_END_ADDR 0x9BFF

#define TILE_BASE 0x8000

int main(int argc, const char ** argv, const char ** env) 
{
	int time, offset, exit_code, row_code, cycles, tile_toggle;
	char LCDC, last_px_state, tile_1[2], tile_2[2];
	VPPU3 *dut;
	std::ofstream f("tb_gen.ppm");

	if (!f.is_open()) {
		std::cerr << "Error opening ppm" << std::endl;
		exit_code = -1;
		return exit_code;
	}
	f << "P2\n160 8\n144\n";

	tile_toggle = cycles = row_code = offset = exit_code = 0;
	last_px_state = 0;

	tile_1[0] = 0xFF;	// 1111_1111
	tile_1[1] = 0x00;	// 0000_0000

	tile_2[0] = 0xAA;	// 1010_1010
	tile_2[1] = 0x55;	// 0101_0101

	Verilated::commandArgs(argc, argv);

	dut = new VPPU3;  	// Instantiate the ppu module

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	dut->trace(tfp, 99);
	tfp->open("ppu3.vcd");

	LCDC = 0xFF;
	dut->WR = 1;
	dut->ADDR = 0xFF40;
	dut->MMIO_DATA_out = LCDC;

	dut->PPU_DATA_in = 0xFF;	// JUNK
	for (time = 0 ; time < 10000 ; time += 10) {
		last_px_state = dut->PX_valid;
    	dut->clk = ((time % 20) >= 10) ? 1 : 0; 	// Simulate a 50 MHz clock
		if (dut->PPU_MODE == H_BLANK)
			cycles = 0;
    	else if (dut->clk == 1)
    		cycles++;

    	dut->rst = (time == 30) ? 1 : 0;			// pulses rst 
    	if (dut->rst == 1)
    		cycles = 0;

		if (dut->PPU_MODE == DRAW && dut->clk == 1) {
			if (dut->PPU_ADDR >= BG_MAP_1_BASE_ADDR && dut->PPU_ADDR < BG_MAP_1_END_ADDR)
				dut->PPU_DATA_in = tile_toggle;
			else if (dut->PPU_ADDR >= TILE_BASE && cycles > 81) 
					if (tile_toggle)
						dut->PPU_DATA_in = tile_2[row_code];
					else
						dut->PPU_DATA_in = tile_1[row_code];
					row_code = !row_code;
		}
    	dut->eval();     			// Run the simulation for a cycle
    	tfp->dump(time); 			// Write the VCD file for this cycle

    	if (last_px_state == 0x00 && dut->PX_valid == 1)	// posedge of PX_valid
    		tile_toggle = !tile_toggle;

    	if (dut->PX_valid) {
    		f << dut->PX_OUT << " ";
    	}
    }

	tfp->close(); // Stop dumping the VCD file
	delete tfp;

	dut->final(); // Stop the simulation
	delete dut;

	f.close();
	return exit_code;
}

