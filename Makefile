INCL = -I.
CFLAGS = -O3 -Wall $(INCL)
UNAME = $(shell uname)
CC = gcc
CPP = g++
LD = g++
LDFLAGS = 
TARGET = cptest
TARGET_OBJS = main.o color_print.o

all: color

color: $(TARGET)

$(TARGET): $(TARGET_OBJS)

	$(LD) $(TARGET_OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.o: %.cc
	$(CPP) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *~
	rm -f $(TARGET)
