#include <iostream>
// #include "VPPU3.h"
// #include <verilated.h>

typedef struct {
	char y,
	char x,
	char tile_no,
	char flags,

} OAM_Ent;

#define ADD_ENT(x) \
	OAM_BUFF[offset] = ent.y; \
	OAM_BUFF[offset+1] = ent.x; \
	OAM_BUFF[offset+2] = ent.tile_no; \
	OAM_BUFF[offset+3] = ent.flags;

int main(int argc, const char ** argv, const char ** env) {
	char OAM_BUFF[160];
	int i;
	OAM_Ent ent;
	int offset, exit_code;

	exit_code = 0;
	offset = 4;

	for (i = 0; i < 160; i++)
		OAM_BUFF[i] = 0; 

	ent.y = 0;
	ent.x = 30;
	ent.tile_no = 5;
	ent.flags = 5;

	for (i = 0; i < 5; i++)
		ADD_ENT(offset * i);

	Verilated::commandArgs(argc, argv);

	VPPU3 *dut = new VPPU3;  // Instantiate the ppu module

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	dut->trace(tfp, 99);
	tfp->open("ppu3.vcd");

	// output logic PPU_RD,
    // output logic [15:0] PPU_ADDR,
    // input logic [7:0] PPU_DATA_in,

	for (time = 0 ; time < 10000 ; time += 10) {
    	dut->clk = ((time % 20) >= 10) ? 1 : 0; // Simulate a 50 MHz clock

    	dut->PPU_DATA_in = OAM_BUFF[dut->PPU_ADDR - 0xFE00];
    	dut->eval();     // Run the simulation for a cycle
    	tfp->dump(time); // Write the VCD file for this cycle
    }

	tfp->close(); // Stop dumping the VCD file
	delete tfp;

	dut->final(); // Stop the simulation
	delete dut;

	return exit_code;
}

