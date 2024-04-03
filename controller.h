#include <libusb-1.0/libusb.h>

#define VENDOR_ID 		0x0079
#define PROD_ID	  		0x0011
#define ENDPT_ADDR_IN	0x81

#define EMPTY_INTERR(packet) 	  \
			((packet[3] == 127) & \
 		    (packet[4] == 127) &  \
		    (packet[5] == 15)  &  \
		    (packet[6] == 0)   &  \
		 	(packet[7] == 0))

#define PROCESS(PACKET_BYTE, BIT, PRESSED_BYTE)	\
			if (PACKET_BYTE & BIT##_DET)	\
				PRESSED_BYTE |= BIT;  \
			else				\
				PRESSED_BYTE &= ~BIT

#define EMPTY_PROCESS(PACKET_BYTE, BIT, PRESSED_BYTE)	\
			if (!(PACKET_BYTE & BIT##_DET))	\
				PRESSED_BYTE |= BIT;  \
			else				\
				PRESSED_BYTE &= ~BIT

enum detect_bits { SELECT_DET=0x10, 
				   START_DET=0x20, 
				   A_DET=0x20, 
				   B_DET=0x40, 
				   DOWN_DET=0x80, 
				   RIGHT_DET=0x80, 
				   UP_DET=0xFF, 
				   LEFT_DET=0xFF };

enum press_bits {A=0x1, B=0x2, START=0x4, SELECT=0x8, LEFT=0x10, RIGHT=0x20, UP=0x40, DOWN=0x80};