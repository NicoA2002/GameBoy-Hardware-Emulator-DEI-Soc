# TCL File Generated by Component Editor 18.1
# Wed Jun 26 17:18:14 EDT 2019
# DO NOT MODIFY


# 
# GameBoy "GameBoy" v1.0
#  2019.06.26.17:18:14
# The GameBoy
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module GameBoy
# 
set_module_property DESCRIPTION "The GameBoy"
set_module_property NAME GameBoy
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP GameBoy
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME GameBoy
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL GameBoy_Top
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file GameBoy_Top.sv SYSTEM_VERILOG PATH GameBoy_Top.sv TOP_LEVEL_FILE


# 
# parameters
# 


# 
# display items
# 


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock clk clk Input 1


# 
# connection point GameBoy_ROM
# 
add_interface GameBoy_ROM conduit end
set_interface_property GameBoy_ROM associatedClock ""
set_interface_property GameBoy_ROM associatedReset ""
set_interface_property GameBoy_ROM ENABLED true
set_interface_property GameBoy_ROM EXPORT_OF ""
set_interface_property GameBoy_ROM PORT_NAME_MAP ""
set_interface_property GameBoy_ROM CMSIS_SVD_VARIABLES ""
set_interface_property GameBoy_ROM SVD_ADDRESS_GROUP ""

add_interface_port GameBoy_ROM CART_ADDR cart_addr Output 16
add_interface_port GameBoy_ROM CART_RD cart_rd Output 1
add_interface_port GameBoy_ROM CART_WR cart_wr Output 1
add_interface_port GameBoy_ROM CART_DATA_in cart_data_in Input 8
add_interface_port GameBoy_ROM CART_DATA_out cart_data_out Output 8


# 
# connection point GameBoy_Pixel
# 
add_interface GameBoy_Pixel conduit end
set_interface_property GameBoy_Pixel associatedClock clock
set_interface_property GameBoy_Pixel associatedReset ""
set_interface_property GameBoy_Pixel ENABLED true
set_interface_property GameBoy_Pixel EXPORT_OF ""
set_interface_property GameBoy_Pixel PORT_NAME_MAP ""
set_interface_property GameBoy_Pixel CMSIS_SVD_VARIABLES ""
set_interface_property GameBoy_Pixel SVD_ADDRESS_GROUP ""

add_interface_port GameBoy_Pixel LD ld Output 2
add_interface_port GameBoy_Pixel PX_VALID px_valid Output 1


# 
# connection point GameBoy_Joypad
# 
add_interface GameBoy_Joypad conduit end
set_interface_property GameBoy_Joypad associatedClock ""
set_interface_property GameBoy_Joypad associatedReset ""
set_interface_property GameBoy_Joypad ENABLED true
set_interface_property GameBoy_Joypad EXPORT_OF ""
set_interface_property GameBoy_Joypad PORT_NAME_MAP ""
set_interface_property GameBoy_Joypad CMSIS_SVD_VARIABLES ""
set_interface_property GameBoy_Joypad SVD_ADDRESS_GROUP ""

add_interface_port GameBoy_Joypad P10 p10 Input 1
add_interface_port GameBoy_Joypad P11 p11 Input 1
add_interface_port GameBoy_Joypad P12 p12 Input 1
add_interface_port GameBoy_Joypad P13 p13 Input 1
add_interface_port GameBoy_Joypad P14 p14 Output 1
add_interface_port GameBoy_Joypad P15 p15 Output 1


# 
# connection point reset
# 
add_interface reset reset end
set_interface_property reset associatedClock clock
set_interface_property reset synchronousEdges DEASSERT
set_interface_property reset ENABLED true
set_interface_property reset EXPORT_OF ""
set_interface_property reset PORT_NAME_MAP ""
set_interface_property reset CMSIS_SVD_VARIABLES ""
set_interface_property reset SVD_ADDRESS_GROUP ""

add_interface_port reset rst reset Input 1


# 
# connection point GameBoy_Audio
# 
add_interface GameBoy_Audio conduit end
set_interface_property GameBoy_Audio associatedClock ""
set_interface_property GameBoy_Audio associatedReset ""
set_interface_property GameBoy_Audio ENABLED true
set_interface_property GameBoy_Audio EXPORT_OF ""
set_interface_property GameBoy_Audio PORT_NAME_MAP ""
set_interface_property GameBoy_Audio CMSIS_SVD_VARIABLES ""
set_interface_property GameBoy_Audio SVD_ADDRESS_GROUP ""

add_interface_port GameBoy_Audio LOUT lout Output 16
add_interface_port GameBoy_Audio ROUT rout Output 16

