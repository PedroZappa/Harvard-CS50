// Practice writing a function to find a max value
#include <ctype.h> // isdigit()
#include <stdio.h>
#include <string.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Function prototypes
int max(int array[], int n);
int atoi(char *input);

int main(void)
{
    // Get user input number of elements
    int n;
    do
    {
        printf(BLACKBRIGHT "Number of elements: "RESET);
        scanf("%i", &n);
        // Consume all remaining characters in the input buffer
        while (getchar() != '\n');
    } 
    while (n < 1); // Re-prompt if n is less than 1

    // Check if the input is made up of only digits
    char buffer[100]; // Temporary buffer for user input
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int valid;
        do
        {
            // Get value for each element
            valid = 1;
            printf(CYAN "Element %i: " RESET, i);
            fgets(buffer, sizeof(buffer), stdin);

            // Loop through inputs indexes
            for (int j = 0; j < strlen(buffer); j++)
            {
                // Check if input is a letter
                if ((buffer[j] >= 'a' && buffer[j] <= 'z') || (buffer[j] >= 'A' && buffer[j] <= 'Z'))
                {
                    valid = 0;
                    break;
                }
            }

            if (valid)
            {
                // Parse input as integer
                sscanf(buffer, "%d", &arr[i]); 

                // Check if input is a negative number
                if (arr[i] <= 0)
                {
                    valid = 0;
                }
            }
        } 
        while (!valid); // Re-prompt if input is a letter or non-positive
    }

    printf("The max value is " GREEN "%i.\n" RESET, max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max_value = array[0];

    for (int i = 0; i< n ; i++)
    {
        if (max_value < array[i])
        {
            max_value = array[i];
        }
    }
    return max_value;
}