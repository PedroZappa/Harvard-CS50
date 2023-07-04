#include <stdio.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

// Declare function prototypes
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

// Main: Print total number of coins to give the customer
int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf(
        "%sTotal # coins to give the customer:%s %i\n", 
        blackBright, reset, coins 
    );
    // Print quarters
    printf(
        "%sQuarters:%s %s%i%s\n", 
        blackBright, reset, magenta, quarters, reset
    );
    // Print dimes
    printf(
        "%sDimes:%s %s%i%s\n",
        blackBright, reset, cyan, dimes, reset
    );
    // Print nickels
    printf(
        "%sNickels:%s %s%i%s\n",
        blackBright, reset, red, nickels, reset
    );
    // Print pennies
    printf(
        "%sPennies:%s %s%i%s\n",
        blackBright, reset, green, pennies, reset
    );
}

int get_cents(void)
{
    // Get user input: must be a positive integer
    int cents;
    do
    {
        printf("%sChange owed: %s", blackBright, reset);
        // If scanf return value of 1, it means that the input was invalid
        if (scanf("%d", &cents) != 1)
        {
            // If scanf() couldn't scan an integer, consume invalid input and continue prompting
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
    while (cents < 0);

    return (int) cents;
}

int calculate_quarters(int cents)
{
    int quarter = 25, quarters = 0;

    // if cents < 25 return 0
    if (cents < 25)
    {
        return 0;
    }
    else
    {
        // Subtract 25 cents
        do
        {
            cents -= quarter;
            quarters++;
        }
        while (cents >= quarter);
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dime = 10, dimes = 0;

    // if cents < 10 return 0
    if (cents < 10)
    {
        return 0;
    }
    else
    {
        // Subtract 10 cents
        do
        {
            cents -= dime;
            dimes++;
        }
        while (cents >= dime);
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickel = 5, nickels = 0;

    // if cents < 5 return 0
    if (cents < 5)
    {
        return 0;
    }
    else
    {
        // Subtract 5 cents
        do
        {
            cents -= nickel;
            nickels++;
        }
        while (cents >= nickel);
    }

    return nickels;
}

int calculate_pennies(int cents)
{
    int pennie = 1, pennies = 0;

    // if cents < 1 return 0
    if (cents < 1)
    {
        return 0;
    }
    else
    {
        // Subtract 1 cents
        do
        {
            cents -= pennie;
            pennies++;
        }
        while (cents >= pennie);
    }

    return pennies;
}
