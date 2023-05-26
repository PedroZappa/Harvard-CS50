import sys, random
from pyfiglet import Figlet
from colored import fg, bg, attr

isRandom = True
isColor = True
# color = {fg('purple')}
figlet = Figlet()
fonts = figlet.getFonts()

def main():
    # Check arguments & flags / set execution mode
    ## Random Mode
    if len(sys.argv) == 1:
        # Pick random font
        isRandom = True
    ## Dictionary Mode
    elif sys.argv[1] == "-d" or sys.argv[1] == "--dict":
        print_dict()
        exit(1)
    ## Usage Guide Help Mode
    elif sys.argv[1] == "-h" or sys.argv[1] == "--help":
        print_help()
        exit(2)
    ## User defined font Mode
    elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
        # set user input font
        isRandom = False
    ## User defined color Mode
    elif len(sys.argv) == 4 and (sys.argv[3] == "-c" or sys.argv[1] == "--color"):
        # set user input color
        isColor = True
    ## User input color code
    elif len(sys.argv) == 5:
        # set user input color
        isColor = True
    else:
        print("Invalid usage.\nRun with -h for help.")
        sys.exit(3)
        
    # Set font
    font = set_font()
    
    # Get user input
    text = input("Input: ")
    
    # Print to the terminal
    print_font(text, font)
    exit(0)


def print_dict():
    # Print font list
        print(f"{fg(random.randint(0, 255))}Dictionary of Figlet Fonts:\n")
        cols = 10
        rows = len(fonts) // cols + (1 if len(fonts) % cols > 0 else 0)
        for row in range(rows):
            for col in range(cols):
                index = row * cols + col
                if index < len(fonts):
                    print(f'{fg(random.randint(0, 255))}{fonts[index]: <15}', end="")
            print("")


def print_help():
    print("Zedro's Figlet Writer Usage Guide: ||")
    print("                                   ||")
    print("Prints the list of valid fonts     ||")
    print("./figlet.py -dict                  ||")
    print("            -d                     ||")
    print("                                   ||")
    print("Set user defined font              ||")
    print("./figlet.py --font font_name       ||")
    print("            -f font_name           ||")
    print("                                   ||")
    print("Print this usage guide             ||")
    print("./figlet.py --help                 ||")
    print("            -h                     ||")


def set_font():
    # Set Figlet options
    if isRandom == False:
        try:
            # Set user defined font
            font = sys.argv[2]
            figlet.setFont(font=font)
        except:
            # handle invalid font
            print("Invalid font.\nRun with -h for help.")
            sys.exit(4)
    else:
        isRandom == True
        # Get random font
        font = random.choice(figlet.getFonts())
        # set random font
        figlet.setFont(font=font)
    return font


def print_font(text, font):
    # Print font meta
    print(f"Font: {font}")
    # Print font
    # if random is true print random color
    if isRandom is True:
        print("Output:\n\n")
        print(f"{fg(random.randint(0, 255))}{figlet.renderText(text)}")
    else:
        if len(argv) == 3:
            print(f"{fg(random.randint(0, 255))}_Output:\n\n{figlet.renderText(text)}")
        else:
            print(f"_Output:\n\n{figlet.renderText(text)}")


# Run
main()