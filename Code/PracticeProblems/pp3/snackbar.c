// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

// #include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // malloc() free()
#include <string.h>
#include <strings.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10
#define MAX_LEN 30

// Menu itmes have item name and price
typedef struct
{
    char *item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Function prototypes
void add_items(void); // Add items to menu
float get_cost(char *item); // Calculate total cost

int main(void)
{
    add_items();

    printf(BLACKWHITE "Welcome to Beach Burger Shack!" RESET "\n");
    printf(RED "Choose from the following menu to order." RESET " Press enter when done!\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf(YELLOW "%s: " RESET "$%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    // Get user input
    float total = 0;
    while (1)
    {
        char *item = malloc(MAX_LEN);
        printf(CYAN "Enter a food item: " RESET);
        fgets(item, MAX_LEN, stdin);
        if (item[0] == '\n')
        {
            printf("\n");
            break;
        }
        // Remove the newline character from the input
        item[strcspn(item, "\n")] = '\0';
        // Strip leading whitespaces
        while (isspace((unsigned char)item[0]))
        {
            memmove(item, item + 1, strlen(item));
        }
        // Strip trailing whitespaces
        char *end = item + strlen(item) - 1; // Get the end of the string
        while (end >= item && isspace((unsigned char)*end))
        {
            *end = '\0';
            end--;
        }

        // Calculate total
        total += get_cost(item);

        // Free the dynamically allocated memory
        free(item);
    }

    printf(GREEN "Your total cost is: $%.2f\n" RESET, total);
}

// Add at least the first for items to the menu array
void add_items(void)
{
    menu[0].item = "Burger";
    menu[0].price = 9.5;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11;

    menu[2].item = "Hot Hog";
    menu[2].price = 5;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7;

    menu[4].item = "Fries";
    menu[4].price = 5;

    menu[5].item = "Cheese Fries";
    menu[5].price = 6;

    menu[6].item = "Cold Pressed Juice";
    menu[6].price = 7;

    menu[7].item = "Cold Brew";
    menu[7].price = 3;

    menu[8].item = "Water";
    menu[8].price = 2;

    menu[9].item = "Soda";
    menu[9].price = 2;
}

// Search through the menu array to find an item's cost
float get_cost(char *item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcasecmp(menu[i].item, item) == 0)
        {
            return menu[i].price;
        }
    }
    return 0.0;
}
