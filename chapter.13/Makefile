obj-m = kprobe_example.o
KDIR = /lib/modules/4.15.0-142-generic/build 
PWD  = $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

