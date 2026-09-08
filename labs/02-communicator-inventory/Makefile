CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
.PHONY: all clean
all: communicator_inventory
communicator_inventory: communicator_inventory.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	$(RM) communicator_inventory
