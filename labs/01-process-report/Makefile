CC := mpicc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
.PHONY: all clean
all: process_report
process_report: process_report.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	$(RM) process_report
