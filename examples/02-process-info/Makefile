CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: process_info

process_info: process_info.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) process_info
