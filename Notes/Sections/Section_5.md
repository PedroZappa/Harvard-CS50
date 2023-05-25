Section_5: Data Structures
=======================

#### Return to [`CS50x`](/README.md)

=======================

## Table o'Contents

- [Scenario](#scenario)
- [Linked List](#linked-list)
- [Hash Table](#hash-table)
- [Tries](#tries)
- [Nodes](#nodes)
- [Creating a Linked List](#creating-a-linked-list)
- [Inserting Nodes](#inserting-nodes)
- [Inserting into a Linked List](#inserting-into-a-linked-list)
- [Unloading a Linked List](#unloading-a-linked-list)
- [Hashing](#hashing)

___

What are the key **`trade-offs`** between data structures we should consider in decisions about which to use?

What are some of the primary operations we should know how to do on a linked list?

How can we build our very own **`hash table`**?

___

## [Scenario](#scenario)

- Imagine you work for a company that has created a **`digital assistant`** running on a mobile device.

- Customer reports indicate **`people have trouble activating the assistant`** with its "`wake word`".

- Your team has been asked to ensure the voice assistant can be **`awoken with a greater variety of words.`**

- What **`data structure`** would you propose the team build to store these words?

___

When choosing a `Data Structure`, we should consider the following areas/tasks, in order of priority:

```sh
If you want to give the end user the ability to search faster and more efficiently, you should consider the following areas/tasks, in order of priority:
```

1. Search
2. Insertion
3. Deletion

```sh
If you want to give the end user the ability to add new wake words, you should consider the following areas/tasks, in order of priority:
```

1. Insertion
2. Search
3. Deletion

___

## [Linked List](#linked-list)

![Linked List Example](/IMG/Sect5/Sect5_0.png)

`Linked lists` would be a good choice if we want to `Insert` data.

- All it takes to insert into a linked list is simply to make a new node and put it at the very front (constant time operation).

- `Deletion` and `Search` would be slow;

___

## [Hash Table](#hash-table)

![Hash Table Example](/IMG/Sect5/Sect5_1.png)

- `Search` and `Inserting` would be faster using a `Hash Table`;

- The downside of using a `hash tables` is that they take a lot more memory in order to make our lookup (search) really fast;

## [Tries](#tries)

![Tries Example](/IMG/Sect5/Sect5_2.png)

- `Search` and `Insertion` are very fast using `Tries`;

- Like with `Hash Tables`, `Tries` take a lot more memory;

___

## [Nodes](#nodes)

Below is the template for a simple `node`:

```c
typedef struct node
{
    string phrase;
    struct node *next;
}
node;
```

- The attribute `node *next` is a pointer to the struct `node`.

| Struct  |   Node |
--------|---------|
 phrase |   "Hi"  |
  next  |  0x123  |

- We could also have an attribute called `before` that we could theoretically point to the previous node.

___

## [Creating a Linked List](#creating-a-linked-list)

- Create a new `node` and set to `NULL`;

```c
node *list = NULL;
```

- To add data to the linked list, we need to make a new `node`;

- Create a new `node` (pointer) by calling `malloc`;

![Creating a Linked List Example](/IMG/Sect5/Sect5_5.png)

- To add data to the `node` we can use this new `arrow syntax`;

![Arrow Syntax Example](/IMG/Sect5/Sect5_6.png)

- `n->phrase` is saying: start with `n` pointer, follow it into its structure, go to the `phrase` attribute and set it to `"Hi!"`;

- Now we also need to include the next portion (`node`) of our `linked list`;

![Creating a Linked List Example](/IMG/Sect5/Sect5_7.png)

- `n->next` is saying: follow `n`s pointer to our node structure, go to the `next` attribute and set it to `NULL`;

- There is one more step, we have our `node` but our `list` is still empty;

![Creating a Linked List Example](/IMG/Sect5/Sect5_8.png)


if instead of `list = n` we had set `n = list`, our program would suffer a `memory leak` and we would loose the address of `list`;

___

## [Inserting Nodes](#inserting-nodes)

- How do we keep adding (inserting) more nodes?

- Let's say we want to create a new `node` called `n`, using `malloc` to get some space in memory and create it;

![Inserting Nodes Example](/IMG/Sect5/Sect5_10.png)

- To create a quick `insertion` we have to add a `node` at the beginning of the linked list, and make sure this `node` points to the current first `node` in our list;

- First give the new `node` a `phrase` attribute:

![Inserting Nodes Example](/IMG/Sect5/Sect5_11.png)

- Then we should point `n` to `list`:

![Inserting Nodes Example](/IMG/Sect5/Sect5_12.png)

- Notice: `list` is still pointing to the second `node`;

- To make sure that the `list` includes our second `node` we should point `list` to `n`:

![Inserting Nodes Example](/IMG/Sect5/Sect5_14.png)

- Now `list` gets the value `n`, meaning `list` now points to this new first node;

- Now we have a `linked list` of more than one `node`;

## [Inserting into a Linked List](#inserting-into-a-linked-list)

Starting below that TODO, implement code to add a node to the linked list. 

Ensure that list always points to the head of the linked list. 

Also ensure your new node contains a phrase.

```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

// to free memory as we go
bool unload(node *list);
// to visualize changes in the linked list
void visualizer(node *list);

int main(void)
{
    // At the beginning list is NULL
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node at the front of list
        // Create space in memory to store new node;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Failed to allocate memory.\n");
            return 1;
        }
        // Add phrase 
        n->phrase = phrase;
        // Update node.next address to point to the head of the list
        n->next = list;

        list = n;
        // The last node we add becomes the first in our linked list

        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    unload(list);

    printf("Freed the list.\n");
    return 0;
}

bool unload(node *list)
{
    // TODO: Free all allocated nodes
    while (list != NULL) // while got nodes
    {
        node *ptr = list->next; //to avoid memory leak: save Pointer to next node
        free(list); // free memory
        list = ptr; // update list to point to next node
    }
    
    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
```

## [Unloading a Linked List](#unloading-a-linked-list)

- Full `Linked List`:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_15.png)

![Unloading a Linked List Example](/IMG/Sect5/Sect5_17.png)

- if we `free(list)` (the `head of the list`) we loose the other nodes; the only reason we know where that next `node` is located is because it's in the next portion of our very first `node`.

- Instead let's make a new `pointer` that will point to whatever the `head of our list` is pointing to (next `node`).

![Unloading a Linked List Example](/IMG/Sect5/Sect5_19.png)

- Now we could safely `free(list)`:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_20.png)

- `*ptr` is still pointing to the rest of our list, so that we don't lose the location in memory of the other `nodes`.

- Now we want to actually get back to the `head of our list` and make sure that we're actually kind of moving forward.

- So what we'll do is say that `list` gets the value for `ptr`:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_22.png)

- Now the `head of our list` points to whatever `*ptr` points to.

- We could also do this in a loop, where pointer will get list arrow next again:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_24.png)

- `ptr` will hold a `NULL` value;

- Moving on, if we `free(list)`:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_25.png)

- `List` gets `pointer`:

![Unloading a Linked List Example](/IMG/Sect5/Sect5_26.png)

- We've gone from the very first node to our very last node;

- We've ended when `list` equals `NULL`, when there's nothing left to free;

___

## [Hashing](#hashing)

- This idea of a `Linked List` where we store different kind of activation words for our voice assistant;

![Hashing Example](/IMG/Sect5/Sect5_27.png)

- We could try to make sure we can access certain parts of this _`Linked List`_ faster; for that we could use a _`Hash Table`_;

![Hashing Example](/IMG/Sect5/Sect5_28.png)

- We have an array of `buckets` on the left side of the screen, where a `bucket` might be a `letter of the alphabet`;

- There are other ways to assign these phrases to a `bucket`, but for now lets focus on this `alphabetical hash`;

- To know where a `bucket` is, we must find out the `index` of the `bucket` in the `hash table`;

![Hashing Example](/IMG/Sect5/Sect5_29.png)

- In those `indexes` we can add in our `Linked Lists`;

- Given a new phrase, in order to figure out which `bucket` it should go into, we can use a `hash function`;

![Hashing Example](/IMG/Sect5/Sect5_30.png)

___

The code below is an example of a `Hash Function`:

- It makes sure we have different `linked lists` depending on the very
first letter of the phrase we add.

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

// Array of Pointers to Node aka. Table (w/ 26 buckets)
node *table[26];

// figure out where these new phrases should go.
int hash(string phrase);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }
}

// TODO: return an index, 0-25, for a given phrase
int hash(string phrase)
{
    // toupper() standardizes input: lowercase and uppercase will hash to the same value;
    // "- 'A'" makes sure that every index is going to be inside the length value of my table. I won't get any indexes that are out of bounds for this list.
    return toupper(phrase[0]) - 'A';
    // A = 65
    // A - A = 0
    // B - A = 1
    // ...
    // Z - A = 25
}
```

## A good hash function:

- Always gives you the `same value` for the `same input`;

- Produces an `even distribution` across `buckets`;

- Uses all `buckets`;

___
___

=======================

#### Return to [`CS50x`](/README.md)

=======================