.PHONY: all examples labs solutions clean help

all: examples labs solutions

examples:
	@$(MAKE) --no-print-directory -C examples all

labs:
	@$(MAKE) --no-print-directory -C labs all

solutions:
	@$(MAKE) --no-print-directory -C solutions all

clean:
	@$(MAKE) --no-print-directory -C examples clean
	@$(MAKE) --no-print-directory -C labs clean
	@$(MAKE) --no-print-directory -C solutions clean

help:
	@echo "Targets:"
	@echo "  all       Build examples and labs"
	@echo "  examples  Build all examples"
	@echo "  labs      Build all labs"
	@echo "  solutions Build all instructor solutions"
	@echo "  clean     Remove generated build products"
