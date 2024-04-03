/* Headers */

#include <libusb-1.0/libusb.h>

#define VENDOR_ID 		0x0079
#define PROD_ID	  		0x0011
#define ENDPT_ADDR_IN	0x81

#define EMPTY_INTERR(packet) ((packet[3] == 127) & (packet[4] == 127) & (packet[5] == 15) & (packet[6] == 0) & (packet[7] == 0))

/* End of Headers */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
 
struct libusb_device_handle *opencontroller()
{
	libusb_device_handle *controller;
    libusb_context *context = NULL;
    int error;

    // Initialize libusb
    if ((error = libusb_init(&context)) < 0) {
        fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(error));
        return NULL;
    }

    // Open device with the given vendor ID and product ID
    if ((controller = libusb_open_device_with_vid_pid(context, VENDOR_ID, PROD_ID)) == NULL) {
        fprintf(stderr, "Device not found.\n");
        libusb_exit(context);
        return NULL;
    }

    // There's only one interface so we know we can use 0
    if (libusb_kernel_driver_active(controller, 0))
		libusb_detach_kernel_driver(controller, 0);							
	libusb_set_auto_detach_kernel_driver(controller, 0);
    if ((error = libusb_claim_interface(controller, 0)) != LIBUSB_SUCCESS) {
        fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(error));
        libusb_close(controller);
        libusb_exit(context);
        return NULL;
    }

    return controller;
}

int main()
{
	struct libusb_device_handle *controller;
	int transferred;
	unsigned char packet[8];
	int r;

	if ((controller = opencontroller()) == NULL) {
	    fprintf(stderr, "Did not find a controller\n");
	    exit(1);
	  }

	while (1) {
		libusb_interrupt_transfer(controller, 0x81,
					    (unsigned char *) packet, 8,
					     &transferred, 500);
		if (transferred > 0 && !EMPTY_INTERR(packet)) {			
			/* --- Start/Select --- */
			if (packet[6]  & 0x10)
				printf("Select!\n");
			if (packet[6]  & 0x20)
				printf("Start!\n");

			printf("%d ", transferred);
			for (int i = 0; i < sizeof(packet); i++)
				printf("%d ", packet[i]);
			printf("\n");

			/* Effectively debounces by introducing a delay after input was recieved */
			usleep(200 * 1000);
		}
	}

	return 0;
}