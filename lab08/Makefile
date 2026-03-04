TARGETS=buggy_code

CC=gcc
CFLAGS=-g -O0 -std=c99 -Wall -pedantic
LDFLAGS=

all: $(TARGETS)

buggy_code: buggy_code.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

