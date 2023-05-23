// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool isLower = false;
    bool isUpper = false;
    bool isNumber = false;
    bool isSymbol = false;

    // Loop through password[elements]
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        // if password[i] is lowercase, isLower = true
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            isLower = true;
        }
        // if password[i] is uppercase, isUpper = true
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            isUpper = true;
        }
        // if password[i] is number, isNumber = true
        else if (password[i] >= '0' && password[i] <= '9')
        {
            isNumber = true;
        }
        // if password[i] is symbol, isSymbol = true
        else
        {
            isSymbol = true;
        }
    }

    if (isLower == true && isUpper == true && isNumber == true && isSymbol == true)
    {
        // Return true if all bools == true
        return true;
    }

    return false;
}