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
	char tile_map[1024];
	char tile_1[16], tile_2[16];
	char tile[2] = {tile_1, tile_2};

	int i, time, offset, exit_code, tile_req;
	char LCDC, line_buf_cnt = 0;
	char line_buf[160] = {0};
	VPPU3 *dut;
	
	offset = exit_code = 0;

	for (i = 0; i < 1024; i++)
		tile_map[i] = (i % 2) ? 0 : 1;			// 0 => tile_1, 1 => tile_2

	for (i = 0; i < 16; i = i + 2) {			// tile_1 == 10, tile_2 == 11
		tile_1[i] = 1;
		tile_1[i + 1] = 0;

		tile_2[i] = 1;
		tile_2[i + 1] = 0;
	}

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

	for (time = 0 ; time < 10000 ; time += 10) {
    	dut->clk = ((time % 20) >= 10) ? 1 : 0; 	// Simulate a 50 MHz clock

    	dut->rst = (time == 30) ? 1 : 0;			// pulses rst 
		dut->PPU_DATA_in = 0;

		//for map 2 and 8000 addressing method, due to LCDC = FF
		if (dut->PPU_MODE == DRAW) {
			if (dut->PPU_ADDR >= BG_MAP_1_BASE_ADDR && dut->PPU_ADDR <= BG_MAP_1_END_ADDR) {	// if its requesting bg map
				dut->PPU_DATA_in = tile_map[dut->PPU_ADDR - BG_MAP_1_BASE_ADDR];				// gives it back a tile no
			}
			else if (dut->PPU_ADDR >= TILE_BASE) {
				dut->PPU_DATA_in = tile[(int)(dut->PPU_ADDR - TILE_BASE / 16)][(dur->PPU_ADDR - TILE_BASE) % 16];
			}

		}

		if (dut->PX_valid) 
			line_buf[line_buf_cnt = (line_buf_cnt + 1) % 160] = dut->PX_OUT;
		if (line_buf_cnt == 159) {
			for (i = 0; i < 160; i++)
				std::cout << (int) line_buf[i];
			std::cout << std::endl;
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

