CC = clang
CFLAGS = -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm

all: reverse

reverse: reverse.c
	$(CC) $(CFLAGS) -o reverse reverse.c

clean:
	rm -f reverse