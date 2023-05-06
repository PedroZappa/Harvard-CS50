// (Hans Peter) Luhn's Algorithm [aka. Mod 10 Check]
// Validates a credit card number (syntatically)
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Function Prototypes
int count_digits(long credit_card);
int luhn_check(long credit_card);
int multi_sum(int last_digit);
bool is_valid_amex(long credit_card, int num_digits);
bool is_valid_master(long credit_card, int num_digits);
bool is_valid_visa(long credit_card, int num_digits);

int main(void)
{
    // Get Credit Card Number
    long credit_card = get_long("Credit Card: ");

    // Luhn's Algorithm
    int sum_every_other_digit = luhn_check(credit_card);

    // Get Number of Digits
    int num_digits = count_digits(credit_card);

    // Check if valid AMERICAN EXPRESS
    bool amex = is_valid_amex(credit_card, num_digits);
    // check if valid MASTERCARD
    bool master = is_valid_master(credit_card, num_digits);
    // check if valid VISA
    bool visa = is_valid_visa(credit_card, num_digits);

    // Print credit_card validity check results
    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

}

bool is_valid_amex(long credit_card, int num_digits)
{
    // Get first two digits of credit_card
    int first_two_digits = credit_card / pow(10, num_digits - 2);
    if ((num_digits == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_valid_master(long credit_card, int num_digits)
{
    // Get first two digits of credit_card
    int first_two_digits = credit_card / pow(10, num_digits - 2);
    if ((num_digits == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_valid_visa(long credit_card, int num_digits)
{
    if (num_digits == 13)
    {
        // Get first digit of credit_card
        int first_digit = credit_card / pow(10, num_digits - 1);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (num_digits == 16)
    {
        // Get first digit of credit_card
        int first_digit = credit_card / pow(10, num_digits - 1);
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}


int count_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count++; // Increment count
        // Remove last digit from credit_card
        credit_card /= 10;
    }
    return count;
}

int luhn_check(long credit_card)
{
    int sum = 0;
    // is isAlterDigit is false to skip first digit read;
    bool isAlterDigit = false;
    // Loop until # < 0
    while (credit_card > 0)
    {
        // if isAlterDigit is true
        if (isAlterDigit == true)
        {
            // Multiply last_digit and add the product to sum;
            // Get last digit of credit_card
            int last_digit = credit_card % 10;
            // Multiply every other digit by 2
            int product = multi_sum(last_digit);
            // Add product to sum
            sum += product;
        }
        else
        {
            // Get last digit of credit_card
            int last_digit = credit_card % 10;
            // Add last_digit to sum;
            sum += last_digit;
        }
        // Toggle isAlterDigit
        isAlterDigit = !isAlterDigit;
        // Remove last digit from credit_card
        credit_card /= 10;
    }
    return sum;
}

int multi_sum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum += last_digit_multiply;
        multiply /= 10;
    }
    return sum;
}