#include <iostream>
#include <fstream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VPPU3.h"

typedef enum {PPU_H_BLANK, PPU_V_BLANK, PPU_SCAN, PPU_DRAW} PPU_STATES_t;

#define BG_MAP_1_BASE_ADDR 0x9800
#define BG_MAP_1_END_ADDR 0x9BFF

#define OAM_BASE_ADDR 0xFE00

#define TILE_BASE_ADDR 0x8000
#define TILE_END_ADDR  0x97FF

int main(int argc, const char ** argv, const char ** env) 
{
	int time, exit_code, last_clk, row_1_loaded, cycles, tile_toggle, tile_row_cnt, scan_line, i;
	char tile_1[2], tile_2[2], tile_3, sprite_data[4], OAM_MEM[160], BG_MAP[1024], TILE_MAP[6144], update_reg;
	VPPU3 *dut;
	std::ofstream f("tb_gen.ppm");

	if (!f.is_open()) {
		std::cerr << "Error opening ppm" << std::endl;
		exit_code = -1;
		return exit_code;
	}
	f << "P2\n160 144\n4\n";

	scan_line = tile_row_cnt = tile_toggle = cycles = last_clk = time = exit_code = row_1_loaded = 0;

	for (i = 0; i < 1024; i++)
		BG_MAP[i] = i % 2;

	for (i = 0; i < 16; i += 2) {
		TILE_MAP[i] = 0xFF;					// 1111_1111
		TILE_MAP[i+1] = 0x00;				// 0000_0000

		TILE_MAP[16 + i] = 0xAA;			// 1010_1010
		TILE_MAP[16 + i + 1] = 0x55;		// 0101_0101

		TILE_MAP[16 + 16 + i] = 0xFF;		// "sprite"
		TILE_MAP[16 + 16 + i + 1] = 0xFF;
	}

	OAM_MEM[0] = 16;				// (y-value)		16 + pos
	OAM_MEM[1] = 8 + (8 * 1);		// (x-value)		 8 + pos
	OAM_MEM[2] = 2;					// (tile no.)
	OAM_MEM[3] = 0xFF >> 1;				// flags (prio and other things)

	OAM_MEM[4] = 16 + (8 * 1);				// (y-value)		16 + pos
	OAM_MEM[5] = 8 + (8 * 2);		// (x-value)		 8 + pos
	OAM_MEM[6] = 2;					// (tile no.)
	OAM_MEM[7] = 0xFF >> 1;				// flags (prio and other things)

	Verilated::commandArgs(argc, argv);

	dut = new VPPU3;  	// Instantiate the ppu module

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	dut->trace(tfp, 99);
	tfp->open("ppu3.vcd");

	dut->PPU_DATA_in = 0x0;	// JUNK

	for (time = 0 ; time < 2272110 ; time += 10) {
		// Simulate a 50 MHz clock
		last_clk = dut->clk;							// used to detect posedge
    	dut->clk = ((time % 20) >= 10) ? 1 : 0;
		if (dut->clk == 1)
    		cycles++;

    	// Triggers rst
    	dut->rst = (time == 30) ? 1 : 0;
    	if (dut->rst == 1)
    		cycles = 0;

    	// only on posedge
    	if (dut->clk == 1) {
	    	if (time > 40) { // after rst
	    		if (!(update_reg & 0x1)) { // LCDC
					dut->WR = 1;
					dut->ADDR = 0xFF40;
					dut->MMIO_DATA_out = 0xFB;
					update_reg |= 0x1;
	    		} else if (!(update_reg & 0x2)) {
	    			dut->WR = 1;
	    			dut->ADDR = 0xFF43;
	    			dut->MMIO_DATA_out = 0x2;
	    			update_reg |= 0x2;
	    		} else if (!(update_reg & 0x4)) {
	    			dut->WR = 1;
	    			dut->ADDR = 0xFF42;
	    			dut->MMIO_DATA_out = 0x2;
	    			update_reg |= 0x4;
	    		} else
	    			dut->WR = 0;

	    	}


			if (dut->PPU_ADDR >= OAM_BASE_ADDR && dut->PPU_ADDR < OAM_BASE_ADDR + 160)
				dut->PPU_DATA_in = OAM_MEM[dut->PPU_ADDR - OAM_BASE_ADDR];
			else if (dut->PPU_ADDR >= BG_MAP_1_BASE_ADDR && dut->PPU_ADDR <= BG_MAP_1_END_ADDR)
				dut->PPU_DATA_in = BG_MAP[dut->PPU_ADDR - BG_MAP_1_BASE_ADDR];
			else if (dut->PPU_ADDR >= TILE_BASE_ADDR && dut->PPU_ADDR <= TILE_END_ADDR)
				dut->PPU_DATA_in = TILE_MAP[dut->PPU_ADDR - TILE_BASE_ADDR];
		}


    	dut->eval();     			// Run the simulation for a cycle
    	tfp->dump(time); 			// Write the VCD file for this cycle

    	if (dut->clk != last_clk && dut->clk == 1) {	// on posedge of clock
    		/* Writes to ppm file */
    		if ((int)dut->PX_valid == 1)
    			f << (int) dut->PX_OUT << " ";
    	}
    }

	tfp->close(); // Stop dumping the VCD file
	delete tfp;

	dut->final(); // Stop the simulation
	delete dut;

	f.close();
	return exit_code;
}

