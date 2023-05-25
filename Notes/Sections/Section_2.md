CS50: Section_2
=======================

#### Return to [`CS50x`](/README.md)

=======================

[https://cs50.harvard.edu/x/2023/sections/2/]

## Compiling

- Compiling command example:

```sh
gcc -o main main.c
```

- If compiling with non-standard header files
(e.g. using `<cs50.h>`):

```sh
gcc -o main main.c -lcs50
```

## Array

- Independent Variables example:

```c
int hours_1 = 7;
int hours_2 = 9;
int hours_3 = 8;
int hours_4 = 7;
int hours_5 = 8;
```

- Variables grouped into an array:

```c
int hours[5];  // Array of integers with 5 elements (length/size)
hours[0] = 7; // Assigning values to each index one at a time
hours[1] = 9;
hours[2] = 8;
hours[3] = 7;
hours[4] = 8;
```

or

```c
// Assigning an object of values to fill the array
int hours[] = {7, 9, 8, 7, 8}; 
```

- Accessing and printing values from an array recursively:

```c
int hours[] = {7, 9, 8, 7, 8};

for (int i = 0; i < 5; i++)
{
  printf("%i\n", hours[i]);
}
```

### Powers of 2

- Create a program that prompts the user for a size, `n`;
- Dynamically create an array of that size, where each element is 2 times the previous one;
- Start the array at 1;
- Print the array, integer by integer;

```c
#include <cs50.h>
#include <stdio.h>

int main(void) // Powers of 2
{
    // Get array length
    int length;
    do
    {
        length = get_int("Input Array Length Value: ");
    } 
    while ( length < 1); // Requires length to be a positive integer;
    
    // Declare array
    int twice[length];
    // Set first value
    twice[0] = 1;


    if (length == 1)
    {
        printf("\narray[%i] = { %i }", length, twice[0]);
    }
    else 
    {
        printf("\narray[%i] = { %i, ", length, twice[0]);

        // Loop through the array starting at index 1;
        for (int i = 1; i < length; i++)
        {
            // Make current element twice the previous
            twice[i] = 2 * (twice[i - 1]);

            // Print current element
            printf("%i", twice[i]);
            if ( i < length-1) 
            {
                printf(", ");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("}\n");
    }
}
```

=================================================================

## String

- Declaring a string:

```c
string name = "Emma";
```

- A `string` is an `array` of chars;

```c
char name[] = {'E', 'm', 'm', 'a', '\0'};
```

Strings always end with a `NUL` character: `\0`;

The `NUL` character marks the end of a string;

`ASCII` character values:

![ascii table](/IMG/Sect2//sect_00_ascii.png)

- Handling a `string` as an `array` and printing the `ASCII` values of its `char`s:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string name = "John";
  int length = strlen(name);
  //  Print ASCII Value of each character
  for (int i = 0; i < length; i++) 
  {
    printf("%i ", name[i]);
  }
  puts("\n");

  // Print character 
  for (int i = 0; i < length; i++) 
  {
    printf("%c ", name[i]);
  }
}
```

===============================================================

## Alphabetical Exercise

- Check if a lowercase string's characters are in alphabetical order. If yes, print "Yes". If no, print "No".

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string word = get_string("Input a string of characters: ");
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++)
    {
        // check if NOT alphabetical (i.e., "ba")
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
```

============================================================

## Command Line Arguments

- Function with no command line arguments:

```c
int main(void)
{
    ...
}
```

- Function with command line arguments:

```c
int main(int argc, string argv[])
{
    ...
}

- a program the loops through the contents of argv[] and prints its contents:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Loop through every argument
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i] is %s\n", i, argv[i]);
    }
}
```

- Execution exemple:

```sh
gcc -o cla cla.c -lcs50
./cla yo Zedro
```

Output:

```sh
argv[0] is cla
argv[1] is yo
argv[2] is Zedro
```

## Initials Exercise

- Given a name as a set of comman-line arguments, print the initials of that name to the terminal:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Print the first characetr of the first element of argv[]
    printf("Initials: %c.%c.\n", argv[1][0], argv[2][0]);
}
```

=======================

#### Return to [`CS50x`](/README.md)

=======================