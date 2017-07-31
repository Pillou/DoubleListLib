CFLAGS=-g -Wall -Isrc -Itest

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all: test

test: $(OBJECTS)
