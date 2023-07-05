#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *yellow = "\033[33m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

// Declare function prototypes
float calc_hours(int *hours, int weeks, char output);
char print_output(int *hours, int weeks, char output);

// Main: Calculate total or average hours/week
int main(void)
{
    // Declare user input as a string
    char input[10];

    // Get number of weeks taking CS50 from user
    int weeks, result;
    do {
        printf(
            "%sNumber of weeks%s taking %sCS50%s: ",
            cyan, reset, magenta, reset
        );
        fgets(input, sizeof(input), stdin);

        // Try to read an integer from the input
        result = sscanf(input, "%d", &weeks);

        // If sscanf couldn't read an integer or the number is not positive, print an error message
        if (result != 1 || weeks <= 0)
        {
            printf(
                "Ups! %sInvalid%s # o'Weeks. Please input a %spositive integer%s!\n",
                red, reset, green, reset
            );
            weeks = 0; // Reset weeks to 0 so the loop continues
        }
    }
    while (weeks <= 0);

    // Get hours taken for each week
    int hours[weeks];
    do 
    {   
        // Loop # times through # o'Weeks
        for (int i = 0; i < weeks; i++)
        {
            do
            {
                printf("Week %i HW Hours: ", i);
                fgets(input, sizeof(input), stdin);

                // Try to read an integer from the input
                result = sscanf(input, "%d", &hours[i]);   

                // If sscanf couldn't read an integer or the number is not positive, print an error message
                if (result != 1 || hours[i] < 0)
                {
                    printf(
                        "Ups! %sInvalid%s # of Hours. Please input a %spositive integer%s!\n",
                        red, reset, green, reset
                    );
                }    
            } while (result != 1 || hours[i] < 0);    
        } 
    } while (hours < 0);

    // Select output type
    char output;
    do
    {
        printf(
            "Enter %sT%s for %stotal%s hours, %sA%s for %saverage%s hours per week: ",
            green, reset, green, reset, cyan, reset, cyan, reset
        );
        scanf(" %c", &output);
        output = toupper(output);
    }
    while (output != 'T' && output != 'A');

    // Print output
    print_output(hours, weeks, output);
}

// Calculate Total Hours or Average Hours per Week
float calc_hours(int *hours, int weeks, char output)
{
    // total hours
    float total_hours = 0.0;

    // total_hours switch
    switch (output)
    {
        case 'T': 
            // calculate the total hours
            for (int i = 0; i < weeks; i++)
            {
                total_hours += hours[i];
            }
            break;
        case 'A':
            // calculate average hours per week
            for (int i = 0; i < weeks; i++)
                {
                    total_hours += hours[i];
                }
                total_hours /= weeks;
            break;

        default:
            printf(
                "%sUps! Invalid input%s\n", 
                red, reset
            );
            break;
    }

    return total_hours;
}

// Print output
char print_output(int *hours, int weeks, char output)
{
    // Print 
    switch (output)
    {
        case 'T':
            printf(
                "%s%.1f%s hours\n", 
                green, calc_hours(hours, weeks, output), reset
            );
            break;
        case 'A':
            printf(
                "%s%.1f%s hours\n", 
                cyan, calc_hours(hours, weeks, output), reset
            );
            break;
        default:
            break;
    }

    return 0;
}