# Get greeting from user
greeting = str(input("Greet me please: ")).strip().lower()

# if greeting starts with hello print $0
# elif greeting starts with hint $20
# else print $100
if greeting.startswith("hello"):
    print("$0")
elif greeting.startswith("h"):
    print("$20")
else:
    print("$100")
