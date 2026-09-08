.PHONY: all clean

SUBDIRS := 01-process-report 02-communicator-inventory 03-message-chain 04-distributed-search

all:
	@for dir in $(SUBDIRS); do $(MAKE) --no-print-directory -C $$dir all || exit; done

clean:
	@for dir in $(SUBDIRS); do $(MAKE) --no-print-directory -C $$dir clean || exit; done
