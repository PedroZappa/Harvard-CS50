// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
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