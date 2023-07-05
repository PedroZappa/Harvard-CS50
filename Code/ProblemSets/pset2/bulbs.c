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

const int MAX_LEN = 100;
const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get user input
    // string message = "Hi!";
    char message[MAX_LEN];
    printf("%sMessage: %s%s", blackBright, message, reset);
    fgets(message, MAX_LEN, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;

    // Loop through string and convert each character to binary
    for (int ch = 0, n = strlen(message); ch < n; ch++)
    {
        char c = message[ch];
        //  iterates from 7 to 0 through each bit of char c
        for (int j = BITS_IN_BYTE -1; j >= 0; j--)
        {
            // Bitwise shift op and Bitwise AND to isolate bit
            int bit = (c >> j) & 1;
            // Print bulb
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
