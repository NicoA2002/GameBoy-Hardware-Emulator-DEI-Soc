#include <iostream>
#include <fstream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VPPU3.h"

typedef enum {PPU_H_BLANK, PPU_V_BLANK, PPU_SCAN, PPU_DRAW} PPU_STATES_t;

#define BG_MAP_1_BASE_ADDR 0x9800
#define BG_MAP_1_END_ADDR 0x9BFF

#define OAM_BASE_ADDR 0xFE00

#define TILE_BASE 0x8000

int main(int argc, const char ** argv, const char ** env) 
{
	int time, exit_code, last_clk, row_1_loaded, cycles, tile_toggle, tile_row_cnt;
	char LCDC, tile_1[2], tile_2[2], tile_3, sprite_data[4];
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

	tile_3 = 0x00;

	sprite_data[0] = 16 + (8 * 1);		// (y-value)		16 + pos
	sprite_data[1] = 8 + (8 * 1);		// (x-value)		 8 + pos
	sprite_data[2] = 2;					// (tile no.)
	sprite_data[3] = 0x00;				// flags (prio and other things)

	Verilated::commandArgs(argc, argv);

	dut = new VPPU3;  	// Instantiate the ppu module

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	dut->trace(tfp, 99);
	tfp->open("ppu3.vcd");

	LCDC = 0xFB;
	dut->WR = 1;
	dut->ADDR = 0xFF40;
	dut->MMIO_DATA_out = LCDC;

	dut->PPU_DATA_in = 0x0;	// JUNK
	for (time = 0 ; time < 1368000 ; time += 10) {
		// Simulate a 50 MHz clock
		last_clk = dut->clk;							// used to detect negedge
    	dut->clk = ((time % 20) >= 10) ? 1 : 0;
		if (dut->clk == 1)
    		cycles++;

    	// Triggers rst
    	dut->rst = (time == 30) ? 1 : 0;
    	if (dut->rst == 1)
    		cycles = 0;
    	
    	if (dut->clk == 1) {
			if (dut->PPU_ADDR == OAM_BASE_ADDR)
				dut->PPU_DATA_in = sprite_data[0];
			if (dut->PPU_ADDR == OAM_BASE_ADDR + 1)
				dut->PPU_DATA_in = sprite_data[1];
			if (dut->PPU_ADDR == OAM_BASE_ADDR + 2)
				dut->PPU_DATA_in = sprite_data[2];
			if (dut->PPU_ADDR == OAM_BASE_ADDR + 3)
				dut->PPU_DATA_in = sprite_data[3];
		}

		if (dut->PPU_MODE == PPU_DRAW && dut->clk == 1) {
			if (dut->PPU_ADDR >= BG_MAP_1_BASE_ADDR && dut->PPU_ADDR < BG_MAP_1_END_ADDR) {
				dut->PPU_DATA_in = !(tile_row_cnt % 2 == 0);					// tells it to pull from file 1
				row_1_loaded = 0;
			}

			else if ((TILE_BASE + (16*0) <= dut->PPU_ADDR) && (TILE_BASE + (16*1) > dut->PPU_ADDR)) {
					if (!row_1_loaded) {
						tile_row_cnt++;
						dut->PPU_DATA_in = tile_2[0];
						row_1_loaded = 1;
					}
					else 
						dut->PPU_DATA_in = tile_2[1];
			}

			else if ((TILE_BASE + (16*1) <= dut->PPU_ADDR) && (TILE_BASE + (16*2) > dut->PPU_ADDR)) {
					if (!row_1_loaded) {
						tile_row_cnt++;
						dut->PPU_DATA_in = tile_1[0];
						row_1_loaded = 1;
					}
					else 
						dut->PPU_DATA_in = tile_1[1];
			}

			else if ((TILE_BASE + (16*2) <= dut->PPU_ADDR) && (TILE_BASE + (16*3) > dut->PPU_ADDR)) {
					dut->PPU_DATA_in = tile_3;
			}
		}

		if (dut->PPU_MODE == PPU_H_BLANK) {
			cycles = 0;
			tile_row_cnt = 0;
			dut->PPU_DATA_in = 0x0;
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

