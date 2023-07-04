// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value
#include <stdio.h>

// Declare function prototype for 'half'
float half(float bill, float tax, int tip);

int main(void)
{
    // Get user inputs
    float bill_amount;
    printf("Bill before tax and tip: ");
    scanf("%f", &bill_amount);

    float tax_percent;
    printf("Sale Tax Percent: ");
    scanf("%f", &tax_percent);

    int tip_percent;
    printf("Tip percent: ");
    scanf("%d", &tip_percent);

    // ANSI escape sequences to color output
    const char *cyan = "\033[36m";
    const char *reset = "\033[0m";

    // Print the total amount owed, calculated by calling the 'half' function with the user's inputs
    printf(
        "You will owe %s$%.2f%s each!\n", 
        cyan, half(bill_amount, tax_percent, tip_percent), reset
    );
}

// Function definition for 'half'
float half(float bill, float tax, int tip)
{
    // Convert tax and tip percentages to decimal values
    float tax_dec = tax / 100.0;
    float tip_dec = tip / 100.0;

    // Calculate tax amount and add it to the bill amount
    float tax_amount = bill * tax_dec;
    float bill_with_tax = bill + tax_amount;

    // Calculate tip amount and add it to the bill_with_tax amount
    float tip_amount = bill_with_tax * tip_dec;
    float total_amount = bill_with_tax + tip_amount;

    // Return half of the total_amount
    return total_amount / 2;
}