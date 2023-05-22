# [Shorts 4: Memory](https://cs50.harvard.edu/x/2023/weeks/4/)

Table o'Contents

- [Hexadecimal](#hexadecimal)
- [Pointers](#pointers)
- [Defining Data Types](#defining-data-types)
- [Dynamic Memory Allocation](#dynamic-memory-allocation)
- [Call Stacks](#call-stacks)
- [File Pointers](#file-pointers)

___

## [Hexadecimal](#hexadecimal)

- Most Western cultures use the `decimal system`, aka base-10, to represent numeric data.

``` 
0 1 2 3 4 5 6 7 8 9
```

- As we know, computers use the `binary system`, aka base-2, to represent numeric (and indeed all data).

```
0 1
```

-  As computer scientists, it’s useful to be able to express data the same way the computer does.

- • The problem, of course, is that trying to parse a huge chain of 0s and 1s can be quite difficult.

- The `hexadecimal system`, aka base-16, is a much more concise way to express the data on a computer’s system.

```
0 1 2 3 4 5 6 7 8 9 a b c d e f
```

- Hexadecimal makes this mapping easy because a group of `four binary digits` (bits) is able has 16 different combinations, and each of those combinations maps to a single hexadecimal digit.

- The hexadecimal system, aka base-16, is a much more concise way to express the data on a computer’s system.

```
0 1 2 3 4 5 6 7 8 9 A B C D E F
```

- Hexadecimal makes this mapping easy because a group of four
binary digits (bits) is able has 16 different combinations, and
each of those combinations maps to a single hexadecimal digit.

<center>

| Decimal | Binary | Hexadecimal |
| :-----: | :----: | :---------: |
| 0       | 0000   | 0x0         |
| 1       | 0001   | 0x1         |
| 2       | 0010   | 0x2         |
| 3       | 0100   | 0x3         |
| 4       | 1000   | 0x4         |
| 5       | 0101   | 0x5         |
| 6       | 0110   | 0x6         |
| 7       | 0111   | 0x7         |
| 8       | 1000   | 0x8         |
| 9       | 1001   | 0x9         |
| 10      | 1010   | 0xA         |
| 11      | 1011   | 0xB         |
| 12      | 1100   | 0xC         |
| 13      | 1101   | 0xD         |
| 14      | 1110   | 0xE         |
| 15      | 1111   | 0xF         |

</center>

- Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

- • Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

```sh
3 9 7 
```

- Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

```sh
0x 3 9 7
```

- Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

```sh
   256 16 1
0x 3   9  7
```

- Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

```sh
   12^2 16^1 16^0
0x 3    9    7
```

- Just like binary has place values (1, 2, 4, 8…) and decimal does too (1, 10, 100, 1000…), so does hexadecimal.

```sh
   12^2 16^1 16^0
0x A    D    C
```

- To convert a binary number to hexadecimal, group four binary digits (bits) together from right to left.

    - Pad the leftmost group with extra 0 bits at the front if necessary.

- Then use the chart a few slides back or your memory to
convert those bits to something a bit more concise.

```
01000110101000101011100100111101

0100 0110 1010 0010 1011 1001 0011 1101

4    6    A    2    B    9    3    D

0x46A2B93D
```

___

## [Pointers](#pointers)

Pointers provide an alternative way to pass data between functions.

- Recall that up to this point, we have passed all data by value, with
one exception.
- When we pass data by value, we only pass a copy of that data.

If we use pointers instead, we have the power to pass the actual variable itself.

- That means that a change that is made in one function can impact what happens in a different function.
- Previously, this wasn’t possible!

Before we dive into what pointers are and how to work with them, it’s worth going back to basics and have a look at our computer’s memory.

- Every file on your computer lives on your disk drive, be it a hard disk drive (HDD) or a solid-state drive (SSD).

- Disk drives are just storage space; we can’t directly work there. Manipulation and use of data can only take place in RAM, so we have to move data there.

- Memory is basically a huge array of 8-bit wide bytes.
   - 512 MB, 1GB, 2GB, 4GB…

Data Type | Size (in bytes)
--- | ---
int     | 4 
char    | 1 
float   | 4 
double   | 8 
long long   | 8
bool    | 1 
char*, int*, float*, double* (32bit)  | 4
char*, int*, float*, double* (64bit)  | 8


- Back to this idea of memory as a big array of byte-sized cells.

- Recall from our discussion of arrays that they not only are
useful for storage of information but also for so-called random
access.
   - We can access individual elements of the array by indicating which
index location we want.

Similarly, each location in memory has an address.

![char / int / string in memory visualization](/IMG/Shorts4/Shorts4_0.png)

There’s only one critical thing to remember as we start working
with pointers:

```c
POINTERS ARE JUST ADDRESSES!
```

As we start to work with pointers, just keep this image in mind:

![int *pointer visualization](/IMG/Shorts4/Shorts4_1.png)

A pointer, then, is a data item whose

- value is a memory address
- type describes the data located at that memory address

As such, pointers allow data structures and/or variables to be shared among functions.

Pointers make a computer environment more like the real world.

The simplest pointer available to us in C is the `NULL pointer`.

- As you might expect, this pointer points to nothing (a fact which can
actually come in handy!)

When you create a pointer and you don’t set its value immediately, you should always set the value of the pointer to `NULL`.

You can check whether a pointer is `NULL` using the equality operator (`==`).

Another easy way to create a pointer is to simply `extract` the address of an already existing variable. We can do this with the address extraction operator (`&`).

- If `x` is an int-type variable, then `&x` is a pointer-to-int whose
value is the address of `x`.

- If `arr` is an array of doubles, then `&arr[i]` is a pointer-to-double who value is the address of the `ith` element of `arr`.
   - An array’s name, then, is actually just a pointer to its first element – you’ve been working with pointers all along!

- The main purpose of a pointer is to allow us to modify or inspect the location to which it points.
   - We do this by `dereferencing` the pointer.

- If we have a pointer-to-char called `pc`, then `*pc` is the data that lives at the memory address stored inside the variable `pc`.

- Used in this context, `*` is known as the `dereference operator`.

- It “goes to the reference” and accesses the data at that
memory location, allowing you to manipulate it at will.

- This is just like visiting your neighbor. Having their address isn’t
enough. You need to `go to` the address and only then can you
interact with them.

Can you guess what might happen if we try to dereference a
pointer whose value is NULL?

```c
Segmentation fault
```

Surprisingly, this is actually good behavior! It defends against accidental dangerous manipulation of unknown pointers.

- That’s why we recommend you set your pointers to `NULL` immediately if you aren’t setting them to a known, desired value.

```c
int* p;
```

- The value of `p` is an address.
- We can dereference `p` with the `*` operator.
- If we do, what we’ll find at that location is an `int`.

One more annoying thing with those `*`s. They’re an important
part of both the type name and the variable name.

- Best illustrated with an example.

```c
int* px, py, pz // Creates 1 pointer *px and two variables py and pz;

int* pa, *pb, *pc; // Creates 3 pointers
```

![Pointer example 1/3](/IMG/Shorts4/Shorts4_2.png)

![Pointer example 2/3](/IMG/Shorts4/Shorts4_3.png)

![Pointer example 3/3](/IMG/Shorts4/Shorts4_4.png)

## [Defining Data Types](#defining-data-types)

The C keyword typedef provides a way to create a shorthand
or rewritten name for data types.

- The basic idea is to first define a type in the normal way, then
alias it to something else.

```c
typedef <old name> <new name>;
...
typedef unsigned char byte;
typedef char * string;
```

```c
struct car
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
};
typedef struct car car_t;
```

is the same as

```c
typedef struct car
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
}
car_t;
```
___

Consider de following code snippet:

```c
// variable declaration
struct car mycar;
// field accessing
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);
mycar.odometer = 50505;
```

It could be re-written as:

```c
// variable declaration
car_t mycar;
// field accessing
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);
mycar.odometer = 50505;
```

___

## [Dynamic Memory Allocation](#dynamic-memory-allocation)

- We’ve seen one way to work with pointers, namely pointing a pointer variable at another variable that already exists in our system.

   - This requires us to know exactly how much memory our system will need at the moment our program is compiled.

- What if we `don’t` know how much memory we’ll need at compile-time? How do we get access to new memory while our program is running?

- We can use pointers to get access to a block of `dynamically-allocated memory` at runtime.
- Dynamically allocated memory comes from a pool of memory
known as the `heap`.
- Prior to this point, all memory we’ve been working with has
been coming from a pool of memory known as the `stack`.

![Memory Graph](/IMG/Shorts4/Shorts4_5.png)

- We get this dynamically-allocated memory by making a call to
the C standard library function `malloc()`, passing as its
parameter the number of bytes requested.

- After obtaining memory for you (if it can), `malloc()` will
return a pointer to that memory.

- What if `malloc()` can’t give you memory? It’ll hand you back
`NULL`.

```c
// statically obtain an integer
int x;
// dynamically obtain an integer
int *px = malloc(sizeof(int));
```

```c
// get an integer from the user
int x = GetInt();
// array of floats on the stack
float stack_array[x];
// array of floats on the heap
float* heap_array = malloc(x * sizeof(float));
```

- Here’s the trouble: `Dynamically-allocated memory` is not
automatically returned to the system for later use when the
function in which it’s created finishes execution.

- Failing to return memory back to the system when you’re
finished with it results in a `memory leak` which can
compromise your system’s performance.

- When you finish working with dynamically-allocated memory,
you must `free()` it.

```c
char* word = malloc(50 * sizeof(char));
// do stuff with word
// now we’re done working with that block
free(word);
```

### Three Golden Rules

1. Every block of memory that you `malloc()` must subsequently be `free()`d.
2. Only memory that you `malloc()` should be `free()`d.
3. Do not `free()` a block of memory more than once.

### Memory Allocation Example

![malloc()](/IMG/Shorts4/Shorts4_6.png)

![&a](/IMG/Shorts4/Shorts4_7.png)

![a=b](/IMG/Shorts4/Shorts4_8.png)

![m=10](/IMG/Shorts4/Shorts4_9.png)

![*b = m+2](/IMG/Shorts4/Shorts4_10.png)

![free()](/IMG/Shorts4/Shorts4_11.png)

![free()](/IMG/Shorts4/Shorts4_12.png)

## [Call Stacks](#call-stacks)

- When you call a function, the system sets aside space in memory for that function to do its necessary work.

   - We frequently call such chunks of memory `stack frames` or `function frames`.

- More than one function’s stack frame may exist in memory at a given time. If `main()` calls `move()`, which then calls `direction()`, all three functions have open frames.

- These frames are arranged in a `stack`. The frame for the most recently called function is always on the top of the stack.

-  When a new function is called, a new frame is `pushed` onto the top of the stack and becomes the active frame.

-  When a function finishes its work, its frame is `popped` off of the stack, and the frame immediately below it becomes the new, active, function on the top of the stack. This function picks up immediately where it left off.

### Call Stack Example

![main()](/IMG/Shorts4/Shorts4_13.png)

![printf()](/IMG/Shorts4/Shorts4_14.png)

![fact(4)](/IMG/Shorts4/Shorts4_15.png)

![fact(3)](/IMG/Shorts4/Shorts4_16.png)

![fact(2)](/IMG/Shorts4/Shorts4_17.png)

![fact(1)](/IMG/Shorts4/Shorts4_18.png)

![fact(1) returns](/IMG/Shorts4/Shorts4_19.png)

![fact(2) returns](/IMG/Shorts4/Shorts4_20.png)

![fact(3) returns](/IMG/Shorts4/Shorts4_21.png)

![fact(4) returns](/IMG/Shorts4/Shorts4_22.png)

![fact(5) returns](/IMG/Shorts4/Shorts4_23.png)

## [File Pointers](#file-pointers)

- The ability to read data from and write data to files is the primary means of storing `persistent data`, data that does not disappear when your program stops running.
- The abstraction of files that C provides is implemented in a data structure known as a `FILE`.
   - Almost universally when working with files, we will be using pointers to them, `FILE*`.

The file manipulation functions all live in `<stdio.h>`.

- All of them accept `FILE*` as one of their parameters, except for the function `fopen()`, which is used to get a file pointer in the first
place.
- Some of the most common file `input/output (I/O)` functions that we’ll be working with are:

```
fopen() | flcose() | fgetc() | fputc() | fread() | fwrite()
```

___

### `fopen()`

- Opens a file and returns a file pointer to it.
- Always check the return value to make sure you don’t get back `NULL`.

```c
FILE* ptr = fopen(<filename>, <operation>);
```

```c
FILE* ptr1 = fopen(“file1.txt”, “r”); // Read Mode
FILE* ptr2 = fopen(“file2.txt”, “w”); // Write Mode
FILE* ptr3 = fopen(“file3.txt”, “a”); // Append Mode
```

___

### ``fclose()``

- Closes the file pointed to by the given file pointer.

```c
fclose(<file pointer>);
```

```c
fclose(ptr1);
```

___

### `fgetc()`

- Reads and returns the next character from the file pointed to.
- Note: The operation of the file pointer passed in as a parameter must be `“r”` for read, or you will suffer an error.

```c
char ch = fgetc(<file pointer>);
```

```c
char ch = fgetc(ptr1);
```

The ability to get single characters from files, if wrapped in a
loop, means we could read all the characters from a file and
print them to the screen, one-by-one, essentially.

```c
char ch;
while((ch = fgetc(ptr)) != EOF)
   printf(“%c”, ch);
```

- We might put this in a file called `cat.c`, after the Linux
command `“cat”` which essentially does just this.

___

### ``fputc()``

- Writes or appends the specified character to the pointed-to file.
- Note: The operation of the file pointer passed in as a parameter must be `“w”` for write or `“a”` for append, or you will suffer an error.

```c
fputc(<character>, <file pointer>);
```

```c
fputc(‘A’, ptr2);
fputc(‘!’, ptr3);
```

Now we can read characters from files and write characters to them. Let’s extend our previous example to copy one file to another, instead of printing to the screen.

```c
char ch;
while((ch = fgetc(ptr)) != EOF)
   printf(“%c”, ch);
```

Now we can read characters from files and write characters to them. Let’s extend our previous example to copy one file to another, instead of printing to the screen.

```c
char ch;
while((ch = fgetc(ptr)) != EOF)
fputc(ch, ptr2);
```

- We might put this in a file called `cp.c`, after the Linux command `“cp”` which essentially does just this.

___

### `fread()`

Reads `<qty>` units of size `<size>` from the file pointed to and stores them in memory in a buffer (usually an array) pointed to by
`<buffer>`.

- Note: The operation of the file pointer passed in as a parameter must be “r” for read, or you will suffer an error.

```c
fread(<buffer>, <size>, <qty>, <file pointer>);
```

```c
int arr[10];
fread(arr, sizeof(int), 10, ptr);
```

```c
double* arr2 = malloc(sizeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr);
```

```c
char c;
fread(&c, sizeof(char), 1, ptr);
```

___

### `fwrite()`

- Writes `<qty>` units of size `<size>` to the file pointed to by reading them from a buffer (usually an array) pointed to by `<buffer>`.
- Note: The operation of the file pointer passed in as a parameter must be `“w”` for write or `“a”` for append, or you will suffer an error.

```c
fwrite(<buffer>, <size>, <qty>, <file pointer>);
```

```c
int arr[10];
fwrite(arr, sizeof(int), 10, ptr);
```

```c
double* arr2 = malloc(sizeof(double) * 80);
fwrite(arr2, sizeof(double), 80, ptr);
```

```c
char c;
fwrite(&c, sizeof(char), 1, ptr);
```

 Lots of other useful functions abound in stdio.h for you to work
with. Here are some of the ones you may find useful!

<center>

Function | Description |
---: | :--- |
fgets() | Reads a full string from a file. |
fputs() | Writes a full string to a file. |
fprintf() | Writes a formatted string to a file. |
fscanf() | Reads a formatted string from a file. |
fseek() | Changes the position of a file pointer. |
ftell() | Returns the current position (byte) of a file pointer. |
feof() | Returns true if the end of file has been reached. |
ferror() | Returns true if an error occurred. |