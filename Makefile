INCL = -I.
CFLAGS = -O3 -Wall $(INCL)
UNAME = $(shell uname)
CC = gcc
CPP = g++
LD = g++
LDFLAGS = 
TARGET = cptest
TARGET_OBJS = main.o color_print.o
MOVEMENT_TARGET = movement
MOVEMENT_OBJS = movement.o color_print.o

all: color

color: $(TARGET) $(MOVEMENT_TARGET)

$(TARGET): $(TARGET_OBJS)

	$(LD) $(TARGET_OBJS) -o $(TARGET) $(LDFLAGS)

$(MOVEMENT_TARGET): $(MOVEMENT_OBJS)

	$(LD) $(MOVEMENT_OBJS) -o $(MOVEMENT_TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.o: %.cc
	$(CPP) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *~
	rm -f $(TARGET)
	rm -f $(MOVEMENT_TARGET)
