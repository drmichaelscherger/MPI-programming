CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: send_recv

send_recv: send_recv.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) send_recv
