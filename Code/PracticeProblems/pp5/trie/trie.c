// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <ctype.h> // isspace()
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKYELLOW "\e[38;2;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[38;2;255;0;0m"
#define GREEN "\e[38;2;0;255;0m"
#define YELLOW "\e[38;2;255;255;0m"
#define CYAN "\e[38;2;0;255;255m"
#define RESET "\e[0m"

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);
char* get_string();

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Titles
    printf(BLACKWHITE "Dog Names Dictionary " RESET "\n");
    // Check for command line args
    if (argc != 2)
    {
        printf(RED "Usage: " RESET GREEN "./trie infile\n" RESET);
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf(RED "Error opening file!\n" RESET);
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return 1;
    }
    // Initialize trie root
    root->is_word = false;
    // Loop through letters in the alphabet
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        // set root's children memeber to NULL
        root->children[i] = NULL;
    }

    // Add words to the trie from file
    while (fscanf(infile, "%s", name) == 1) 
    {
        // Init cursor pointing at root
        node *cursor = root;
        // Loop through letters in name
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            // Store alphabet index of current letter
            // a = 0; b = 1; ...; z = 25; 
            int index = tolower(name[i]) - 'a';
            // if cursor is NOT pointing at NULL
            if (cursor->children[index] == NULL)
            {
                // Init new node
                node *new = malloc(sizeof(node));
                // Init new node's members
                new->is_word = false;
                // Init each element in new node's array of pointers (children)
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                // Assign new node to the 'index'th element in cursor's children array
                cursor->children[index] = new;
            }
            // Go to (point at) node which we may have just been made
            cursor = cursor->children[index];
        }
        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    // Check if input str is valid
    if (check(get_string()))
    {
        printf(GREEN "Found!\n" RESET);
    }
    else
    {
        printf(RED "Dog Name Not Found.\n" RESET);
    }

    if (!unload())
    {
        printf(RED "Problem freeing memory!\n" RESET);
        return 1;
    }
    // Close files
    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char* word)
{
    // Point cursor to root
    node *cursor = root;
    // Loop through each letter in word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Get alphabet index of current letter
        int index = tolower(word[i]) - 'a';
        // if index not between 0 and 25
        if (index < 0 || index >= SIZE_OF_ALPHABET)
        {
            return false;
        }
        // if current letter is not null
        if (cursor->children[index] != NULL)
        {
            cursor = cursor->children[index];
        }
        else
        {
            return false;
        }
    }
    // Return is_word property
    return cursor->is_word;
}

// get user string
char* get_string()
{
    // Accept only valid input
    char *str = malloc(MAXCHAR);
    if (str == NULL)
    {
        printf(RED "Problem allocating memory!\n" RESET);
        return 1;
    }
    do
    {
        printf(BLACKBRIGHT "Enter a name for checking: " RESET);
        fgets(str, MAXCHAR, stdin);
        // Remove newline char
        str[strcspn(str, "\n")] = '\0';
        // Strip leading whitespaces
        while (isspace((unsigned char)str[0]))
        {
            memmove(str, str + 1, strlen(str));
        }
        // Strip trailing whitespaces
        char *end = str + strlen(str) - 1; // Get the end of the string
        while (end >= str && isspace((unsigned char)*end))
        {
            *end = '\0';
            *end--;
        }
    }
    while (str[0] == '\0');
    return str;
}


// Unload trie from memory
bool unload(void)
{
    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node* current)
{
    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }
    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}
