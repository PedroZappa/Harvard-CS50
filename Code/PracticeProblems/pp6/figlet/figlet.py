import sys, random
from pyfiglet import Figlet

isRandom = None
figlet = Figlet()
fonts = figlet.getFonts()

# Check for arguments
if len(sys.argv) == 1:
    # Pick random font
    isRandom = True
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    # set user input font
    isRandom = False
else:
    print("Invalid usage.")
    sys.exit(1)

# Set Figlet options
if isRandom == False:
    try:
        # Set user defined font
        font = sys.argv[2]
        figlet.setFont(font=font)
    except:
        # handle invalid font
        print("Invalid font.")
        sys.exit(1)
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
