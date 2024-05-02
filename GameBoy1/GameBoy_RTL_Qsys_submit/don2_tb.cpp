#include <iostream>
#include <fstream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VPPU3.h"

typedef enum {H_BLANK, V_BLANK, SCAN, DRAW} PPU_STATES_t;

#define BG_MAP_1_BASE_ADDR 0x9800
#define BG_MAP_1_END_ADDR 0x9BFF

#define TILE_BASE 0x8000

int main(int argc, const char ** argv, const char ** env) 
{
	int time, exit_code, last_clk, row_1_loaded, cycles, tile_toggle, tile_row_cnt;
	char LCDC, tile_1[2], tile_2[2];
	VPPU3 *dut;
	std::ofstream f("tb_gen.ppm");

	if (!f.is_open()) {
		std::cerr << "Error opening ppm" << std::endl;
		exit_code = -1;
		return exit_code;
	}
	f << "P2\n160 144\n4\n";

	tile_row_cnt = tile_toggle = cycles = last_clk = time = exit_code = row_1_loaded = 0;

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
	for (time = 0 ; time < 1368000 ; time += 10) {
		last_clk = dut->clk;
    	dut->clk = ((time % 20) >= 10) ? 1 : 0; 	// Simulate a 50 MHz clock
		if (dut->PPU_MODE == H_BLANK) {
			cycles = 0;
			tile_row_cnt = 0;
		} else if (dut->clk == 1)
    		cycles++;

    	dut->rst = (time == 30) ? 1 : 0;			// pulses rst 
    	if (dut->rst == 1)
    		cycles = 0;

		if (dut->PPU_MODE == DRAW && dut->clk == 1) {
			if (dut->PPU_ADDR >= BG_MAP_1_BASE_ADDR && dut->PPU_ADDR < BG_MAP_1_END_ADDR) {
				dut->PPU_DATA_in = !(tile_row_cnt % 2 == 0);					// tells it to pull from file 1
				row_1_loaded = 0;
			}

			else if ((TILE_BASE <= dut->PPU_ADDR) && (TILE_BASE + 16 > dut->PPU_ADDR)) {
					if (!row_1_loaded) {
						tile_row_cnt++;
						dut->PPU_DATA_in = tile_2[0];
						row_1_loaded = 1;
					}
					else 
						dut->PPU_DATA_in = tile_2[1];
			}

			else if ((TILE_BASE + 16 <= dut->PPU_ADDR) && (TILE_BASE + 32 > dut->PPU_ADDR)) {
					if (!row_1_loaded) {
						tile_row_cnt++;
						dut->PPU_DATA_in = tile_1[0];
						row_1_loaded = 1;
					}
					else 
						dut->PPU_DATA_in = tile_1[1];
			}
		}
    	dut->eval();     			// Run the simulation for a cycle
    	tfp->dump(time); 			// Write the VCD file for this cycle

    	if (dut->clk != last_clk && dut->clk == 1) {	// on posedge of clock
    		/* Writes to ppm file */
    		if ((int)dut->PX_valid == 1) {
    			f << (int) dut->PX_OUT << " ";
    		}
    	}
    }

	tfp->close(); // Stop dumping the VCD file
	delete tfp;

	dut->final(); // Stop the simulation
	delete dut;

	f.close();
	return exit_code;
}

