// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *yellow = "\033[33m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

const int MAX_LEN = 30;

typedef struct {
    bool isLower;
    bool isUpper;
    bool isNumber;
    bool isSymbol;
    bool valid;
} PasswordState;

// Function prototypes
PasswordState valid(char* password);


// Main: Check if a password is valid
int main(void)
{
    char password[30];
    printf("%sEnter your password: %s", blackBright, reset);
    fgets(password, MAX_LEN, stdin);

    // Check that a password has at least one lowercase letter, uppercase letter, number and symbol
    PasswordState valid_result = valid(password);

    // Print Constrains
    printf("%sConstrains met%s\n", cyan, reset);
    printf(
        "%sLowercase%s && %sUppercase%s && %sNumber%s && %sSymbol%s\n",
        valid_result.isLower ? green : yellow, reset,
        valid_result.isUpper ? green : yellow, reset,
        valid_result.isNumber ? green : yellow, reset,
        valid_result.isSymbol ? green : yellow, reset
    );

    // Print valid() result
    if (valid_result.valid == true)
    {
        printf("Your password is %svalid%s\n", green, reset);
    }
    else
    {
        printf("Your password is %sinvalid%s\n", red, reset);
    }
}

PasswordState valid(char* password)
{
    PasswordState state = {
        .isLower = false,
        .isUpper = false,
        .isNumber = false,
        .isSymbol = false,
        .valid = false
    };

    // Loop through each password[letter]
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        // if password[i] is lowercase, isLower = true
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            state.isLower = true;
        }
        // if password[i] is uppercase, isUpper = true
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            state.isUpper = true;
        }
        // if password[i] is number, isNumber = true
        else if (password[i] >= '0' && password[i] <= '9')
        {
            state.isNumber = true;
        }
        // if password[i] is symbol, isSymbol = true
        else if (password[i] == '@' || password[i] == '#' || password[i] == '!' || password[i] == '~' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+' || password[i] == '/' || password[i] == ':' || password[i] == '.' || password[i] == ',' || password[i] == '<' || password[i] == '>' || password[i] == '?' || password[i] == '|' || password[i] == '_')
        {
            state.isSymbol = true;
        }
    }

    // Return true if all constrains are met
    if (state.isLower == true && state.isUpper == true && state.isNumber == true && state.isSymbol == true)
    {
        state.valid = true;
    }

    return state;
}