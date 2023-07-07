// Practice working with structs
// Practice applying sorting algorithms
#include <stdio.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

#define NUM_CITIES 10

typedef struct
{
    char *city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

// Function prototypes
void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // Sort cities by temperature
    sort_cities();

    printf(BLACKWHITE "Average July Temperatures by City" RESET "\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf(BLACKBRIGHT "%s: " RESET YELLOW " %i\n" RESET, temps[i].city, temps[i].temp);
    }

    return 0;
}

// Sort cities by temperature in descending order
void sort_cities(void)
{
    // Bubble sort through temps[]
    int n = NUM_CITIES; // Number of cities
    avg_temp temp_buffer; // Temporary buffer for swapping

    // Outer loop for each pass
    for (int i = 0; i < n; i++)
    {
        // Inner loop for comparisons and swapping
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare the temperatures of adjacent cities
            if (temps[j].temp < temps[j + 1].temp)
            {
                // if the current temp is less than the next temp
                temp_buffer = temps[j]; // Store the current in buffer
                temps[j] = temps[j+ 1]; // Overwrite current with next
                temps[j + 1] = temp_buffer; // Overwrite next with buffered current
            }
        }
    }
}
