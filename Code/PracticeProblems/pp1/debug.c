// Become familiar wih C syntax
// Learn to debug buggy code
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

int main(void)
{
    // Declare strings
    char name[MAX_SIZE];
    char location[MAX_SIZE];

    // Ask for your name and where live
    printf("What is your name? ");
    fgets(name, MAX_SIZE, stdin);
    // Remove newline character from name and insert null character by array indexing
    name[strcspn(name, "\n")] = '\0';

    printf("Where do you live? ");
    fgets(location, MAX_SIZE, stdin);
    // Remove newline character from location and insert null character by array indexing
    location[strcspn(location, "\n")] = '\0';

    // ANSI escape sequences to color output
    const char *red = "\033[31m";
    const char *blue = "\033[34m";
    const char *reset = "\033[0m";

    // Say hello
    printf("Hello %s%s%s, from %s%s%s!\n", red, name, reset, blue, location, reset);

    return 0;
}
