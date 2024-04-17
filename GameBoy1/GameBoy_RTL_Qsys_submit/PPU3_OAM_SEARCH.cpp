#include <iostream>
// #include "VPPU3.h"
// #include <verilated.h>

typedef struct {
	unsigned char y,
	unsigned char x,
	unsigned char tile_no,
	unsigned char flags,

} OAM_Ent;

#define ADD_ENT(x) \
	OAM_BUFF[offset] = ent.y; \
	OAM_BUFF[offset+1] = ent.x; \
	OAM_BUFF[offset+2] = ent.tile_no; \
	OAM_BUFF[offset+3] = ent.flags;

int main(int argc, const char ** argv, const char ** env) {
	unsigned char OAM_BUFF[160];
	OAM_Ent ent;
	int offset, exit_code;

	exit_code = 0;
	offset = 4;

	for (i = 0; i < 160; i++)
		OAM_BUFF[i] = 0; 

	ent.y = 0;
	ent.x = 30;
	ent.tile_no = 5;
	flags = 5;

	for (i = 0; i < 5; i++)
		ADD_ENT(offset * i);

	// Verilated::commandArgs(argc, argv);

	// VPPU3 *dut = new VPPU3;  // Instantiate the collatz module

	return exit_code;
}

