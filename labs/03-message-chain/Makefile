CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
.PHONY: all clean
all: message_chain
message_chain: message_chain.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	$(RM) message_chain
