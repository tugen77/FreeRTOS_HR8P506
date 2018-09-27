CPU = HR8P506

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c HR8P506_StdPeriph_Driver/src CMSIS

CFLAGS  = -g -O2 -Wall -D$(CPU)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -march=armv6s-m
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -includehr8p506_conf.h -ICMSIS -IHR8P506_StdPeriph_Driver/inc


SRCS  = hr8p506_iap_table.c \
	   lib_adc.c lib_euart.c lib_gpio.c lib_iic.c lib_led.c lib_printf.c \
	   lib_rtc.c lib_scs.c lib_scu.c lib_spi.c lib_timer.c lib_uart.c \
	   lib_wdt.c 
SRCS += system_HR8P506.c

OBJS = $(SRCS:.c=.o)

.PHONY: libhr8p506.a

all: libhr8p506.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libhr8p506.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libhr8p506.a

