CFLAGS = -Wall
CC = gcc
OBJECTS = controller.o

controller: $(OBJECTS)
	$(CC) $(CFLAGS) -o lab2 $(OBJECTS) -lusb-1.0 -pthread

controller.o: controller.c controller.h

.PHONY: clean
clean:
	rm -rf *.o controller