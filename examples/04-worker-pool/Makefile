CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: worker_pool

worker_pool: worker_pool.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) worker_pool
