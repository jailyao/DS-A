SOURCE  := $(wildcard *.c) 
OBJS    := $(patsubst %.c, %.o, $(SOURCE))
TARGET  := test

# CC := arm-linux-gnueabi-gcc
CC := gcc

LDFLAGS := -L./lib
INCLUDE := -I.
CFLAGS  := -g -Wall $(INCLUDE) $(ADDED_CFLAGS)

.PHONY : all objs clean rb

all : $(TARGET)
	# -Wl, -Map, $(OBJS).map

objs : $(OBJS)

rb: clean all

clean :
	rm -rf *.o
	rm -rf $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) 