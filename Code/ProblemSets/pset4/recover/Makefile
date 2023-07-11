CC = clang
CFLAGS = -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm

all: recover

recover: recover.c
	$(CC) $(CFLAGS) -o recover recover.c

clean:
	rm -f recover