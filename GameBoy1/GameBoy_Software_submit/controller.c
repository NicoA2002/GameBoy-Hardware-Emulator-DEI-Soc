#include "controller.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
 
struct libusb_device_handle *opencontroller(void)
{
	libusb_device_handle *controller;
    int error;

    // Initialize libusb
	if ((error = libusb_init(NULL)) < 0) {
        fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(error));
        return NULL;
    }

    // Open device with the given vendor ID and product ID
	if ((controller = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PROD_ID)) == NULL) {
        fprintf(stderr, "Device not found.\n");
        return NULL;
    }

    // There's only one interface so we know we can use 0
    if (libusb_kernel_driver_active(controller, 0))
		libusb_detach_kernel_driver(controller, 0);							
	libusb_set_auto_detach_kernel_driver(controller, 0);
    if ((error = libusb_claim_interface(controller, 0)) != LIBUSB_SUCCESS) {
        fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(error));
        libusb_close(controller);
        return NULL;
    }

    return controller;
}

void read_inputs(void)
{
	struct libusb_device_handle *controller;
	int transferred;
	unsigned char packet[8];
	unsigned char pressed, last_pressed;			// 	DOWN_UP_LEFT_RIGHT_START_SELECT_B_A

	if ((controller = opencontroller()) == NULL) {
	    fprintf(stderr, "Did not find a controller\n");
	    exit(1);
	  }

	pressed = 0;
	printf("Ready to read input\n");
	while (1) {
		        libusb_interrupt_transfer(controller, ENDPT_ADDR_IN,
            (unsigned char *)& packet, sizeof(packet),
            &transferred, 500);

           
        if (transferred > 0 && !EMPTY_INTERR(packet)) {			
			/* --- Start/Select --- */
			PROCESS(packet[6], SELECT, pressed);
			PROCESS(packet[6], START, pressed);

			/* --- A/B --- */
			PROCESS(packet[5], A, pressed);
			PROCESS(packet[5], B, pressed);

			/* --- D_Pad --- */
			PROCESS(packet[4], DOWN, pressed);
			PROCESS(packet[3], RIGHT, pressed);
			EMPTY_PROCESS(packet[4], UP, pressed);
			EMPTY_PROCESS(packet[3], LEFT, pressed);

            // bytes are swapped, and not recognizing a header file change
            pressed = ((pressed & 0x0F) << 4) | ((pressed & 0xF0) >> 4);
			/* Effectively debounces by introducing a delay after input was recieved */
			usleep(100 * 1000);
		} else if (transferred > 0){    
            pressed = 0x00;        
		}
        if (last_pressed != pressed) printf("Pressed: 0x%X\n", pressed); //send to reg here
        last_pressed = pressed;
	}

	libusb_close(controller);
}