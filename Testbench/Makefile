SVFILE = ../GameBoy1/GameBoy_RTL_Qsys_submit/PPU3.sv ../PPU3.sv

.PHONY default
default: PPU3.vcd

# Quickly check the System Verilog files for errors

lint :
	for file in $(SVFILE); do \
	verilator --lint-only -Wall $$file; done


#Create and Run Verilator Simulations

PPU3.vcd : obj_dir/VPPU3
	obj_dir/VPPU3


obj_dir/VPPU3 : PPU3.sv PPU_tb.cpp
	verilator -trace -Wall -cc PPU3.sv -exe PPU3.cpp -top-module PPU3
	cd obj_dir && make -j -f VPPU3.mk

.PHONY clean
clean: 
	rm -rf obj_dir *.vcd
