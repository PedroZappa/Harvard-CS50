CS50 Week-2: Shorts
=======================

#### Return to [`CS50x`](/README.md)

=======================

## Functions

- So far, all the programs we’ve been writing in the
course have been written inside of `main()`.

- That hasn’t been a problem yet, but it could be if
our programs start to become unwieldy.

- C and nearly all languages developed since allow us
to write `functions`, sometimes also known as
`procedures`, `methods`, or `subroutines`.

- Let’s see what functions are all about.

## What is a function?

- A black box with a set of 0+ inputs and 1 output.

### Pseudo Code examples:
```
func( a, b, c ) // outputs: z
```

Add two numbers
```
add( 3, 7 ) // outputs: 10
```

Multiply two numbers
```
mult( 3, 7 ) // outputs: 21
```

## Why call it a black box?

- If we aren’t writing the functions ourselves, we don’t
need to know the underlying implementation.

- That’s part of the contract of using functions. The
behavior is typically predictable based on that name.
That’s why most functions have clear, obvious(ish)
names, and are well-documented.

## Why use functions?

- Organization

- Functions help break up a complicated problem into more
manageable subparts.

- Simplification

- Smaller components tend to be easier to design,
implement, and debug.

- Reusability

- Functions can be recycled; you only need to write them
once, but can use them as often as you need!

## Function Declarations

- The first step to creating a function is to declare it. This
gives the compiler a heads-up that a user-written
function appears in the code.

- Function declarations should always go atop your code,
before you begin writing main().

- There is a standard form that every function
declaration follows.

```
return-type name(argument-list);
```

- The return-type is what kind of variable the
function will output.

- The argument-list is the comma-separated set of

- The name is what you want to call your function.
inputs to your function, each of which has a type and a
name.

### A function to add two integers.

```
int add_two_ints(int a, int b);
```

- sum of two integers is going to be an integer as
well.

- Given what this function does, make sure to give it an
appropriate name.

- There are two inputs to this function, and we need to
give a name to each of them for purposes of the
function. There’s nothing important about these inputs
as far as we know, so giving them simple names is okay.

### Correct C syntax example:

- Function that multiplies two floating point numbers:

```c
float mult_two_reals( float x, float y );
```
If more precision is necessary, use `double` instead.

```c
double mult_two_reals( double x, double y );
```

- The product of two floating point numbers is also a
floating point number.

- Let’s be sure to give this a relevant name.

- Again, the names of these particular inputs don’t seem
to be important, so we can call them anything simple.

## Function Definitions

- The second step to creating a function is to define it.
This allows for predictable behavior when the function
is called with inputs.

- Let’s try to define mult_two_reals(), from a
moment ago.

- A function definition looks almost identical to a
function declaration, with a small change.

```c
float mult_two_reals(float x, float y); // Prototype

float mult_two_reals(float x, float y)
{
float product = x * y;
return product;
}
```

or

```c
float mult_two_reals(float x, float y);

float mult_two_reals(float x, float y)
{
return x * y;
}
```

### Define add_two_ints(), from a moment ago.

```c
int add_two_ints(int a, int b);

int add_two_ints(int a, int b)
{
    int sum;      // decalre variable
    sum = a + b;  // calculate the sum
    return sum;   // give result back
}
```

## Function Calls

- Now that you’ve created a function, time to use it!

- To call a function, simply pass it appropriate arguments
and assign its return value to something of the correct
type.

- To illustrate this, let’s have a look at adder-1.c

```c
/**
 * adder-1.c
 * Doug Lloyd
 * lloyd@cs50.harvard.edu
 *
 * Adds two numbers.
 *
 * Demonstrates use of CS50's library and functions
 */


// includes
#include <cs50.h>
#include <stdio.h>

// declare function prototype
int add_two_ints(int a, int b);

int main(void)
{
    // ask user for input
    int x = get_int("Give me an integer: ");
    int y = get_int("Give me another integer: ");

    // add the two numbers together via a function call
    int z = add_two_ints(x, y);

    // output the result
    printf("The sum of %i and %i is %i!\n", x, y, z);

}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
```

## Function Miscellany

