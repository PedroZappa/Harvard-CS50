# Compiler & Compiler Flags
CC = clang
CFLAGS = -g -Wall -Wextra -std=c99

# Targets
all: bottomup
bottomup: bottomup.c
	$(CC) $(CFLAGS) -o bottomup bottomup.c

clean:
	rm -f bottomup