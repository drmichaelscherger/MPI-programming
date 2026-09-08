.PHONY: all clean

SUBDIRS := 01-hello 02-process-info 03-send-recv 03-ping-pong 04-ring 04-worker-pool

all:
	@for dir in $(SUBDIRS); do $(MAKE) --no-print-directory -C $$dir all || exit; done

clean:
	@for dir in $(SUBDIRS); do $(MAKE) --no-print-directory -C $$dir clean || exit; done
