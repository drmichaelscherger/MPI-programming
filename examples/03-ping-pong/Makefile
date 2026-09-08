CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: ping_pong

ping_pong: ping_pong.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) ping_pong
