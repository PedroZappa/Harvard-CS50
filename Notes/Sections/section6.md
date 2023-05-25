This is CS50

What questions do you have?

Strings

Dot notation

Loops

e.g., str.lower()

Dictionaries

Libraries

File Reading, Writing

Strings

"In the great green room"

"there was a telephone and a red balloon"

char \*text = get\_string("...");

text = input("...")

if (strcmp(text, "hello") == 0) { ... }

if text == "hello": ...

text\[i\]

text\[i\]

Dot Notation

text = input("...")

" In the great green room

"

text = input("...") text.strip()

" In the great green room

"

text = input("...") text.strip()

"In the great green room"

text = input("...")

"IN thE great green ROom"

text = input("...") text.lower()

"IN thE great green ROom"

text = input("...") text.lower()

"in the great green room"

text = input("...") text.capitalize()

"IN thE great green ROom"

text = input("...") text.capitalize()

"In the great green room"

str

candidate

candidate.name

candidate.votes

str

str.capitalize()

str.lower()

Loops

for c in text: print(c)

"In the great green room"

for c in text: print(c) c

"In the great green room"

for c in text: print(c) c

"In the great green room"

for c in text: print(c) c

"In the great green room"

for c in text: print(c) c

"In the great green room"

for c in text: print(c) c

"In the great green room"

for c in text: print(c) c

"In the great green room"

words = text.split()

"In the great green room"

words = text.split()

\["In", "the", "great", "green", "room"\]

words = text.split() for word in words: print(word)

\["In", "the", "great", "green", "room"\]

words = text.split() for word in words: print(word)

word

\["In", "the", "great", "green", "room"\]

words = text.split() for word in words: print(word)

word

\["In", "the", "great", "green", "room"\]

words = text.split() for word in words: print(word)

word

\["In", "the", "great", "green", "room"\]

● Python's for / in syntax helps you iterate through components of an
"iterable" while referring to them by a convenient name. ● When your
iterable is a list, you'll iterate over every element of the list. ●
When your iterable is a string, you'll iterate over every character of
the string.

Text Analysis Look at text.py. Using what you know about Python's
syntax, guess what each round of loops will print to the terminal. If
feeling more comfortable, try writing your own loop to reverse the text
given in the ﬁle.

Dictionaries

authors Goodnight Moon Margaret Wise Brown

Corduroy Don Freeman

Curious George H.A. Ray

authors Goodnight Moon Margaret Wise Brown

Corduroy Don Freeman

Curious George H.A. Ray

Key Value

book Title Goodnight Moon

Author Margaret Wise Brown

book = dict()

book

book = dict()

book title book = dict() book\["title"\] = "Corduroy"

Corduroy

book title book = dict() book\["title"\] = "Corduroy" book\["author"\]
= "Don Freeman"

Corduroy

author Don Freeman

book title book = dict() book\["title"\] = "Corduroy" book\["author"\]
= "Don Freeman" print(book\["title"\])

Corduroy

author Don Freeman

book title book = dict() book\["title"\] = "Corduroy" book\["author"\]
= "Don Freeman" print(book\["title"\])

Corduroy

author Don Freeman

"Corduroy"
==========

book title book = dict() book\["title"\] = "Corduroy" book\["author"\]
= "Don Freeman" print(book["Corduroy"](#corduroy))

Corduroy

author Don Freeman

book title book = dict() book\["title"\] = "Corduroy" book\["author"\]
= "Don Freeman" print(book["Corduroy"](#corduroy))

Corduroy

author Don Freeman

KeyError: 'Corduroy'

book = { "title": "Goodnight Moon", "author": "Margaret Wise Brown" }

\[{"title": "Goodnight Moon", ...}, {"title": "Corduroy", ...},
{"title": "Curious George", ...}\]

\[{"title": "Goodnight Moon", ...}, {"title": "Corduroy", ...},
{"title": "Curious George", ...}\]

\[{"title": "Goodnight Moon", ...}, {"title": "Corduroy", ...},
{"title": "Curious George", ...}\]

Shelf of Books Download books.py. Complete books.py so that a user is
prompted to continue adding books (with a title and author) to a list of
books. If feeling more comfortable, try "sanitizing" the user's input by
stripping whitespace and capitalizing each word in the title.

Libraries and Modules

books.csv title,author Goodnight Moon,Margaret Wise Brown Corduroy,Don
Freeman Curious George,H.A. Ray Winnie-the-Pooh,A.A. Milne Fantastic Mr.
Fox,Roald Dahl ...

import csv

import csv

csv

import csv

DictReader DictWriter reader writer

import csv csv.DictReader(...)

DictReader DictWriter reader writer

import csv csv.DictReader(...) csv.reader(...)

DictReader DictWriter reader writer

import csv

DictReader DictWriter reader writer

from csv import DictReader

DictReader DictWriter reader writer

from csv import DictReader DictReader(...)

DictReader DictWriter reader writer

File Reading and Writing

with open(FILENAME) as file:

with open(FILENAME) as file: text = file.read()

with open(FILENAME) as file: file\_reader = csv.DictReader(file)

with open(FILENAME) as file: file\_reader = csv.DictReader(file) for
row in file\_reader:

with open(FILENAME) as file: file\_reader = csv.DictReader(file) for
row in file\_reader: ...

Good reads Download reads.py and books.csv. Complete reads.py so that a
user can build a list of children's books. If feeling more comfortable,
try allowing the user to eliminate books by certain authors (e.g.,
"Roald Dahl").

This was CS50


