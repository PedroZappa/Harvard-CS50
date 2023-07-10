# Compiler & Compiler Flags
CC = clang
CFLAGS = -g -Wall -Wextra -std=c99

# Targets
# Default target (dependent on volume)
all: volume

# Compiles the volume.c source file into an executable named volume.
volume: volume.c
	$(CC) $(CFLAGS) -o volume volume.c

# Removes the compiled executable, volume, using the rm command.
clean: 
	rm -f volume 