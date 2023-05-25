CS50 Section_4: Memory
=======================

#### Return to [`CS50x`](/README.md)

=======================


[https://cs50.harvard.edu/x/2023/sections/4/]

## Contents

- [Pointers](#pointers)
- [Pointer Prediction Exercise](#pointer-prediction-exercise)

What are `pointers`, and how can we become familiar with their `syntax`?

- [File I/O](#file-io)
- [File Reading Exercise](#file-reading-exercise)

How can we `read` and `write` data from a file?

- [Dynamic Memory](#dynamic-memory)
- [Common Memory Errors](#common-memory-errors)
- [Debugging Memory Exercise](#debugging-memory-exercise)

What is `dynamic memory`, and how can we use it?

___
___
___



## [Pointers](#pointers)

Before we talk about pointers let's define variables.

```c
int calls = 4; // data_type name = value;
```

- `calls` is simply some `name` for `some place in memory` that has the `value` 4;

- `calls` is located at the memory `address` 0x1A (Hexadecimal #);

- to make use of this `address` we call a `pointer`;

```c
int *p = 0x1A; // data_type name = address;
```

- A `pointer` is a `variable` but it stores not a regular `value` like and integer or character, but a memory `address` that points to a `value` in memory;

Note: the `pointer` itself has an address of its own memory location;

### Ampersand ( & ) [ get address ]

```c
&calls; // get address of variable calls
&p; // get pointer's address
```

- `&calls` prints the `address` of `calls`;

### Dereferencing Operator ( * ) [ get value ]

```c
*p // go to the value at address stored in p
```

- `type *` is a pointer that stores the `address` of a type;
- `*x` takes a pointer `x` and goes to the `address` stored at that `pointer`;
- `&` takes `x` and gets its address;

## [Pointer Prediction Exercise](#pointer-prediction-exercise)

Visualize the following code, step by step.

How do the values of the variables evolve? It's ok to use made-up addresses.

What will the final values for each variable or pointer be?
Download, compile, and run `pointers.c` to find out;

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28;  // address a: random address
    int b = 50;  // address b: random address
    int *c = &a; // address c: address of a

    *c = 14;  // address: 0x1A
    c = &b;   // address: 0x1B
    *c = 25;  // address: 0x1A

    // Print Results
    printf("a has the value %i, located at %p\n", a, &a);
    printf("b has the value %i, located at %p\n", b, &b);
    printf("c has the value %p, located at %p\n", c, &c);
}
```
Output:

    a has the value 14, located at 0x7ff7b76c65dc
    b has the value 25, located at 0x7ff7b76c65d8
    c has the value 0x7ff7b76c65d8, located at 0x7ff7b76c65d0

## [File I/O](#file-io)

- to read `hi.txt` from file system:

```c
// TYPE *name = fopen("filename", mode) 
FILE *input = fopen("hi.txt", "r"); // r = Read Mode
```

- to store the read data from a file into a `Buffer` we use `fread()` :

```c
// fread( buffer, block_size (bytes), num_blocks_to_read, file_pointer);
fread(buffer, 1, 3, input);
```

## [File Reading Exercise](#file-reading-exercise)

Create a program, `pdf.c`, that checks whether a file, passed in as a command-line argument, is a `PDF`.

All `PDF`s will begin with a `four byte sequence`, corresponding to these bytes: `37 80 68 70`

```c
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Check if user has input filename
    if (argc != 2)
    {
        printf("Usage: ./pdf filename\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL)
    {
        printf("Error: Unable to open file\n");
    }

    // Create buffers
    // uint8_t = unsigned integer 8-bit (1 byte)
    uint8_t buffer[4];
    // Signature buffer
    uint8_t signature[] = {37, 80, 68, 70};

    // Read file
    fread(buffer, 1, 4, file);

    // Loop into buffer
    for (int i = 0; i < 4; i++)
    {
        // Check if one byte of buffer[] != signature[]
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF.\n");
            return 0;
        }  
    }
    printf("Likely a PDF\n");
    
    // Close file
    fclose(file);
    return 0;
}
```

## [Dynamic Memory](#dynamic-memory)

- to allocate memory dynamically we use `malloc()` :

```c
// Get the value of running malloc() given the size of an integer
int *hours = malloc(sizeof(int));
// Get five times the size of an integer
int *hours = malloc(sizeof(int) * 5);
```

- to store a value in memory :

```c
*hours = 7;
*(hours + 1) = 9;
hours[2] = 8;
hours[3] = 7;
```

```
hours
[ 7, 9, 8, 7, ... ]
```

- `malloc` gives us some memory from the `Heap`.

-  the `Stack` is what is used when you use a function and its variables. That asks for memory from the `Stack`.

- When using `malloc`, you get memory from the `Heap`.

- If you want a much `larger data structure`, you might often do that on the `Heap` because it is more persistent, and larger.

- You don't want to fill up the `Stack` too much.

- The `Heap` is used for `large files` that you might work with.

- The `Heap` is useful when you want to have a data structure that many functions can operate on (a linked list or a hash table).

- a `Stack` is limited to the single function call, but the `Heap` can be shared across functions overall.

## [Common Memory Errors](#common-memory-errors)

- Failing to `free` every block of memory which we've `malloc`'d.

- Failing to `flocse` every file we've `fopen`'d.

- Using more memory than we've allocated.
 
## [Debugging Memory Exercise](#debugging-memory-exercise)

Debug a program, `create.c`, that creates the file given as input at the command-line. For example,

```sh
./create test.c
```

will create a file, `test.c`. But our code has memory errors~
Can you find and fix them? Try running the command check:

```sh
valgrind ./create test.c
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for improper usage, otherwise, get filename length
    if (argc != 2)
    {
        printf("Wrong usage: Try ./create [filename]\n");
        return 1;
    }
    int filename_length = strlen(argv[1]);

    // Create a new block of memory to store filename
    char *filename = malloc(sizeof(char) * (filename_length + 1));

    // Copy argv[1] into block of memory for filename
    sprintf(filename, "%s", argv[1]);

    // Open new file under the name stored at filename
    FILE *new_file = fopen(filename, "w");
    if (new_file == NULL)
    {
        printf("Could not create file/\n");
        return 1;
    }
    
    // Close file
    fclose(new_file);
    // Free memory 
    free(filename);
}
```

=======================

#### Return to [`CS50x`](/README.md)

=======================