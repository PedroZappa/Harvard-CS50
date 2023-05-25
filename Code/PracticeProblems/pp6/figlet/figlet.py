import sys, random
from pyfiglet import Figlet

isRandom = None
figlet = Figlet()
fonts = figlet.getFonts()

# Usage Guide Printer
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

# Check arguments / set mode
## Random Mode
if len(sys.argv) == 1:
    # Pick random font
    isRandom = True
# Check flags
## Dictionary Mode
elif sys.argv[1] == "-d" or sys.argv[1] == "--dict":
    # Print font list
    print("Dictionary of Figlet Fonts:\n")
    
    cols = 10
    rows = len(fonts) // cols + (1 if len(fonts) % cols > 0 else 0)
    for row in range(rows):
        for col in range(cols):
            index = row * cols + col
            if index < len(fonts):
                print(f'{fonts[index]: <15}', end="")
        print()
    exit(1)
## Usage Guide Help Mode
elif sys.argv[1] == "-h" or sys.argv[1] == "--help":
    print_help()
    exit(2)
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    # set user input font
    isRandom = False
else:
    print("Invalid usage.\nRun with -h for help.")
    sys.exit(3)

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
    # Get random font
    font = random.choice(figlet.getFonts())
    # set random font
    figlet.setFont(font=font)
    
# Get user input
text = input("Input: ")

# Print font meta
print(f"\nFont: {font}")
# Print font
print(f"Output:\n\n{figlet.renderText(text)}")
