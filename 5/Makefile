obj-m :=hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	echo insmod ./mp.ko to turn it on

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
