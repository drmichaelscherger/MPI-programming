.PHONY: all examples labs clean help

all: examples labs

examples:
	@$(MAKE) --no-print-directory -C examples all

labs:
	@$(MAKE) --no-print-directory -C labs all

clean:
	@$(MAKE) --no-print-directory -C examples clean
	@$(MAKE) --no-print-directory -C labs clean

help:
	@echo "Targets:"
	@echo "  all       Build examples and labs"
	@echo "  examples  Build all examples"
	@echo "  labs      Build all labs"
	@echo "  clean     Remove generated build products"
