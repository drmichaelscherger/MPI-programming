CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: ring

ring: ring.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) ring