- Recall from our discussion of data types that functions
can sometimes take no inputs. In that case, we declare
the function as having a `void` argument list.

- Recall also that functions sometimes do not have an
output. In that case, we declare the function as having
a void return type.

## Practice Problem

- Declare a write a function called `valid_triangle`
that takes three real numbers representing the lengths
of the three sides of a triangle as its arguments, and
outputs either `true` or `false`, depending on whether
those three lengths are capable of making a triangle.

Note the following rules about triangles:

- A triangle may only have sides with positive length.

- The sum of the lengths of any two sides of the triangle must
be greater than the length of the third side.

```c
#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    // Get user input
    printf("Input the length of three sides of a triangle:\n");
    int a = get_int("Side A: ");
    int b = get_int("Side B: ");
    int c = get_int("Side C: ");

    // Check if triangle is valid
    valid_triangle(a, b, c);

    return 0;
}

bool valid_triangle(int a, int b, int c)
{
    // Check for positive sides
    if ( a <= 0 || b <= 0 || c <= 0 )
    {
        printf("Invalid triangle\nSide's length must be positive\n");
        return false;
    }
    // Check that a + b is greater than the third side
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        printf("Invalid triangle\nThe sum of any two sides must be greater than the length of the third side\n");
        return false;
    };
    // IF we passed both tests, we're good!
    printf("Valid triangle\n");
    return true;
}

```

## Variable Score

Scope is a characteristic of a variable that defines
from which functions that variable may be
accessed.

- `Local variables` can only be accessed within the
functions in which they are created.
- `Global variables` can be accessed by any function in the
program.

- So far in the course, you’ve almost assuredly been
working only with local variables.

```c
int triple(int x); // declaration

int main(void)

{
    int result = triple(5);
}
    int triple(int x)
{
    return x * 3;
}
```

- Here, x is local to the function triple(). No other
function can refer to that variable, not even
main(). result is local to main().

Global variables exist too. If a variable is declared
outside of all functions, any function may refer to
it.

```c
int triple(int x); // declaration
#include <stdio.h>

float global = 0.5050;

int main(void)
{
    triple();
    printf(“%f\n”, global);
}

void triple(void)
{
    global *= 3;
}
```

- Why does this distinction matter? For the most
part, local variables in C are `passed by value` in
function calls.

- When a variable is passed by value, the `callee`
receives a copy of the passed variable, not the
variable itself.

- That means that the variable in the `caller` is
unchanged unless overwritten.

No effect on foo. (Function declarations omitted
for space.)

```c
int main(void)
{
    int foo = 4;
    triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```

Overwrites foo. (Function declarations omitted for
space.)

```c
int main(void)
{
    int foo = 4;
    foo = triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```

Things can get particularly insidious if the same
variable name appears in multiple functions, which
is perfectly okay as long as the variables exist in
different scopes.

```c
int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf(“x is %i, y is %i\n”, x, y);
}

int increment(int x)
{
    x++;
    return x;
}
```

outputs:

```sh
x is 1, y is 2
```

## Debugging

Guess Game

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 5;

    int guess = get_int("Guess the number: ");

    if (guess != number)
    {
      printf("Wrong guess!");
      return 0;
    }

    printf("You're correct!");
}
```

=============================================================

## Array

- Arrays are a fundamental `data structure`, and they
are extremely useful!

- We use arrays to hold values of the same type at
contiguous memory locations.

- One way to analogize the notion of array is to think
of your local post office, which usually has a large
bank of post office boxes.

## Arrays / Post Office Boxes Analogy

| Arrays | Post Office Boxes |
|--------|-------------------|
| An `array` is a block of contiguous space in memory… | A `mail bank` is a large space on the wall of the post office… |
| …which has been partitioned into small, identically-sized blocks of space called `elements`… | …which has been partitioned into small, identically-sized blocks of space called `post office boxes`… |
| …each of which can store a certain amount of `data`… | …each of which can hold a certain amount of `mail`… |
| …all of the same data type such as `int` or `char`… | …all of a similar type such as `letters` or `small packages`… |
| …and which can be accessed directly by an `index`. | …and which can be accessed directly by a `mailbox number` |


## `Array` Indexing 

- In C, the elements of an array are indexed starting
from 0.

  - This is one of the major reasons we count from zero!

- If an array consists of `n` elements:

  - the first element is located at `index 0`.

  - The last element is located at `index (n-1)`.

- C is very lenient. It will not prevent you from going
“out of bounds” of your array; be careful!

## `Array` Declarations

```c
type name[size];
```

- The `type` is what kind of variable each element of the
array will be.

- The `name` is what you want to call your array.

- The `size` is how many elements you would like your
array to contain.

Examples:

```c
int student_grades[40];
```

Declares a `array` of `integers` called student_grades of `size` 40.

```c
double menu_prices[8];
```

Declares a `array` of `doubles` ( large `floats` ) called menu_prices of `size` 8.

- If you think of a single element of an array of type data-type the same as you would any other variable of type data-type (which effectively, it is) then all the familiar operations make sense.

```c
bool truthtable[10]; // 10 element truthtable array
truthtable[2] = false; // third element

