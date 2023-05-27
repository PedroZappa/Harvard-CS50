# Shorts_6: `Python`

#### Return to [`CS50x`](/README.md)

___

## Table o'Contents

- [Python Syntax](#python-syntax)
- [Variables](#variables)
- [Conditionals](#conditionals)
- [Loops](#loops)
- [Lists](#lists)
- [Tuples](#tuples)
- [Dictionaries](#dictionaries)
- [Loops Redux](#loops-redux)
- [Printing and variable interpolation](#printing-and-variable-interpolation)
- [Functions](#functions)
- [Objects](#objects)
- [Style](#style)
- [Including Files](#including-files)

___

## [Python Syntax](#python-syntax)

`Python` is an example of a very commonly-used modern programming language. 
    - `C` was first released in 1972, `Python` in 1991.

`Python` is an excellent and versatile language choice for making complex C operations much simpler.

- String manipulation
- Networking

Fortunately, `Python` is heavily inspired by C (its primary interpreter, Cpython, is actually written in C) and so the syntax should be a shallow learning curve.

___

To start writing `Python`, open up a file with the `.py` file extension.

Unlike a `C` program, which typically has to be compiled before you can run it, a `Python` program can be `run without explicitly compiling` it first.

Important note: In `CS50`, we teach `Python 3`. (Not Python 2, which is also still fairly popular.)

Python Syntax • Variables • Python variables have two big differences from C.

- No type specifier.
- Declared by initialization only.

___

## [Variables](#variables)

`Python` variables have two big differences from `C`.

- No type specifier.
- Declared by initialization only.
- `Python` statements needn't end with semicolons!

### Examples

- `Integers`:

```c
// C
int x = 54;
```

```py
# Python
x = 54
```

- `Strings`:

```c
// C
string phrase = "This is CS50";
```

```py
# Python
phrase = "This is CS50"
# or
phrase = 'This is CS50'
```

___

## [Conditionals](#conditionals)

• All of the old favorites from `C` are still available for you to use, but they look a little bit different now.

### `If Statement`

```c
// C
if (y < 43 || z == 15) 
{ 
    // code goes here 
}
```

```py
# Python
if y < 43 or z == 15: 
    # code goes here
```

### `If/Else Statement`

```c
// C
if (y < 43 && z == 15) 
{ 
    // code block 1 
} 
else 
{ 
    // code block 2
}
```

```py
# Python
if y < 43 and z == 15: 
    # code block 1
else: 
    # code block 2
```

### `If/Else If Statement`

```c
// C
if (coursenum == 50) 
{ 
    // code block 1 
}
else if (coursenum != 51) 
{ 
    // code block 2 
}
```

```py
# Python
if coursenum == 50: 
    # code block 1 
elif not coursenum == 51: 
    # code block 2
```

### `Alphabetic Check`

```c
// C
char var = get_char(); 
bool alphabetic = isalpha(var) ? true : false;
```

```py
# Python
letters_only = True if input().isalpha() else False
```

___

## [Loops](#loops)

Two varieties: `while` and `for`.

### `while`

```c
// C
int counter = 0;
while (counter < 100) 
{ 
    printf("%i\n", counter); 
    counter++; 
}
```

```py
# Python
counter = 0 
while counter < 100: 
    print(counter) 
    counter += 1
```

### `for`

```c
// C
for (int x = 0; x < 100; x++) 
{ 
    printf("%i\n", x); 
}
```

```py
# Python
for x in range(100): 
    print(x)
```

Or

```c
// C
for (int x = 0; x < 100; x += 2) 
{ 
    printf("%i\n", x); 
}
```

```py
# Python
# Third arg sets the increment
for x in range(0, 100, 2): 
    print(x)
```

___

## [Lists](#lists)

Here's where things really start to get a lot better than C.

`Python arrays` (more appropriately known as `lists`) are `not` fixed in size; they can grow or shrink as needed, and you can always tack extra elements onto your array and splice things in and out easily.

___

`Declaring a list` is pretty straightforward.

```py
# Empty list
nums = []
```

```py
# Explicitly created list
nums = [1, 2, 3, 4]
```

```py
# Create list with 500 elements
nums = [x for x in range(500)]
```

```py
# Create an empty list
nums = list()
```

___

`Tacking` on to an existing `list` can be done a few ways:

```py
# Appending to an existing list
nums = [1, 2, 3, 4] 
nums.append(5)
```

```py
# Inserting on 4th position the number 5
nums = [1, 2, 3, 4] 
nums.insert(4, 5)
```

```py
#
nums = [1, 2, 3, 4] 
nums[len(nums):] = [5]
```

The 3 examples above do the same thing.
___

## [Tuples](#tuples)

`Python` also has a data type that is not quite like anything comparable to `C`, a `tuple`.

`Tuples` are `ordered`, `immutable` sets of data; they are great for associating collections of data, sort of like a `struct` in `C`, but where those values are unlikely to change.

Here is a `list` of `tuples`:

```py
presidents = [ 
    ("George Washington", 1789), 
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801), 
    ("James Madison", 1809)
]
```

This list is iterable as well:

```py
# 'prez, year' matches the the tuples in our presidents list 
for prez, year in presidents: 
    print("In {1}, {0} took office".format(prez, year))
```

Output:

```output
In 1789, George Washington took office
In 1797, John Adams took office
In 1801, Thomas Jefferson took office
In 1809, James Madison took office
```

___

## [Dictionaries](#dictionaries)

`Python` also has built in support for `dictionaries`, allowing you to specify `list indices` with words or phrases (`keys`), instead of integers, which you were restricted to in `C`.

```py
# Dictionary of pizzas
pizzas = { 
    "cheese": 9, 
    "pepperoni": 10, 
    "vegetable": 11, 
    "buffalo chicken": 12 
}
```

```py
# Change value stored in key == "cheese"
pizzas["cheese"] = 8
```

```py
pizzas["cheese"] = 8
# Do if pizza[key] < 12
if pizza["vegetables"] < 12: 
    # do something
# Add new key-value pair
pizzas["bacon"] = 14
```

But this creates a somewhat new problem… how do we iterate through a dictionary? We don't have indexes ranging from `[0, n-1]` anymore.

___

## [Loops Redux](#loops-redux)

The `for` loop in Python is extremely flexible!

```py
for pie in pizzas: 
    # use pie in here as a stand-in for "i"
```

```py
# Dictionary of pizzas
pizzas = { 
    "cheese": 9, 
    "pepperoni": 10, 
    "vegetable": 11, 
    "buffalo chicken": 12 
}
```

```py
for pie in pizzas: 
    print(pie)
```

```output
cheese 
vegetable 
buffalo chicken 
pepperoni
```

```py
# .items() transforms dictionary into a list to iterate through values
for pie, price in pizzas.items(): 
    print(price)

# When converting a dict() into a list it is not garanteed that the items will maintain its order
```

```output
12 
10 
9 
11
```

```py
# Print key & value
for pie, price in pizzas.items(): 
    print("A whole {} pizza costs ${}".format(pie, price))
```

```output
A whole buffalo chicken pizza costs $12
A whole cheese pizza costs $9
A whole vegetable pizza costs $11
A whole pepperoni pizza costs $10
```

## [Printing and variable interpolation](#printing-and-variable-interpolation) 

`format` gives one way to interpolate variables into our printed statements in a very `printf`-like way, but there are others.

```py
print("A whole {} pizza costs ${}".format(pie, price))

print("A whole " + pie + " pizza costs $" + str(price))

# you may see this, but avoid;
deprecated print("A whole %s pizza costs $%2d" % (pie, price))
```

## [Functions](#functions)

`Python` has support for `functions` as well. Like `variables`, we don't need to specify the `return type` of the `function` (because it doesn't matter), nor the data types of any parameters (ditto).

All `functions` are introduced with the `def` keyword.
- Also, no need for `main`; the `interpreter` reads from top to bottom!
- If you wish to define `main` nonetheless (and you might want to!), you must at the very end of your code have: 

```py
if __name__ == "__main__": main() •
```

```py
def square(x): 
    return x * x
```

```py
## ** exponentiation operator
def square(x): 
    return x ** 2
```

```py
def square(x): 
    result = 0 
    for i in range(0, x): 
        result += x 
    return result

print(square(5))
```

The previous code snippets have the same effect.

___

## [Objects](#objects)

`Python` is an `object-oriented` programming language.

An `object` is sort of analogous to a `C structure`.

`C structures` contain a number of `fields`, which we might also call `properties`.

- But the `properties` themselves can not ever stand on their own.

```c
struct car 
{ 
    int year; 
    char *model; 
}
```

```c
// Initilizing a struct car
struct car herbie;
herbie.year = 1963; 
herbie.model = "Beetle";
```

`Objects`, meanwhile, have `properties` but also `methods`, or functions that are inherent to the `object`, and mean nothing outside of it. You define the `methods` inside the `object` also.

- Thus, `properties` and `methods` don’t ever stand on their own.

```py
object.method()
```

You define a type of `object` using the `class` keyword in `Python`.

`Classes` require an `initialization function`, also more-generally known as a `constructor`, which sets the starting values of the properties of the `object`.

In defining each `method` of an `object`, `self` should be its first parameter, which stipulates on what object the method is called.

```py
class Student(): 

    def **init**(self, name, id):
        # Object properties
        self.name = name 
        self.id = id 

    # Object methods
    def changeID(self, id): 
        self.id = id 

    def print(self): 
        print("{} – {}".format(self.name, self.id))
```

```py
# Initialize Student() class
jane = Student("Jane", 10) 
jane.print() 
jane.changeID(11) 
jane.print()
```

## [Style](#style)

If you haven't noticed, good style is _`crucial`_ in `Python`.

`Tabs` and `indentation` actually matter in this language, and things will not work the way you intend for them to if you disregard styling!

Good news? No more `curly braces` to delineate `blocks`!

- Now they just are used to declare `dictionaries`.

## [Including Files](#including-files)

Just like `C` programs can consist of multiple files to form a single program, so can Python programs tie files together.

```c
// C
#include <cs50.h>;
```

```py
# Python
import cs50
```

```py
cs50.get_int() 
cs50.get_float() 
cs50.get_string()
```

`Python` programs can be prewritten in `.py` files, but you can also write and test short Python `snippets` using the Python `interpreter` from the command line. 

All that is required is that the Python `interpreter` is installed on the system you wish to run your Python programs on.

To run your Python program through the Python `interpreter` at the command-line, simply type:

```py
python <file> 
```

and your program will run through the `interpreter`, which will execute everything inside of the file, top to bottom.

You can also make your programs look a lot more like `C` programs when they execute by adding a `shebang` to the top of your Python files, which automatically finds and executes the interpreter for you.

```py
#!/usr/bin/env python3
```

If you do this, you need to change the `permissions` on your file as well using the `Linux` command `chmod` as follows:

```sh
chmod a+x <file>
```

___

#### Return to [`CS50x`](/README.md)

___