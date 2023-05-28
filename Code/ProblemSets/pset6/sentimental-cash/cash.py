from cs50 import get_float


def main():
    # Ask how many cents the customer is owed
    change = get_cents()
    cents = change

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = round(cents - quarters * 0.25, 2)

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = round(cents - dimes * 0.10, 2)

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = round(cents - nickels * 0.05, 2)

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = round(cents - pennies * 0.01, 2)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print Coins
    print(f"{coins}")


# Ask user for change
def get_cents():
    # if negative integer, re-prompt
    while True:
        try:
            cents = get_float("Change owed: ")
            # If input valid break
            if cents > 0.00:
                break
            # check if input is negative
            if cents <= 0.00:
                print("Input a positive integer please.")
        except ValueError:
            print("ValueError: Input a positive integer please.")
    return cents


def calculate_quarters(cents):
    quarter = 0.25
    quarters = 0

    # if cents < 0.25 return 0
    if cents < quarter:
        return quarters
    else:
        while cents >= quarter:
            # Subtract quarters and count coins
            cents -= quarter
            quarters += 1
    return quarters


def calculate_dimes(cents):
    dime = 0.10
    dimes = 0

    # if cents < 0.10 return 0
    if cents < dime:
        return dimes
    else:
        while cents >= dime:
            # Subtract dimes and count coins
            cents -= dime
            dimes += 1
    return dimes


def calculate_nickels(cents):
    nickel = 0.05
    nickels = 0

    # if cents < nickel return 0
    if cents < nickel:
        return nickels
    else:
        while cents >= nickel:
            # Subtract nickels and count coins
            cents -= nickel
            nickels += 1
    return nickels


def calculate_pennies(cents):
    pennie = 0.01
    pennies = 0

    # if cents < pennie return 0
    if cents < pennie:
        return pennies
    else:
        while cents >= pennie:
            # Subtract nickels and count coins
            cents -= pennie
            pennies += 1
    return pennies


# Run
main()