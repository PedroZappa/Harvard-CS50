# Felipe's Taqueria Menu
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    # Greet user
    print("Welcome to Felipe's Taqueria!")
    print("Please enter your order: ")

    # create a list to store user order
    order = []

    # Get user order
    get_order(order)

    # Calculate Price for user order
    price = get_price(order, menu)

    # Print out user order price
    print(f"\nTotal: ${price:.2f}")


def get_order(order):
    # Get user order
    while True:
        try:
            # Prompt user for item
            order_item = input("Item: ").strip()
            # Convert to titlecase
            order_item_title = order_item.title()
            # Check if order_item is in menu
            found = False
            for menu_item in menu:
                if order_item_title == menu_item.title():
                    # Append item to order
                    order.append(menu_item)
                    found = True
                    break
            if not found:
                print("Please enter a valid item")
        # exit try when user ctrl+d
        except EOFError:
            break


def get_price(order, menu):
    # Calculate Price for user order
    price = 0
    for item in order:
        price += menu[item]
    return price


main()