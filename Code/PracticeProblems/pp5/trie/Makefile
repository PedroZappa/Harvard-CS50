C = clang
CFLAGS = -ggdb3 -gdwarf-4 -O0 -std=c11 -Wall -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm

all: trie

trie: trie.c
	$(CC) $(CFLAGS) -o trie trie.c

clean:
	rm -f trie