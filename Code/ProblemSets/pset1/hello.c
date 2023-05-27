#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input
    string user = get_string("What's your name? ");

    // Print user name
    printf("Hello, %s!\n", user);
    return 0;
}