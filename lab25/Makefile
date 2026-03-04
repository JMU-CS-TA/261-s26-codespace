TARGETS=files

CC=gcc
CFLAGS=-g -O0 -std=c99 -Wall -pedantic
LDFLAGS=

all: $(TARGETS)

files: files.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -rf $(TARGETS) *.dSYM

.PHONY: all clean

