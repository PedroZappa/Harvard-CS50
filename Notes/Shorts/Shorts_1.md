# Shorts 1: _`C`_

#### Return to [`CS50x`](/README.md)

___

## Table o'Contents

- [C Language Data Types and Variables](#c-language-data-types-and-variables)
- [CS50 Additional Types](#cs50-additional-types)
- [Creating a Variable](#creating-a-variable)
- [Using a Variable](#using-a-variable)
- [Arithmetic Operators](#arithmetic-operators)
- [Boolean Expressions](#boolean-expressions)
- [Logical Operators](#logical-operators)
- [Relational Operators](#relational-operators)
- [Conditionals](#conditionals)
- [Ternary Op Conditional](#ternary-op-conditional)
- [Loops](#loops)
- [Using the Linux Command Line](#using-the-linux-command-line)
- [Magic Numbers](#magic-numbers)

___

## [C Language Data Types and Variables](#c-language-data-types-and-variables)

### `int`

- The `int` data_type is used for variables that will store integers;

- Integers always take up 4 bytes of memory (32bits) This means the range of values they can store is necessarily limited to 32 bits worth of information;

- Integer Range `[-2^31 - 0 - 2^31-1]`

### `unsigned int`

- `unsigned` is a qualifier that can be applied to certain types (including `int`), which effectively doubles the positive range of variables of that type, at the cost of disallowing any negative values;

- You'll occasionally have use for `unsigned` variables in CS50;

- Unsigned Integer Range `[0 - 2^31 - 2^32-1]`

### `char`

- The `char` data_type is used for variables that will store single characters;

- Characters always take up 1 byte of memory (8bits). This means the range of values they can store is necessarily limited to 8 bits worth of information;

- Thanks to ASCII, we've developed a mapping of characters like A, B, C, etc... to numeric values in the positive side of this range;

- Character Range `[-128 - 0 - 127]`

### `float`

- The `float` data_type is used for variables that will store floating point values, also known as Real Numbers;

- Floating points values take up 4 bytes of memory (32bits);

- It's a little complicated to describer the range of a `float` but suffice it to say with 32 bits of precision, some of which might be used for an integer part, we are limited in how precise we can be;

### `double`

- The `double` data_type is used for variables that will store floating-point values, also known as Real Numbers;

- The difference is that `doubles` are double precision. They always take up 8 bytes of memory (64 bits);

- With an additional 32 bits of precision relative to a `float`, `doubles` allow us to specify much more precise real numbers;

### `void`

- Is a `type`, but not a data_type;

- Functions can have a `void` return type, which just means they don't return a value;

- The parameter list of a function can also be `void`. It simply means the function takes no parameters;

- For now, think of `void` more as a placeholder for "nothing". It's more complex than that, but this should suffice for the better part of the course;

___

## [CS50 Additional Types](#cs50-additional-types)

### bool

- The `bool` data_type is used for variables that will store a boolean value. More precisely, they are capable only of storing one of two values: `true` or `false`;

- Be sure to #include <cs50.h> atop your program if you wish to use the bool type.

### string

- The `string` data_type is used for variables that will store a series of characters, which programmers typically call a `string`;

- `Strings` include things such as words, sentences, paragraphs, and the like.

- Be sure to #include <cs50.h> atop your program if you wish to use the `string` type;

## [Creating a Variable](#creating-a-variable)

- To bring a variable into existence, you need simply specify the data type of the variable and give it a name;

```c
int number;
char letter;
```

- if you wish to create multiple variables of the same type, you specify the type name once, and then list as many variables of that type you want;

```c
int height, width;
float sqrt2, sqrt3, pi;
```

- In general, it's a good practice to only declare variables when you need them;

## [Using a Variable](#using-a-variable)

- After a variable has been declared, it's no longer necessary to specify that variable's type. (In fact, doing so has some unintended consequences!):

```c
int number;   // declaration
number = 17;  // assignment
char letter;  // declaration
letter = 'H'; // assignment
```

- if you are simultaneously declaring and setting he value of a variable (sometimes called initializing), you can consolidate this to one step:

```c
int number = 17;  // Initialization
char letter= 'H'; // Initialization
```

___

## [Arithmetic Operators](#arithmetic-operators)

- In order to manipulate and work with variable and value in C, we have a number of `operators` at our disposal;

- In C we can add ( `+` ), subtract ( `-` ), multiply ( `*` ) and divide ( `/` ) numbers, as expected;

```c
int x = y + 1;
x = x * 5;
```

- We also have the modulus operator, ( `%` ) which gives us the remainder when the number on the left of the operator is divided by the number on the right;

```c
int m 13 % 4;  // m is now 1
```

- C also provides a shorthand way to apply an arithmetic operator to a single variable;

```c
int x = x * 5;
x *= 5
```

- This trick works with all five basic arithmetic operators. C provides a further shorthand for incrementing or decrementing a variable by 1:

```c
x++;
x--;
```

## [Boolean Expressions](#boolean-expressions)

- Boolean expressions are used in C for comparing two values;

- All Boolean expressions in C evaluate to one of two values - `true` or `false`;

- We can use the result of evaluating a Boolean expression in other programming constructs such as deciding which branch in a conditional to take, or determining whether a loop should continue to run;

- Sometimes when working with Boolean expressions we will use variables of type bool, but we don’t have to;

- In C, every nonzero value is equivalent to true, and zero is false;

- Two main types of Boolean expressions: logical operators and relational operators.

### [Logical Operators](#logical-operators)

- Logical AND ( `&&` ) is true if and only if both operands are
true, otherwise false:

| X | Y |   X && Y   |
|---|---|------------|
| True | True |      True     |
| True | False |      False     |
| False | True |      False     |
| False | False |      False     |

- Logical OR (||) is true if and only if at least one operand is true, otherwise false:

| X | Y |   X && Y   |
|---|---|------------|
| True | True |      True     |
| True | False |      True     |
| False | True |      True     |
| False | False |      False     |

- Logical NOT (!) inverts the value of its operand:

|   X   |   !X   |
|-------|--------|
| True  |      False     |
| False  |      True     |

### [Relational Operators](#relational-operators)

- These behave as you would expect them to, and appear syntactically similar to how you may recall them from elementary arithmetic;

  - Less than (x < y)
  - Less than or equal to (x <= y)
  - Greater than (x > y)
  - Greater than or equal to (x >= y)

- C also can test two variables for equality and inequality.

  - Equality (x == y)
  - Inequality (x != y)

- Be careful! It’s a common mistake to use the
assignment operator ( `=` ) when you intend to use the
equality operator ( `==` ).

___

## [Conditionals](#conditionals)

- Conditional expressions allow your program to make decisions and take different forks in the road, depending on the values of variables or user input;

- C provides a few different ways to implement conditional expressions (also known as branches) in your programs, some of which likely look familiar from Scratch;

### if

```c
if ( boolean-expression ) {
  ...
}
```

- If the `boolean-expression` evaluates to true, all lines of code between the curly braces will execute in order from top-to-bottom;

- If the `boolean-expression` evaluates to false, those lines of code will not execute;

### if-else

```c
if ( boolean-expression ) {
  ...
} else {
  ...
}
```

- If the `boolean-expression` evaluates to true, all lines of code between the first set of curly braces will execute in order from top-to-bottom;

- If the `boolean-expression` evaluates to false, all lines of code between the second set of curly braces will execute in order from top-to-bottom;

```c
if ( boolean-expr1 ) {
  ...  // first branch
} else if ( boolean-expr2 ) {
  ...  // second branch
} else if ( boolean-expr3 ) {
  ...  // third branch
} else {
  ...  // fourth branch
}
```

- In C, it is possible to create an `if-else if-else` chain;

- Each branch is mutually exclusive;

```c
if ( boolean-expr1 ) {
  ...  // first branch
} if ( boolean-expr2 ) {
  ...  // second branch
} if ( boolean-expr3 ) {
  ...  // third branch
} else {
  ...  // fourth branch
}
```

- It is also possible to create a chain of non-mutually exclusive branches;

- In this example, only the third and fourth branches are mutually exclusive. The `else` binds to the nearest `if` only;

### switch

```c
int x = GetInt();
switch(x) {
  case 1:
    printf("One!\n");
    break;
  case 2:
    printf("Two!\n");
    break;
  case 3:
    printf("Three!\n");
    break;
  default:
    printf("Default!\n");
}
```

- C's `switch()` statement is a conditional statement that permits enumeration of discrete cases, instead of relying on Boolean expressions;

- It's important to `break;` between each case, or you will "fall through" each case (unless that is the desired behavior);

```c
int x = GetInt();
switch(x) {
  case 5:
    printf("Five, \n");
  case 4:
    printf("Four, \n");
  case 3:
    printf("Three, \n");
  case 2:
    printf("Two, \n");
  case 1:
    printf("One, \n");
  default:
    printf("Blast-off!\n");
}
```

- No `breaks;` Execution will fall through each case without breaking;

## [Ternary Op Conditional](#ternary-op-conditional)

- These two snippets of code act identically;

```c
int x;
if (expr)
{
  x = 5;
}
else
{
  x = 6
}
```

```c
int x = (expr) ? 5 : 6;
```

- The ternary operator ( `?:` ) is mostly a cute trick, but is useful for writing trivially short conditional branches. Be familiar with it, but know that you won't need to write it if you don't want to;

## Conditionals Recap

### if ( and if-else, and if-else if-...-else)

- Use Boolean expressions to make decisions;

### switch

- Use discrete cases to make decisions;

### Ternary (`?:`)

- Use to replace a very simple `if-else` to make your code look fancy;

___

## [Loops](#loops)

- Loops allow your programs to execute lines of code repeatedly, saving you from needing to copy and paste or otherwise repeat lines of code;

- C provides a few different ways to implement loops in your programs, some of which likely look familiar from Scratch;

### while 

```c
while ( true )
{
  ... // Infinite Loop
}
```

- This is what we call an infinite loop. The lines of code between the curly braces will execute repeatedly from top to bottom, until and unless we break out of it (as with a `break;` statement) or otherwise kill our program;

```c
while ( boolean-expr )
{
  ...
}
```

- If the `boolean-expr` evaluates to true, all lines of code
between the curly braces will execute repeatedly, in order
from top-to-bottom, until `boolean-expr` evaluates to
false;

- Somewhat confusingly, the behavior of the Scratch block is
reversed, but it is the closest analog;

### do-while

```c
do {
  ...
} while ( boolean-expr );
```

- This loop will execute all lines of code between the curly braces once, and then, if the `boolean-expr` evaluates to `true`, will go back and repeat that process until `boolean-expr` evaluates to `false`;

### for

```c
for ( int i = 0; i < 10; i++ )
{
  ...
}
```

- Syntactically unattractive, but `for` loops are used to repeat the
body of a loop a specified number of times, in this example 10.

- The process undertaken in a `for` loop is:

  - The counter variable(s) (here, i) is set

  - The Boolean expression is checked.
    - If it evaluates to `true`, the body of the loop executes.
    - If it evaluates to `false`, the body of the loop does not
  execute.
  - The counter variable is incremented, and then the
Boolean expression is checked again, etc;

```c
for ( `start`; `expr`; `increment` )
{
  ...
}
```

- Syntactically unattractive, but `for` loops are used to repeat the
body of a loop a specified number of times, in this example 10.

- The process undertaken in a `for` loop is:

  - The statement(s) in `start` are executed
  - The `expr` is checked.
    - If it evaluates to `true`, the body of the loop executes.
    - If it evaluates to `false`, the body of the loop does not
  execute.
  • The statement(s) in `increment` are executed, and then the `expr` is checked again, etc;

## Loop Recap

### while

- Use when you want a loop to repeat an unknown number of times, and possibly not at all;

### do-while

- Use when you want a loop to repeat an unknown number of times, but at least once;

### for 

- Use when you want a loop to repeat a discrete number of times, though you may not know the number at the moment the program is compiled.

___

## [Using the Linux Command Line](#using-the-linux-command-line)

- The CS50 IDE is a cloud-based machine running Ubuntu, one of the many flavors of the Linux OS;

- Many modern Linux distributions have graphical user interfaces (GUI) to allow easy mouse-based navigation;

- Still, as a programmer you’ll likely be using your `terminal window` frequently, and you can do many of the same tasks with keyboard commands;

- Let’s have a look at some of the most important of these keyboard-based commands for working within the IDE or any UNIX-based system;

### ls

- Short for “list”, this command will give you a readout of
all the files and folders in your current directory;

### cd `<directory>`

- Short for “change directory”, this command will change your 
current working directory to <directory>, which you specify, in your workspace or on your operating system.

- The shorthand name for the current directory is `.` ;

- The shorthand name for the parent directory of the
current directory is `..` ;

- If ever curious about the name of the current directory, though the terminal prompt will often tell you, you can type `pwd` (present working directory);

### mkdir `<directory>`

- Short for “make directory”, this command will create a new subdirectory called `<directory>` located in the current directory;

### cp `<source>` `<destination>`

- Short for “copy”, this command will allow you to create a duplicate of the file you specify as `<source>`, which it will save in `<destination>`;

- If you wish to copy entire directories, you’ll need to
modify the command slightly:

```sh
cp –r <sourceDirectory> <destinationDirectory>
```

- The `-r` stands for recursive, and tells cp to dive down into the directory and copy everything inside of it (including any subdirectories it  might contain);

### rm `<file>`

- Short for “remove”, this command will delete `<file>`after it asks you to confirm (y/n) you want to delete it.

- You can skip the confirmation by typing:

```sh
rm –f <file>
```

- But use at your own peril! There’s no undo.

- To delete entire directories you need to use the `-r` flag, just as was the case with `cp`.

```sh
rm –r <directory>
```

- You can also combine the `–r` and `–f` flags into `–rf`. Again, careful! There’s no undo!

### mv `<source>` `<destination>`

- Short for “move”, this command will allow you to effectively rename a file, moving it from `<source>` to `<destination>`;

## Conclusion

- To be sure, there are many more basic command line utilities at your disposal, and we’ll discuss many of them in the future in CS50.

- If you wish to explore other interesting ones before we see them in the class, read up on:
  - chmod
  - rmdir
  - sudo
  - ln
  - man
  - clear
  - touch
  - diff
  - telnet

## [Magic Numbers](#magic-numbers)

- Some of the programs we’ve written in CS50 have some weird numbers thrown in there.
  - The height of Mario’s pyramid is capped at 23, for example.

- What do those numbers mean? If someone looks at your program, is the meaning of 23 immediately obvious?

- Directly writing constants into our code is sometimes referred to as using magic numbers;

```c
card deal_cards( deck name )
{
    for ( int i = 0; i < 52; i++) >
    {
        // deal the card
    }
}
```

- We’ve got a magic number in here. Do you see what it is?
    - More importantly, do you see a potential problem here? Particularly if this function is just one of many in a suite of programs that manipulate decks of cards.

```c
card deal_cards( deck name )
{
    int deck_size = 52;
    for ( int i = 0; i < deck_size; i++) >
    {
        // deal the card
    }
}
```

- This fixes one problem, but introduces another.
    - Even if globally declared, what if some other function in
our suite inadvertently manipulates `deck_size`. Could
spell trouble;

## Preprocessor Directives [ macros ]

- C provides a preprocessor directive (also called a
macro) for creating symbolic constants.

```c
#define NAME REPLACEMENT
```

Note: Don't use `;` at the end of preprocessor directives;

- At the time your program is compiled, #define goes through your code and replaces `NAME` with `REPLACEMENT`.
    - If `#include` is similar to copy/paste, then #define is analogous to find/replace.

- C provides a preprocessor directive (also called a
macro) for creating symbolic constants.

```c
#define PI 3.14159265
```

- At the time your program is compiled, `#define` goes through your code and replaces `PI` with 3.14159265.
    - If `#include` is similar to copy/paste, then `#define` is analogous to find/replace.

- C provides a preprocessor directive (also called a
macro) for creating symbolic constants.

```c
#define COURSE "CS50"
```

- At the time your program is compiled, `#define` goes through your code and replaces COURSE with `“CS50”`.
    - If `#include` is similar to copy/paste, then `#define` is analogous to find/replace.

```c
#define DECKSIZE 52

card deal_cards(deck name)
{
for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```

```c
#define DECKSIZE 32

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```

```c
#define DECKSIZE 50000

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```

___

#### Return to [`CS50x`](/README.md)

___