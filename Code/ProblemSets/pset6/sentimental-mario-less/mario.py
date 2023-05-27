# Print half-pyramid using #
from cs50 import get_int


def main():
    # Get user input height
    height = get_height()

    # Print half-pyramid
    print_half_pyramid(height)


# Get user height
def get_height():
    # while input not between 1 and 8
    while True:
        try:
            # Get user input
            height = get_int("Height: ")
            # must be a positive integer between 1 and 8, inclusive
            if height < 1 or height > 8:
                print("Height must be an integer between 1 and 8.")
            if height >= 1 and height <= 8:
                break
        except ValueError:
            print("ValueError: Height must be an integer between 1 and 8.")
    return height


def print_half_pyramid(height):
    space = height

    # print pyramid
    for i in range(height):
        # handle height = 1
        if height == 1:
            print("#")
            break
        # print space
        for _ in range(space - 1):
            print(" ", end="")
        # print i + 1 #s
        for hash in range(i + 1):
            print("#", end="")
        # print \n
        print("")
        space -= 1


# Run
main()