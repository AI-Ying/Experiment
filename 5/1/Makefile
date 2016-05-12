obj-m :=hello.o

LINUX_KERNEL :=/lib/modules/$(shell uname -r)/build

all:
	make -C $(LINUX_KERNEL) M=$(shell pwd) modules
	echo insmod ./mp.ko to turn it on

clean:
	make -C $(LINUX_KERNEL) M=$(shell pwd) clean
