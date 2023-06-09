#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *red = "\033[31m";
const char *reset = "\033[0m";

// Declare function prototypes
bool prime(int number);

// Main: Print primes through user defined range
int main(void)
{
    // Declare input as a string
    char input[10];

    // Get user inputs
    // Get min
    int min;
    do
    {
        printf("%sMinimum: %s", blackBright, reset);
        fgets(input, sizeof(input), stdin);

        // Loop through input min string
        int i;
        for (i = 0; i < strlen(input) - 1; i++)
        {
            // Break if character is not a digit
            if (!isdigit(input[i]))
            {
                break;
            }
        }
        // if i is the last character & i is greater than 0
        if (i == strlen(input) - 1 && i > 0)
        {
            // Convert string to integer
            min = atoi(input);
        }
        else
        {
            min = 0;
        }
    }
    while (min < 1);

    // Get max
    int max;
    do
    {
        printf("%sMaximum: %s", blackBright, reset);
        fgets(input, sizeof(input), stdin);

        // Loop through input max string
        int i;
        for (i = 0; i < strlen(input) - 1; i++)
        {
            // Break if character is not a digit
            if (!isdigit(input[i]))
            {
                break;
            }
        }
        // if i is the last character & i is greater than 0
        if (i == strlen(input) - 1 && i > 0)
        {
            // Convert string to integer
            max = atoi(input);
        }
        else
        {
            max = 0;
        }
    }
    while (min >= max);

    // Print primes through user defined range
    int total_primes = 0;
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
            total_primes++;
        }
        
    }
    // Print a new line
    printf("\n");

    // Print number of prime numbers printed
    printf(
        "There are %s%d%s primes between %s%i%s and %s%i%s.\n", 
        red, total_primes, reset, blackBright, min, reset, blackBright, max, reset
    );

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