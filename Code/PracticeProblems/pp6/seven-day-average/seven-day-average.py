import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Store last timespan days of new cases by state to read
    timespan = int(input("Timespan to read: "))
    
    # Construct # day lists of new cases for each states
    new_cases = calculate(reader, timespan)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\n{timespan}-Day Averages")

    # Print out #-day averages for this week vs last week
    comparative_averages(new_cases, states, timespan)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader, timespan):
    # Create a dictionary to store 14 most recent days of newcases by state
    new_cases = dict()
    prev_cases = dict()

    # Loop through each line of NYTimes db
    for row in reader:
        # Get values from line of csv file
        state = row["state"]
        date = row["date"]
        cases = int(row["cases"])

        # check if state already exists
        if state not in prev_cases:
            # Add state to dictionary
            prev_cases[state] = cases
            # store new cases for each state
            new_cases[state] = []
        else:
            # the data is cumulative, each day’s new cases must be calculated by subtracting the previous day’s cases
            new_case = cases - prev_cases[state]
            prev_cases[state] = cases

            # Check if state already exists in new_cases dict()
            if state not in new_cases:
                new_cases[state] = []
            # Check if len(new_cases[state]) > timespan : remove first element
            if len(new_cases[state]) >= timespan:
                new_cases[state].pop(0)
            # Append each new day's data to end of list
            new_cases[state].append(cases)
    # return new_cases
    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states, timespan):
    # Loop through states
    for state in states:
        # Get first 7 elements from new_cases
        prev_cases = new_cases[state][:7]
        # Get last 7 elements from new_cases
        curr_cases = new_cases[state][7:]
        # Calculate current and previous week's average
        avg_curr = round(sum(curr_cases) / len(curr_cases))
        avg_prev = round(sum(prev_cases) / len(prev_cases))
        # Difference between current and previous week's average
        diff = avg_curr - avg_prev

        if diff > 0:
            txt = "an increase"
        else:
            txt = "a decrease"

        # Percentage of Decrease/Increase
        try:
            percent = (diff / avg_prev) * 100
        except ZeroDivisionError:
            # Handle zero division error
            raise ZeroDivisionError("Error: Dividing by zero")

    for state in states:
        print(f"{state} had an average of {avg_curr} cases in the last {timespan} days and {txt} of {percent:.2f}% in relation to the previous {timespan} days.")


main()