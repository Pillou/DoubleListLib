CFLAGS=-g -Wall

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all: test

test: DoubleLinkedList.o

clean:
	rm -f test
	rm -f *.o

