from cs50 import get_string


def main():
    # Ask user to type in text
    string = get_input()

    # count # letters / assume lowercase
    letter_count = count_letters(string)
    # count # words / assume lowercase
    word_count = count_words(string)
    # count # sentences / assume lowercase
    sentence_count = count_sentences(string)

    # calculate coleman liao
    cl_index = calc_liao(letter_count, word_count, sentence_count)

    # Print Grade
    if cl_index >= 16:
        print(f"\nGrade 16+")
    elif cl_index <= 1:
        print(f"\nBefore Grade 1")
    else:
        print(f"Grade {cl_index}")


def get_input():
    # GET user to type in text
    string = get_string("Text: ")

    return string


def count_letters(string):
    char_count = 0

    for char in string:
        if char.isalpha():
            char_count += 1

    return char_count


def count_words(string):
    word_count = 0

    for char in string:
        # Check for white-space
        if char.isspace():
            word_count += 1

    return word_count + 1


def count_sentences(string):
    sentence_count = 0
    punct = ['.', '!', '?']

    for char in string:
        # loop through punctuation to look out for
        for i in punct:
            if char == i:
                sentence_count += 1

    return 1 if sentence_count == 0 else sentence_count


def calc_liao(letter_count, word_count, sentence_count):
    # L = letter_count / word_count * 100 [ Letters per 100 Words ]
    L = letter_count / word_count * 100
    # S = sentence_count / word_count * 100 [ Sentences per 100
    S = sentence_count / word_count * 100

    # Calculate Coleman Liao index
    cl_index = round(0.0588 * L - 0.296 * S - 15.8)
    return cl_index


# Run
main()