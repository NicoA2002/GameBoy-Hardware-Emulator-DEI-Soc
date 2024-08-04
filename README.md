# GameBoy-Hardware-Emulator
A Hardware Emulator for the 1989 GameBoy for the Terasic DE1-SoC Development Board, using an NES controller as a user input, and VGA to a monitor for display

## Usage 
### To Compile Hardware

- Open a terminal. Change the directory to the RTL folder. 

- Add the following to joypad_hw.tcl if it isn't already there:

```
    set_module_assignment embeddedsw.dts.vendor "csee4840"
    set_module_assignment embeddedsw.dts.name "joypad"
    set_module_assignment embeddedsw.dts.group "game_boy"
```

- Run the following commands:

```
    chmod +x compile-scripts.sh
    ./compile-scripts.sh
    make dtb
```

which runs:
```
	make qsys-clean && make qsys && make rbf;
	embedded_command_shell.sh;
	make dtb;
```

- At this point, you may get several "ERROR (phandle_references): Reference to non-existent node or label Main_PLL". Add the following to the soc_system.dts file under the "clocks" node (e.g. line 43):

```
    Main_PLL: Main_PLL {
    	compatible = "fixed-clock";
    	#clock-cells = <0>;
    	clock_frequency = <0>;	/* 0 Hz */
    	clock-output-names = "Main_PLL-clk";
    };
```

- In reality, the Main_PLL is not used by Linux, so the clock frequency is not important. This just prevents "make dtb" from complaining. 
```
    make dtb
```
- Copy the .rbf file (in output_files folder) and .dtb file onto the boot partition of the DE1-SoC board by. Reboot the board. 

```
    mount /dev/mmcblk0p1 /mnt
    cp output_files/soc_system.rbf /mnt/
    cp soc_system.dtb /mnt/
    sync
```

If this does not work: 

1. First verify the date of the .dtb and .rbf files on the SD Card. 
2. Check "/proc/device-tree/sopc@0/bridge@0xc0000000/" for the devices listed under the soc_system.dts file

You may copy the files directly to the MicroSD card of the DE1 SoC from another device with an SD Card Reader.

------------------------------------------------------

### From DE1 SoC, Software for loading/running ROM + interfacing with NES controller

- The controller Product and Vendor ID are configured in controller.h; verify they are correct with by running 'lsusb'

- Open a console. Change the directory to where software source files are. Run the following commands in order:

```
    make
    insmod game_boy.ko
```

- Before you run the program, press Key0 and Key1 on the DE1-SoC board simultaneously to reset the soc_system. 
```
    ./start [-d] ROM.gb
```
[-d] option is to enable double speed

- After running the program, press Key2 and Key3 on the DE1-SoC board simultaneously to reset the Game Boy. 

- To exit the game, press Ctrl-C on the console

- To clean up:

```
make clean
rmmod game_boy
clear
```