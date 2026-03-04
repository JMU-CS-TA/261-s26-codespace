TARGETS=debug freq

CC=gcc
CFLAGS=-g -O0 -std=c99 -Wall -pedantic
LDFLAGS=

all: $(TARGETS)

debug: debug.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

freq: freq.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

