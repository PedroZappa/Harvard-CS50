import sys, random
from pyfiglet import Figlet

figlet = Figlet()
isRandom = None

# Check number arguments
if len(sys.argv) == 1:
    isRandom = True
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    isRandom = False
else:
    print("Invalid usage.")
    sys.exit(1)

if isRandom == False:
    try:
        figlet.setFont(font=sys.argv[2])
    except:
        print("Invalid usage.")
        sys.exit()
else:
    font = random.choice(figlet.getFonts())

# Get user input
text = input("Input: ")    
print(f"Output:\n\n{figlet.renderText(text)}")