CC = arm-none-linux-gnueabi-gcc
obj-m	:= test_dd.o
KDIR	:= /root/work/achroimx6q/kernel
PWD	:= $(shell pwd)

all : test_dd test_app

test_dd : test_dd.c
	$(MAKE)	-C $(KDIR) SUBDIRS=$(PWD)	modules

test_app : test_app.c
	$(CC) -o test_app test_app.c

clean:
	rm -rf *.ko *.mod.* *.order *.symvers *.o
	rm test_app
