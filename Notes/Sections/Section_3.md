CS50: Section_2
=======================

#### Return to [`CS50x`](/README.md)

=======================

[https://cs50.harvard.edu/x/2023/sections/3/]

## How should we `compare` algorithms?

- Running Time / Number of Steps;
- `Binary Search` requires some kind of `Sorting`;

| | Linear Search | Binary Search | Selection Sort | Bubble Sort | Merge Sort |
|-------|----------|-----------|-------|---|--|
| Upper Bounds | O(n) | O(log n) |  O(n^2) | O(n^2) | O(n log n) |
| Theta | | | Θ(n^2) | | Θ(n log n)
| Lower Bounds | Ω(1) | Ω(1) | Ω(n^2) | O(n) | O(n log n) |


- For any input, what is the `most number of steps` my algorithm will ever take? 
  - (Big O) [Worst Case] {Upper Bound}

- For any input, what is the `least number of steps` my algorithm will evertake? 
  - (Omega) [Best Case] {Lower Bound}

___
___

## Structs

### When are `structs` useful?

- Example

```c
// Type Definition
typedef struct 
{
    string name;
    int votes;  
}
candidate;

// Variable Declaration
candidate president;
president.name = "Arnold";
president.votes = 10;
```

### Structs and Functions Exercise:

- Create your own `get_candidate` function that prompts the user to input attributes for a `candidate`;

- You may rely on `get_string`, `get_float`, etc.

- Your function should return a `candidate`;

Get One Candidate.

```c
#include <cs50.h>
#include <stdio.h>

// Type Definition
typedef struct 
{
    string name;
    int votes;
}
candidate;

// Function Prototype
candidate get_candidate(string prompt);

int main(void)
{
    // Get Candidate Data
    candidate president = get_candidate("Enter a candidate: ");
    printf("%s\n", president.name);
    printf("%d\n", president.votes);
}

candidate get_candidate(string prompt)
{
    // Print user input Prompt;
    printf("%s\n", prompt);
    // create new candidate c;
    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter number of votes: ");

    return c;
}
```

Get Several Candidates.

```c
#include <cs50.h>
#include <stdio.h>

// Type Definition
typedef struct 
{
    string name;
    int votes;
}
candidate;

// Function Prototype
candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates_Array[3];
    // Get Candidates Data
    for (int i = 0; i < 3; i++)
    {
        candidates_Array[i] = get_candidate("Enter a candidate:");
    }
    // Print Candidates Data
    ...
}

candidate get_candidate(string prompt)
{
    // Print user input Prompt;
    printf("%s\n", prompt);
    // create new candidate c;
    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter number of votes: ");

    return c;
}
```

## What is `Recursion`?

Takes a big problem and breaks it down into small pieces;

### Factorial Theory

```c
            1! = 1
        2! = 2 * 1
    3! = 3 * 2 * 1
4! = 4 * 3 * 2 * 1

// can't solve 4! (4factorial) without solving 3! (3factorial) and so on...
4! = 4 * 3! // Recursive call
// What is `3!`?
3! = 3 * 2! 
// What is `2!`?
2! = 2 * 1!
// What is `1!`?
1! = 1 // Base Case

// After finding the base case we go up the `Call Stack` to find the answer
4! = 24
```

### Factorial Exercise

- Write your own recursive function called `factorial`;

- `factorial` should take an `int` and return the factorial of the number as a parameter;

```c
#include <cs50.h>
#include <stdio.h>

// Function Prototype
int factorial(int number);

int main(void)
{
    // Prompt user for a number
    int n = get_int("Type a number: ");
    printf("%i\n", factorial(n));
}

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }
    return number * factorial(number - 1);
}
```

Draw things out in pseudocode before trying to write actual code!

=======================

#### Return to [`CS50x`](/README.md)

=======================