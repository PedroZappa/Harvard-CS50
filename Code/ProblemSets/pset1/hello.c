#include <stdio.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *green = "\033[32m";
const char *reset = "\033[0m";

#define MAX_NAME_LEN 100

int main(void)
{
    // Get user input
    char user[MAX_NAME_LEN];
    printf(
        "%sWhat's your name? %s", 
        blackBright, reset
    );
    fgets(user, MAX_NAME_LEN, stdin);

    // Remove newline character from user input
    user[strcspn(user, "\n")] = 0;

    // Print user name
    printf(
        "Hello, %s%s%s!\n", 
        green, user, reset
    );
    return 0;
}