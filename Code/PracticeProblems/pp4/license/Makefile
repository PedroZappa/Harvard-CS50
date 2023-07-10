# Compiler & Compiler Flags
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c99

# Targets
all: license

license: license.c
	$(CC) $(CFLAGS) -o license license.c

clean:
	rm -f license
