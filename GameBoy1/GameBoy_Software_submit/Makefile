ifneq (${KERNELRELEASE},)

# KERNELRELEASE defined: we are being compiled as part of the Kernel
        obj-m := game_boy.o

else

# We are being compiled as a module: use the Kernel build system

	KERNEL_SOURCE := /usr/src/linux-headers-$(shell uname -r)
        PWD := $(shell pwd)

CFLAGS = -Wall
CC = gcc
OBJECTS = main.o controller.o

default: module main

user: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS) -lusb-1.0 

controller_test: controller.o
	$(CC) $(CFLAGS) -o controller_test controller.o -lusb-1.0

controller.o: controller.c controller.h

module:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
	${RM} main
	rm -rf *.o main 

TARFILES = Makefile README controller.c controller.h game_boy.h game_boy.c main.c
TARFILE = project.tar.gz
.PHONY : tar
tar : $(TARFILE)

$(TARFILE) : $(TARFILES)
	tar zcfC $(TARFILE) .. $(TARFILES:%=Project/%)

endif 