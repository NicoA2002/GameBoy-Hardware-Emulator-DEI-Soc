cp PPU3.sv debug_tests/
cp tb_ppu.cpp debug_tests/
cd debug_tests/
verilator --cc PPU3.sv
verilator -trace -cc PPU3.sv -exe tb_ppu.cpp -top-module PPU3
cd obj_dir && make -j -f VPPU3.mk
./VPPU3
