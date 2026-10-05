obj-m += virtual_dsp.o
KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
all:
	@if [ ! -d "$(KDIR)" ]; then echo "ERROR: Missing kernel build tree: $(KDIR)"; exit 2; fi
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	@if [ -d "$(KDIR)" ]; then $(MAKE) -C $(KDIR) M=$(PWD) clean; fi
