ifneq (${KERNELRELEASE},)

# KERNELRELEASE defined: we are being compiled as part of the Kernel
        obj-m := game_boy.o

else

# We are being compiled as a module: use the Kernel build system

	KERNEL_SOURCE := /usr/src/linux-headers-$(shell uname -r)
        PWD := $(shell pwd)

CFLAGS = -Wall
CC = gcc
OBJECTS = start.o controller.o

default: module start

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o start $(OBJECTS) -lusb-1.0 

module:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
	${RM} start
	rm -rf *.o start

TARFILES = Makefile README controller.c controller.h game_boy.h game_boy.c start.c
TARFILE = final-sw.tar.gz
.PHONY : tar
tar : $(TARFILE)

$(TARFILE) : $(TARFILES)
	tar zcfC $(TARFILE) .. $(TARFILES:%=Project/%)

endif 