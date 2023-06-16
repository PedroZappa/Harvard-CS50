#include <stdio.h>

int main(void) {
    float start, end, years = 0.0;

    // Prompt the user for a starting # o'llamas
    do {
        printf("Initial # of llamas: ");
        scanf("%f", &start);
    } while (start < 9.0); // Re-Prompt if input is less than 9;

    // Prompt the user for an ending # o'llamas
    do {
        printf("Desired # of llamas: ");
        scanf("%f", &end);
    } while ( end < start );

    // How many years will it take to get to the goal?
    // Every year, 1/3 of our curent llamas are born; 1/4 passes away;
    // { Common denominator of 1/3 & 1/4 = 1/12 new llamas per year }
    while (start < end) {
        start += start / 12.0;
        years++;
    }

    printf(
        "Starting with %i llamas, it will take %i year(s) to reach a population of %i llamas\n", 
        start, years, end
    );

    return 0;
}