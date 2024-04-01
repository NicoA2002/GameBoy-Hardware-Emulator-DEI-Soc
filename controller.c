/* Headers */

#include <libusb-1.0/libusb.h>

#define VENDOR_ID 0x0079
#define PROD_ID	  0x0011

/* End of Headers */

#include <stdio.h>
#include <stdlib.h> 
 
struct libusb_device_handle *opencontroller(uint8_t *endpoint_address)
{
	struct libusb_device_handle *controller = NULL;
	struct libusb_device_descriptor desc;
	struct libusb_config_descriptor *config;

	libusb_device **devs;
	
	ssize_t num_devs, d;
	uint8_t i, k, r;

	if (libusb_init(NULL) < 0) {
		fprintf(stderr, "Error: libusb_init failed\n");
		exit(1);
	}

	if ((num_devs = libusb_get_device_list(NULL, &devs)) < 0) {
		fprintf(stderr, "Error: libusb_get_device_list failed\n");
		exit(1);
	}

	for (d = 0 ; d < num_devs ; d++) {
		libusb_device *dev = devs[d];

		if (libusb_get_device_descriptor(dev, &desc) < 0) {
		  fprintf(stderr, "Error: libusb_get_device_descriptor failed\n");
		  exit(1);
		}
		if (desc.idVendor == VENDOR_ID && desc.idProduct == PROD_ID) {
			libusb_get_config_descriptor(dev, 0, &config);
			for (int j = 0; j < config->bNumInterfaces; j++) {
                for (int k = 0; k < config->interface[j].num_altsetting; k++) {
                	const struct libusb_interface_descriptor *inter = config->interface[j].altsetting + k;
                    if (inter->bInterfaceClass == LIBUSB_CLASS_HID) {
						if ((k = libusb_open(dev, &controller)) != 0) {
							fprintf(stderr, "Error: libusb_open failed: %d\n", k);
							exit(1);
						}

						if (libusb_kernel_driver_active(controller,j))
							libusb_detach_kernel_driver(controller, j);							
						libusb_set_auto_detach_kernel_driver(controller, j);
						if ((r = libusb_claim_interface(controller, j)) != 0) {
							fprintf(stderr, "Error: libusb_claim_interface failed: %d\n", r);
							exit(1);
						}

						endpoint_address = inter->endpoint[0].bEndpointAddress;
						libusb_free_config_descriptor(config);
						return controller;

                    }
                }
            }

		}
	}

  return NULL;
}

int main()
{
	struct libusb_device_handle *controller;
	int transferred;
	unsigned char packet;
	uint8_t endpoint_address;
	int r;

	if ((controller = opencontroller(&endpoint_address)) == NULL) {
	    fprintf(stderr, "Did not find a controller\n");
	    exit(1);
	  }

	while (1) {
		if ((r = libusb_interrupt_transfer(controller, endpoint_address,
				    (unsigned char *) &packet, sizeof(packet),
				     &transferred, 5000)) != 0) {
			printf("Error code: %d\n", r);
			exit(1);
		}

		printf("%d 0x%x\n", transferred, packet);
	}

	return 0;
}