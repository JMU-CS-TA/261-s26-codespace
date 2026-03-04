TARGETS=mcpi

CC=gcc
CFLAGS=-g -O0 -std=c99 -Wall -pedantic
LDFLAGS=

all: $(TARGETS)

mcpi: mcpi.c
	$(CC) $(CFLAGS) -O2 $(LDFLAGS) -o $@ $< -lpthread

clean:
	rm -rf $(TARGETS) *.dSYM

.PHONY: all clean

