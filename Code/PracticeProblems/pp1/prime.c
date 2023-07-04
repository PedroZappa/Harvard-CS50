#include <stdbool.h>
#include <stdio.h>

// ANSI escape sequences to color output
const char  *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *reset = "\033[0m";

// Declare function prototypes
bool prime(int number);

// Main: Print primes through user defined range
int main(void)
{
    // Get user inputs for min and max
    int min;
    do
    {
        printf("%sMinimum: %s", blackBright, reset);
        scanf("%d", &min);
    }
    while (min < 1);

    int max;
    do
    {
        printf("%sMaximum: %s", blackBright, reset);
        scanf("%d", &max);
    }
    while (min >= max);

    // Print primes through user defined range
    for (int i = min; i <= max; i++)
    {
        // If the current number is prime, print to terminal
        if (prime(i))
        {
            // Print a comma if not first or last number
            if (i != min && i != max)
            {
                printf(", ");
            }
            printf("%s%i%s", cyan, i, reset);
        }
        
    }
    // Print a new line
    printf("\n");
    return 0;
}

// Boolean function to check if number is prime
bool prime(int number)
{
    // Check if number is less than 2
    if (number < 2)
    {
        return false;
    }
    // Check if number is 2
    if (number == 2)
    {
        return true;
    }
    // Check if number is even
    if (number % 2 == 0)
    {
        return false;
    }
    // Loop from 3 up to the squareRoot of the number, incrementing by 2 (odd numbers)
    for (int i = 3; i * i <= number; i += 2)
    {
        // if number is divisible by any of these odd numbers, return false
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;

    /*
        Note: This method is suitable for relatively small numbers (less than a million). For larger numbers, more sophisticated algorithms like the BPSW-primality test or the AKS primality test can be used, but they require more advanced knowledge and implementation.
    */
}