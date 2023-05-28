from sys import argv, exit
import csv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        # Print usage if user doesn't input 3 args
        print('Usage: python dna.py file.csv file.txt')
        exit()

    # TODO: Read database file into a variable
    with open(argv[1], 'r') as csv_file:
        # Create csv DictReader
        file_reader = csv.DictReader(csv_file)
        # Read csv into memory
        csv_file = [row for row in file_reader]

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], 'r') as seq_file:
        dna_seq = seq_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # loop through first row of csv file to extract headers
    str_count = dict()
    for key in csv_file[0].keys():
        # skip first column header
        if key == 'name':
            continue
        # calculate longest match
        str_count[key] = longest_match(dna_seq, key)

    # TODO: Check database for matching profiles
    # Loop through rows of database
    for row in csv_file:
        # Loop through values in a row
        for value in row.keys():
            if value == 'name':
                # skips first value on csv
                continue
            if int(row[value]) != str_count[value]:
                break
        else:
            print(row["name"])
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
