CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
.PHONY: all clean
all: distributed_search
distributed_search: distributed_search.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	$(RM) distributed_search
