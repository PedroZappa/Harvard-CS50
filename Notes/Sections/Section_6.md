Section_6: Python
=======================

#### Return to [`CS50x`](/README.md)

=======================

## Table o'Contents

[Strings](#strings)

[Dot notation](#dot-notation)

[Loops](#loops)

[Dictionaries](#dictionaries)

[Libraries](#libraries)

[File Reading, Writing](#file-reading-and-writing)

___
___

## [Strings](#strings)

### `Getting` a user input string:

```c
// In C ( using <cs50.h> )
char *text = get_string("...");
```

- `C` is a `statically typed language`, we have to declare a type before we can use it.

```py
# In Python
text = input("...")
```

- `Python` is a `dynamically typed language` we don't have to specify the `type` of a variable, the `Python Interpreter` will infer that for us.

___
___

### `Comparing` a string:

```c
// In C
if (strcmp(text, "hello") == 0) { ... }
```

- in `C` we use the `strcmp` function.
- we need curly braces and indentation;

```py
# In Python
if text == "hello": ...
```

- in `Python` we simply use the `==` operator.
- NO need for curly braces, `only indentation`.


### Accessing a character in a string:

```c
// In C
text[i]
```

```py
# In Python
text[i]
```
___
___

## [Dot Notation](#dot-notation)

Using `Dot Notation` we can access data and methods inside an object, for instance:

```py
text = input("...") 
text.strip()
```

- `.strip()` is a built-in function that returns a copy of a string with `leading` and `trailing` whitespace removed.

```py
text = input("...") 
text.lower()
```

- `.lower()` is a built-in function that returns a copy of a string with all characters converted to lowercase.

```py
text = input("...") 
text.capitalize()
```

- `.capitalize()` is a built-in function that returns a copy of a string with the `first character` converted to `uppercase`.


### str == string [ [Python String Docs](https://docs.python.org/3/library/stdtypes.html) ]

___
___

## [Loops](#loops)

### for / in 

```py
text = "In the great green room"

for c in text: 
    print(c)
```

- Loops through each character stored in `text`.

```py
words = text.split()
```

- `.split()`, looks-up spaces, when found splits the string into a `list` of substrings.

Output:

```py
# Python List
["In", "the", "great", "green", "room"]
```

- In `Python` the `[]` (square brackets) denote a list
- `,`s ( `commas` ) divide  substrings within a list


To Loop through each `substring` (word) in a `list` (words):

```py
words = text.split() 
for word in words: 
    print(word)
```

Output:

```py
["In", "the", "great", "green", "room"]
```

- Python's `for / in` syntax helps you iterate through components of an "iterable" while referring to them by a convenient name.

- When your iterable is a `list`, you'll iterate over every `element` of the `list`.

- When your iterable is a `string`, you'll iterate over every character of the `string`.

### Text Analysis 

Look at `text.py`. Using what you know about Python's syntax, guess what each round of loops will print to the terminal. If feeling more comfortable, try writing your own loop to reverse the text given in the ﬁle.

```py
text = "In the great green room"
words = text.split()

# Round 1 => for / in Loop
print("Round 1")
for word in words:
    print(word)
print()

# Prints "In the great green room", one word per line

# Round 1.2 => for / in Loop
print("Round 1")
for word in words:
    print(word, end=" ")
print()

# Prints "In the great green room", all in one line

# Round 2
print("Round 2")
for word in words:
    for c in word:
        print(c)
print()

# Prints one char per line

# Round 3
print("Round 3")
for word in words:
    if "g" in word:
        print(word)
print()

# Prints only the words that contain "g"

# Round 4
print("Round 4")
for word in words[2:]:
    print(word)
print()

# Prints words from index 2 to the end

# Round 4.2
print("Round 4")
for word in words[2:4]:
    print(word)
print()

# Prints words from index 2 to 3
# The first number is inclusive, the second number is exclusive

# Round 5
print("Round 5")
for word in words:
    print("Goodnight Moon")
print()

# Prints "Goodnight Moon" for each word in words
```

___
___

## [Dictionaries](#dictionaries)

Dictionaries store key-value pairs.

`Authors` Dictionary:

![Key-Value Pairs](/IMG/Sect6/Sect6_0.png)

`Book` Dictionary:

![Key-Value Pairs](/IMG/Sect6/Sect6_1.png)

```py
book = dict()
```

- Create an empty `dictionary` and call it book.

![Key-Value Pairs](/IMG/Sect6/Sect6_2.png)

- Add a `key` called `"title"` and assign it the value `"Corduroy"`

![Key-Value Pairs](/IMG/Sect6/Sect6_3.png)

- Add a `key` called `"author"` and assign it the value `"Don Freeman"`

![Key-Value Pairs](/IMG/Sect6/Sect6_4.png)

- Prints the value stored in `title` in the book dictionary: `Corduroy`

![Key-Value Pairs](/IMG/Sect6/Sect6_6.png)

- Asking for a key that doesn't exist returns `KeyError`

![Key-Value Pairs](/IMG/Sect6/Sect6_7.png)

Book Dictionary Python Syntax

```py
book = { 
    "title": "Goodnight Moon", 
    "author": "Margaret Wise Brown" 
}
```

A `list` of `Dictionaries`:

```py
[
    {"title": "Goodnight Moon", ...}, 
    {"title": "Corduroy", ...},
    {"title": "Curious George", ...}
]
```

\[{"title": "Goodnight Moon", ...}, {"title": "Corduroy", ...},
{"title": "Curious George", ...}\]

\[{"title": "Goodnight Moon", ...}, {"title": "Corduroy", ...},
{"title": "Curious George", ...}\]

___
___

### Shelf of Books

Download `books.py`. Complete `books.py` so that a user is prompted to continue adding books (with a title and author) to a `list` of books.

If feeling more comfortable, try "sanitizing" the user's input by stripping whitespace and capitalizing each word in the title.

```py
books = []

# Add three books to your shelf
for i in range(3):
    book = dict()
    # Get user input then sanitze: strip & capitalize
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ").strip().capitalize()

    # Add book to list
    books.append(book)

# Print book titles
for book in books:
    print(book["title"])
```

___
___

## [Libraries and Modules](#libraries-and-modules)

books.csv

```csv
title,author
Goodnight Moon,Margaret Wise Brown
Corduroy,Don Freeman
Curious George,H.A. Ray
Winnie-the-Pooh,A.A. Milne
Fantastic Mr. Fox,Ronald Dahl 
...
```

In python to read csv files we [import the csv module](https://docs.python.org/3/library/csv.html).

```py
import csv
```

Defined inside the `csv` module:

- DictReader
- DictWriter
- reader
- writer

To use DictReader:

```py
import csv

csv.DictReader(...)
```

or 

```py
from csv import DictReader

DictReader(...)
```

Its preferable to import the full module instead of individual functions so that we don't pollute our namespace.

___
___

## [File Reading and Writing](#file-reading-and-writing)

### Good reads 

Download `reads.py` and `books.csv`. Complete `reads.py` so that a user can build a list of children's books. If feeling more comfortable, try allowing the user to eliminate books by certain authors (e.g., "Ronald Dahl").

book.csv

```csv
title,author
Goodnight Moon,Margaret Wise Brown
Corduroy,Don Freeman
Curious George,H.A. Ray
Winnie-the-Pooh,A.A. Milne
Fantastic Mr. Fox,Roald Dahl
Charlotte's Web,E.B. White
Rainbow Flower,Valentin Kataev
The Cat That Lived a Million Times,Yoko Sano
The Little Prince,Antoine de Saint-Exupéry
The Hen Who Dreamed She Could Fly,Sun-mi Hwang
The Tale of Peter Rabbit,Beatrix Potter
Matilda,Roald Dahl
The Very Hungry Caterpillar,Eric Carle
Stellaluna,Janell Cannon
Dinosaurs Before Dark,Mary Pope Osborne
```

reads.py

```py
import csv

books = []

# Add books to your shelf by reading from books.csv
## while indented the file will be open, 
## once unindented the file will be closed
with open("books.csv") as file:
    file_reader = csv.DictReader(file)
    for book in file_reader:
        books.append(book)

# Print titles of books
for book in books:
    print(book["title"])
```

Opens a file:

```py
with open(FILENAME) as file:
```

Opens a file, reads it line by line, does something with each line ( indented lines ), and closes the file ( when unindented ):

```py
with open(FILENAME) as file: 
    text = file.read()
```

DictReader is a special reader used to read csv files:

```py
with open(FILENAME) as file: 
    file_reader = csv.DictReader(file) 
    for row in file_reader: 
        ...
```

___
___

#### Return to [`CS50x`](/README.md)