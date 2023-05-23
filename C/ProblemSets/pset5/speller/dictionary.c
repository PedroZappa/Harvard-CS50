// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hashtable
node *table[N];

// Variable
unsigned int hash_val;
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
// Open dictionary else return NULL
bool check(const char *word)
{
    // TODO
    // Take input & output a number of a bucket in hashtable
    hash_val = hash(word);
    node* cursor = table[hash_val];

    // Traverse list
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int total = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open Dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open %s\n", dictionary);
        return false;
    }

    // Loading Dictionary into hashtable
    // word buffer
    char word[LENGTH + 1];
    // while words left to read on file
    while (fscanf(file, "%s", word) != EOF)
    {
        // malloc new node for each new word
        node* nn = malloc(sizeof(node));
        if (nn == NULL)
        {
            unload();
            return false;
        }

        // Copy and set word into node
        strcpy(nn->word, word);
        // Get hash value for word
        hash_val = hash(word);
        // Set nn->next to the table's hash_val
        nn->next = table[hash_val];
        table[hash_val] = nn;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // Create cursor pointing to the first node
        node *cursor = table[i];
        while (cursor)
        {
            // Create tmp pointer
            node *tmp = cursor;
            // Move cursor and free tmp
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
