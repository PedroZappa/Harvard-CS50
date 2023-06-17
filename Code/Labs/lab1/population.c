#include <stdio.h>

int main(void) {
    float start, end;
    int years = 0;

    // Prompt the user for a starting # o'llamas
    do {
        printf("Initial # of llamas: ");
        scanf("%f", &start);
    } while (start < 9.0); // Re-Prompt if input is less than 9;

    // Prompt the user for an ending # o'llamas
    do {
        printf("Desired # of llamas: ");
        scanf("%f", &end);
    } while ( end <= start );

    // How many years will it take to get to the goal?
    // Every year, 1/3 of our curent llamas are born; 1/4 passes away;
    // { Common denominator of 1/3 & 1/4 = 1/12 new llamas per year }
    while ((int)start < (int)end) {
        start += start / 12.0;
        years++;
    }

    // ANSI escape sequences to color output
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *blue = "\033[34m";
    const char *reset = "\033[0m";

    printf(
        "Starting with %s%i llamas%s\nit will take %s%i year(s)%s\nto reach a population of %s%i llamas%s\n", 
        green, (int)start, reset, red, years, reset, blue, (int)end, reset
    );

    return 0;
}