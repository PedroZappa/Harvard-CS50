#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Iterate through user defined range
    for (int i = min; i <= max; i++)
    {
        // If true, print to terminal
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    if (number < 2)
    {
        return false;
    }
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