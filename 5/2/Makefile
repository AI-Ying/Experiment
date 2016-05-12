obj-m :=print_process.o

LINUX_KERNEL :=/lib/modules/$(shell uname -r)/build

all:
	make -C $(LINUX_KERNEL) M=$(shell pwd) modules

clean:
	make -C $(LINUX_KERNEL) M=$(shell pwd) clean
