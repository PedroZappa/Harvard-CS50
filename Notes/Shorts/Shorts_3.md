CS50: Shorts 3
=======================

#### Return to [`CS50x`](/README.md)

=======================

## Table of Contents

- [`Linear Search`](#linear-search)
- [`Binary Search`](#binary-search)
- [`Bubble Sort`](#bubble-sort)
- [`Selection Sort`](#selection-sort)
- [`Recursion`](#recursion)
- [`Merge Sort`](#merge-sort)

___
___
____

## [`Linear Search`](#linear-search)

In `linear search`, the idea of the algorithm is to iterate across the array from left to right, searching for a specified element.

In pseudocode: 

- Repeat, starting at the first element:
  - If the first element is what you’re looking for (the target), stop.
  - Otherwise, move to the next element.

___

## Worst-case scenario [ `O(n)` ]:

We have to look through the entire array of n elements, either because the target element is the last element of the array or doesn’t exist in the array at all.

## Best-case scenario: [ `Ω(1)` ]

The target element is the first element of the array, and so we can stop looking immediately after we start.

___
___

## [`Binary Search`](#binary-search)

In `binary search`, the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a target number.

- In order to leverage this power however, our array must first be sorted, else we cannot make assumptions about the array’s contents.

In pseudocode:

- Repeat until the (sub)array is of size 0:
  - Calculate the middle point of the current (sub)array.
  - If the target is at the middle, stop.
  - Otherwise, if the target is less than what’s at the middle, repeat, changing the end point to be just to the left of the middle.
  - Otherwise, if the target is greater than what’s at the middle, repeat, changing the start point to be just to the right of the middle.

___

## Worst-case scenario [ `O(log n)` ]:

We have to divide a list of `n` elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division or doesn’t exist in the array at all.

## Best-case scenario: [ `Ω(1)` ]

The target element is at the midpoint of the full array, and so we can stop looking immediately after we start.

___
___

## [`Bubble Sort`](#bubble-sort)

In `bubble sort`, the idea of the algorithm is to move higher valued elements generally towards the right and lower value elements generally towards the left. 

In pseudocode: 
- Set swap counter to a non-zero value

- Repeat until the swap counter is 0:
  - Reset swap counter to 0;
  - Look at each adjacent pair;
    - If two adjacent elements are not in order, swap them and add one to the swap counter;

___

## Worst-case scenario [ `O(n2)` ]:

The array is in reverse order; we have to “bubble” each of the n elements all the way across the array, and since we can only fully bubble one element into position per pass, we must do this n times.

## Best-case scenario [ `Ω(n)` ]: 
The array is already perfectly sorted, and we make no swaps on the first pass.

___
___

## [`Selection Sort`](#selection-sort)

In `selection sort`, the idea of the algorithm is to find the smallest unsorted element and add it to the end of the sorted list.

In pseudocode:

- Repeat until no unsorted elements remain:
  - Search the unsorted part of the data to find the smallest value;
  - Swap the smallest found value with the first element of the unsorted part;

___

## Worst-case scenario [ `O(n2)` ]: 

We have to iterate over each of the n elements of the array (to find the smallest unsorted element) and we must repeat this process n times, since only one element gets sorted on each pass.

## Best-case scenario [ `Ω(n2)` ]: 

Exactly the same! There’s no way to guarantee the array is sorted until we go through this process for all the elements.

___
___

## [Recursion](#recursion)

- We might describe an implementation of an algorithm as being particularly “elegant” if it solves a problem in a way that is both interesting and easy to visualize.

- The technique of `recursion` is a very common way to implement such an “elegant” solution.

- The definition of a `recursive function` is one that, as part of its execution, invokes itself.

- The factorial function (`n!`) is defined over all positive integers. • n! equals all of the positive integers less than or equal to n, multiplied together.

- Thinking in terms of programming, we’ll define the mathematical function n! as fact(n).

```m
fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...
```

```m
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...
```

```m
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...
```

```m
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * 4 * 3 * 2 * 1
...
```

```m
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
...
```

```m
fact(=) = n * fact(n-1)
```

This forms the basis for a recursive definition of the
factorial function. 

Every recursive function has two cases that could
apply, given any input.

- The base case, which when triggered will terminate the recursive process.
- The recursive case, which is where the recursion will actually occur.

```c
int fact(int n) 
{ 
    // base case 
    
    // recursive case
}
```

```c
int fact(int n) 
{ 
    // base case
    if (n == 1) 
    { 
        return 1; 
    } 
    // recursive case
    else 
    { 
        return n * fact(n-1); 
    } 
}
```

Shrinked down version

```c
int fact(int n) 
{ 
    if (n == 1) 
        return 1; 
    else 
        return n * fact(n-1); 
}
```

In general, but not always, `recursive functions` replace `loops` in non-recursive functions.

```c
// Recursive Factorial Function
int fact(int n) 
{ 
    if (n == 1) 
        return 1; 
    else 
        return n * fact(n-1); 
}
```

```c
// Loop Factorial Function
int fact2(int n) 
{ 
    int product = 1; 
    while(n > 0) 
    { 
        product *= n;
        n--; 
    } 
    return product; 
}
```

It’s also possible to have more than one base or recursive case, if the program might recurse or terminate in different ways, depending on the input being passed in.

### Multiple base cases:

The `Fibonacci` number sequence is defined as follows:
- The first element is 0.
- The second element is 1.
- The nth element is the sum of the `(n-1)th` and `(n-2)th` elements.

### Multiple recursive cases:

The `Collatz` conjecture is applies to positive integers and speculates that it is always possible to get “back to 1” if you follow these steps:
- If n is 1, stop.
- Otherwise, if n is even, repeat this process on n/2.
- Otherwise, if n is odd, repeat this process on 3n + 1.

 Write a recursive function collatz(n) that calculates how many steps
it takes to get to 1 if you start from n and recurse as indicated above.

Run the following tests:

![Collatz conjecture](/IMG/Shorts3//shorts3_collatz.png)

```c
int collatz(int n) 
{ 
    // base case
    if (n == 1) 
        return 0; 
    // even numbers
    else if ((n % 2) == 0) 
        return 1 + collatz(n/2); 
    // odd numbers
    else 
        return 1 + collatz(3\*n + 1); 
}
```

## [Merge Sort](#merge-sort)

In `merge sort`, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order.

Merge sort leverages something called `recursion`, which we’ll touch on in more detail in a future video.

In pseudocode:

- Sort the left half of the array (assuming `n > 1`)
- Sort the right half of the array (assuming `n > 1`)
- Merge the two halves together

___

### Worst-case scenario [ `O(n log n)` ]:

We have to split n elements up and then recombine them, effectively doubling the sorted subarrays as we build them up. (combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into 4-element arrays…) 

### Best-case scenario [ `Ω(n log n)` ]:

The array is already perfectly sorted. But we still have to split and recombine it back together with this algorithm.

---
---

#### Return to [`CS50x`](/README.md)

=======================