if(truthtable[7] == true)
{
    printf(“TRUE!\n”);
}
truthtable[10] = true;
```

## Declaring & Initializing `Arrays`

- When declaring and initializing an array simultaneously, there is a special syntax that may be used to fill up the array with its starting values.

```c
// instantiation syntax
bool truthtable[3] = { false, true, true };

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

If using this special initiation syntax to create an array you don't need to indicate the size of the array beforehand like so:

```c
// instantiation syntax
bool truthtable[] = { false, true, true };
```

## Multi-dimensional `Arrays` 

Arrays can consist of more than a single dimension.
You can have as many size specifiers as you wish.

```c
bool battleship[10][10];
```

- You can choose to think of this as either a 10x10 grid of cells.

- In memory though, it’s really just a 100-element one-dimensional array.

- Multi-dimensional arrays are great abstractions to help visualize game boards or other complex representations.

## Handling `Arrays`

- While we can treat individual elements of arrays as
variables, we cannot treat entire arrays themselves
as variables.

- We cannot, for instance, assign one array to
another using the assignment operator. That is not
legal C.

- Instead, we must use a loop to copy over the
elements one at a time.

The following code is a mistake:
```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

bar = foo; // can't assign foo to bar
```

Instead if we copy the contents of `foo` into `bar` we should use a `for` loop:

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

for (int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}
```

- Recall that most variables in C are `passed by value` in function calls.

- Arrays do not follow this rule. Rather, they are `passed by reference`. The callee receives the actual array, `not` a copy of it.

    - What does that mean when the callee manipulates elements of the array?

- For now, we’ll gloss over why arrays have this special property, but we’ll return to it soon enough!

Exercise:

- What gets printed out at the end of main()?

```c
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = { 0, 1, 2, 3 };
    set_int(a);
    set_array(b);
    printf(“%d %d\n”, a, b[0]);
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}
```

Output:

```sh
10 22\n
```

## Command Line Arguments

- So far, all of your programs have begun pretty much the same way.

```c
int main(void)
{
    ...
}
```

- Since we’ve been collecting user input through in-program prompts, we haven’t needed to modify this declaration of `main()`.

- If we want the user to provide data to our program before the program starts running, we need a new form.

- To collect so called `command-line arguments` from the user, declare main as:

```c
int main(int argc, string argv[])
{
    ...
}
```

- These two special arguments enable you to know what data the user provided at the command line and how much data they provided.

## `argc` ( argument count )

- This integer-type variable will store the number of
command-line arguments the user typed when the
program was executed.

| Command | Argc |
|---------|------|
./greedy | 1 |
./greedy 1024 cs50 | 3 |

## `argv` ( argument vector )

- This array of strings stores, one string per element, the actual text the user typed at the command-line when the program was executed.

- The first element of `argv` is always found at `argv[0]`. The last element of `argv` is always found at `argv[argc-1]`.

- Let’s assume the user executes the greedy program as follows:

```sh
./greedy 1024 cs50
```

| `argv` indices | `argv` contents |
|---------|------|
argv[0] | "./greedy" |
argv[1] | "1024" |
argv[2] | "cs50" |
argv[3] | ??? |

=======================

#### Return to [`CS50x`](/README.md)

=======================