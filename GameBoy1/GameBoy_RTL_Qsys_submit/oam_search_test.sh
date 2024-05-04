cp PPU3.sv debug_tests/
cp PPU3_OAM_SEARCH.cpp debug_tests/
cd debug_tests/
verilator --cc PPU3.sv
verilator -trace -cc PPU3.sv -exe PPU3_OAM_SEARCH.cpp -top-module PPU3
cd obj_dir && make -j -f VPPU3.mk
./VPPU3
gtkwave ppu3.vcd
