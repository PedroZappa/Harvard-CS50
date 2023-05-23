#include <cs50.h>
#include <stdio.h>

int main(void) {
  int start, end, years = 0;

  // Prompt the user for a starting # o'llamas
  do {
    start = get_int("Initial # of llamas: ");
  } while (start < 9); // Re-Prompt if input is less than 9;

  // Prompt the user for an ending # o'llamas
  do {
    end = get_int("Desired # of llamas: ");
  } while ( end < start );

  // How many years will it take to get to the goal?
  // Every year, 1/3 of our curent llamas are born; 1/4 passes away;
  // { Common denominator of 1/3 & 1/4 = 1/12 new llamas per year }
  while (start < end) {
    start += start / 12;
    years++;
  }

  printf("Starting with %i llamas, it will take %i year(s) to reach a population of %i llamas\n", start, years, end);

  return 0;
}