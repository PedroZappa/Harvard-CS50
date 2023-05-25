<center>

[Shorts 5: Data Structures](https://cs50.harvard.edu/x/2023/weeks/5/)
=======================

#### ( Return to [`CS50x`](/README.md) )




## Table o'Contents

[Data Structures](#data-structures)

[Structures](#structures)

[Singly-Linked Lists](#singly-linked-lists)

[Doubly-Linked Lists](#doubly-linked-lists)

[Hash Tables](#hashtables)

[Tries](#tries)

[Queue](#queue)

[Stacks](#stacks)

</center>

___

## [Data Structures](#data-structures)

By this point we’ve now examined four different ways to store
`sets of data`:

- Arrays

- Linked lists

- Hash tables

- Tries

There are even some variations on these (`trees` and `heaps`, quite similar to `tries`, `stacks` and `queues` quite similar to `arrays` or `linked lists`, etc.) but this will generally cover most of what we’re looking at in `C`.

How do all of these `data structures` measure up? How do you
know which to choose for your situation?

Usually it’s a matter of weighing the `pros` against the `cons`.
Let’s consider some of the important metrics for each.

___

### Arrays

- `Insertion is bad` – lots of shifting to fit an element in the middle

- `Deletion is bad` – lots of shifting after removing an element

- `Lookup is great` – random access, constant time

- Relatively `easy to sort`

- Relatively `small size`-wise

- Stuck with a `fixed size`, no flexibility

___

### Linked lists

- `Insertion is easy` – just tack onto the front

- `Deletion is easy` – once you find the element

- `Lookup is bad` – have to rely on linear search

- `Relatively difficult to sort` – unless you’re willing to compromise on super-fast insertion and instead sort as you construct

- `Relatively small size`-wise (not as small as arrays)

___

### Hash Tables

- `Insertion is a two-step process` – hash, then add

- `Deletion is easy` – once you find the element

- `Lookup is on average better` than with linked lists because you have the benefit of a real-world constant factor

- `Not an ideal data structure if sorting is the goal` – just use an array

- Can run the gamut of size

___

### Tries

- `Insertion is complex` – a lot of dynamic memory allocation, but gets easier as you go

- `Deletion is easy` – just free a node

- `Lookup is fast` – not quite as fast as an array, but almost

- `Already sorted` – sorts as you build in almost all situations

- `Rapidly becomes huge`, even with very little data present, not great if space is at a premium

___

## [Structures](#structures)

- `Structures` provide a way to unify several variables of different types into a single, new variable type which can be assigned its own type name.

- We use structures (`structs`) to group together elements of a variety of `data types` that have a logical connection.

- Think of a structure like a “super-variable”.

```c
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};
```

Once we have defined a `structure`, which we typically do in separate `.h` files or atop our programs outside of any functions, we have effectively created a `new type`.

- That means we can create variables of that `type` using the familiar syntax.

- We can also access the various `fields` (also known as members) of the structure using the dot operator (`.`)

```c
// variable declaration
struct car mycar;

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);
mycar.odometer = 50505;
```

- `Structures`, like variables of all other `data types`, do not need to be created on the `stack`. We can dynamically allocate `structures` at run time if our program requires it.

- In order to access the fields of our `structures` in that situation, we first need to `dereference the pointer` to the `structure`, and then we can access its `fields`.

```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, “CS50”);
(*mycar).odometer = 50505;
```

- This is a little annoying. And so as you might expect, there’s a shorter way!

- The arrow operator (`->`) makes this process easier. It’s an operator that does two things `back-to-back`:

  - First, it `dereferences` the pointer on the left side of the operator.

  - Second, it `accesses` the field on the right side of the operator.

```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
mycar->year = 2011;
strcpy(mycar->plate, “CS50”);
mycar->odometer = 50505;
```

___

## [Singly-Linked Lists](#singly-linked-lists)


- So far in the course, we’ve only had one kind of data structure for representing collections of like values.

  - `structs`, recall, give us “containers” for holding variables of different `data types`, typically.

- `Arrays` are great for element lookup, but unless we want to insert at the very end of the array, inserting elements is quite costly – remember `insertion sort`?

- `Arrays` also suffer from a great `inflexibility` – what happens if we need a larger array than we thought?

- Through clever use of `pointers`, dynamic memory allocation, and `structs`, we can put those two pieces together to develop a new kind of `data structure` that gives us the ability to grow and shrink a collection of like values to fit our needs.

- We call this combination of elements, when used in this way, a `linked list`.

- A linked list _`node`_ is a special kind of `struct` with two members:

  - Data of some data type (`int`, `char`, `float`…)

  - A pointer to another node of the same type

- In this way, a set of nodes together can be thought of as forming a chain of elements that we can follow from beginning to end.

```c
// Because sllnode is a self referencial structure, 'struct sllist' is a temporary name used during the definition of sllnode

typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;
```

___

In order to work with `linked lists` effectively, there are a number of operations that we need to understand:

1. `Create a linked list` when it doesn’t already exist.

2. `Search` through a linked list to find an element.

3. `Insert` a new node into the linked list.

4. `Delete a single element` from a linked list.

5. `Delete an entire linked list`.

___

## 1. Create a linked list

```c
sllnode* create(VALUE val);
```

Steps involved:

a. Dynamically allocate space [ `malloc()` ] for a new `sllnode`.

b. Check to make sure we didn’t run `out of memory`.

c. `Initialize` the node’s `val` field.

d. `Initialize` the node’s `next` field.

e. `Return a pointer` to the newly created `sllnode`

```c
sllnode* new = create(6); // creates a new node initialized to 6
```

___

## 2. Search through a linked list to find an element

```c
bool find(sllnode* head, VALUE val);
```

Steps involved:

a. Create a `traversal pointer` pointing to the list’s head.

b. If the current node’s `val` field is what we’re looking for, report success.

c. If not, set the `traversal pointer` to the next `pointer` in the list and go back to step b.

d. If you’ve reached the end of the list, report failure.

```c
bool exists = find(list, 6);
```

<center>

## `Traversing Nodes`

</center>

![Traversal pointer](/IMG/Shorts5/Short5_3.png)
![Traversal pointer](/IMG/Shorts5/Short5_4.png)
![Traversal pointer](/IMG/Shorts5/Short5_5.png)

<center> 

[ And so on... ]

</center>
___

## 3. Insert a new node into the linked list

```c
sllnode* insert(sllnode* head, VALUE val);
```

a. Dynamically allocate space [ `malloc()` ] for a new `sllnode`.

b. Check to make sure we didn’t run `out of memory`.

c. Populate and insert the node `at the beginning of the linked list`.

d. Return a pointer to the new head of the linked list.

```c
list = insert(list, 12);
```

<center>

## `Linking a New Node`

</center>

![Insert](/IMG/Shorts5/Short5_6.png)
![Insert](/IMG/Shorts5/Short5_7.png)
![Insert](/IMG/Shorts5/Short5_8.png)
![Insert](/IMG/Shorts5/Short5_9.png)

- Pointing `list` to the `new node` causes a `memory leak`, and we loose track of the rest of the `nodes`.

- We always want to connect the `new node` into the list, before we take that important step of changing where the head of the linked list is.

- So we want to make sure that everything is chained together, before we move the pointer.

![Insert](/IMG/Shorts5/Short5_7.png)
![Insert](/IMG/Shorts5/Short5_10.png)
![Insert](/IMG/Shorts5/Short5_11.png)

`Which pointer should we move first? `

Should the “12” node be the new head of the linked list, since it now exists, or should we connect it to the list first?

This is one of the trickiest things with linked lists. Order matters!

___

## 4. Delete an entire linked list

```c
void destroy(sllnode* head);
```

a. If you’ve reached a null pointer, stop.

b. Delete `the rest of the list`.

c. Free the current node.

```c
destroy(list);
```

<center>

## `Stacking Deletion Calls`

![Insert](/IMG/Shorts5/Short5_12.png)
![Insert](/IMG/Shorts5/Short5_13.png)
![Insert](/IMG/Shorts5/Short5_14.png)

[ And so on... until ]

![Insert](/IMG/Shorts5/Short5_15.png)

## `Freeing Nodes`

![Insert](/IMG/Shorts5/Short5_16.png)
![Insert](/IMG/Shorts5/Short5_17.png)
![Insert](/IMG/Shorts5/Short5_18.png)
![Insert](/IMG/Shorts5/Short5_19.png)
![Insert](/IMG/Shorts5/Short5_20.png)
![Insert](/IMG/Shorts5/Short5_21.png)

</center>
___

In order to work with linked lists effectively, there are a number of operations that we need to understand:

1. Create a linked list when it doesn’t already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.

___

## [Doubly-Linked Lists](#doubly-linked-lists)

- `Singly-linked lists` really extend our ability to collect and organize data, but they suffer from a crucial limitation.
    
  - We can only ever move in one direction through the list.

- Consider the implication that would have for trying to delete a node.

- A `doubly-linked list`, by contrast, allows us to move `forward` and `backward` through the list, all by simply adding one extra pointer to our `struct` definition.

```c
typedef struct dllist
{
    VALUE val;
    struct dllist* prev;
    struct dllist* next;
}
dllnode;
```

In order to work with `linked lists` effectively, there are a number of operations that we need to understand:

1. `Create` a `linked list` when it doesn’t already exist.

2. `Search` through a `linked list` to find an element.

3. `Insert` a new node into the `linked list`.

    ```c
    dllnode* insert(dllnode* head, VALUE val);
    ```
    
    `a.` Dynamically allocate space for a new `dllnode`.
    
    `b.` Check to make sure we didn’t run out of memory.
    
    `c.` Populate and insert the node at the beginning of the linked list.
    
    `d.` Fix the `prev pointer` of the old head of the linked list.
    
    `e.` Return a pointer to the new head of the linked list.

```
Remember, we can never break the chain when rearranging the pointers.

Even if we need to have redundant pointers temporarily, that’s okay.
```

4. `Delete a single` element from a `linked list`.

    ```c
    void delete(dllnode* target);
    ```

    a. Fix the pointers of the surrounding nodes to “skip over” target.

    b. Free target.

5. `Delete` an entire `linked list`.

___

```c
list = insert(list, 12);
```

<center>

## `Inserting into a Linked List`

![Insert](/IMG/Shorts5/Short5_22.png)
![Insert](/IMG/Shorts5/Short5_23.png)
![Insert](/IMG/Shorts5/Short5_24.png)
![Insert](/IMG/Shorts5/Short5_25.png)
![Insert](/IMG/Shorts5/Short5_26.png)
![Insert](/IMG/Shorts5/Short5_27.png)
![Insert](/IMG/Shorts5/Short5_28.png)

## `Deleting Nodes from a Linked List`

</center>

```c
delete(x);
```

<center>

![Insert](/IMG/Shorts5/Short5_29.png)
![Insert](/IMG/Shorts5/Short5_30.png)
![Insert](/IMG/Shorts5/Short5_31.png)
![Insert](/IMG/Shorts5/Short5_32.png)
![Insert](/IMG/Shorts5/Short5_33.png)

```txt
This is a general case for a node that is in the middle. There are a couple of extra caveats that you need to consider when you're deleting the very beginning of the list or the very end of the list.
```

</center>

___

- `Linked lists`, of both the singly- and doubly-linked varieties, support extremely efficient insertion and deletion of elements.

  - In fact, these operations can be done in `constant time`.

- What’s the downside? Remember how we had to find an element? We’ve lost the ability to randomly-access list elements.

  - Accessing a desired element may now take `linear time`.

___

## [Hash Tables](#hashtables)

- `Hash tables` combine the `random access` ability of an `array` with the `dynamism` of a `linked list`.

- This means (assuming we define our `hash table` well):
  
  - `Insertion` can start to tend toward `Θ(1)`;
  
  - `Deletion` can start to tend toward `Θ(1)`;
  
  - `Lookup` can start to tend toward `Θ(1)`;

- We’re gaining the advantages of both types of `data structure`, while mitigating the disadvantages.

___

- To get this performance upgrade, we create a new structure whereby when we insert data into the structure, the data itself gives us a clue about where we will find the data, should we need to later look it up.

- The trade off is that `hash tables` are not great at ordering o sorting data, but if we don’t care about that, then we’re goo to go!

___

- A `hash table` amounts to a combination of two things with which we’re quite familiar.

  - First, a `hash function`, which returns an nonnegative integer value called a hash code.

  - Second, an `array` capable of storing data of the type we wish to place into the data structure.

- The idea is that we run our data through the `hash function`, and then store the data in the element of the `array` represented by the returned `hash code`

```c
// Initialize hash table with 10 buckets
string hashtable[10];

// calculte hash value for x
int x = hash(“John”); // x is now 4

// lookup x in the hash table
hashtable[x] = “John”;

// calculte hash value for y
int y = hash(“Paul”); // y is now 6

// lookup y in the hash table
hashtable[y] = “Paul”;

// calculte hash value for z
int z = hash(“Ringo”); // z is now 6
```

![Hash Table](/IMG/Shorts5/Short5_0.png)

How to define a `hash function`? Really no limit to the number of possible `hash functions`.

- A good `hash function` should:

  - Use only the data being hashed
  
  - Use all of the data being hashed
  
  - Be deterministic
  
  - Uniformly distribute data
  
  - Generate very different hash codes for very similar data

```c
// Hash Functon (Not particularly great)
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != ‘\0’; j++)
    {
        sum += str[j];
    }
    return sum % HASH_MAX;
}

// str[j] != ‘\0’; 
// An alternative to strlen()
```

## Hash Table `Collisions`

- A `collision` occurs when two pieces of data, when run through the `hash function`, yield the same hash code.

- Presumably we want to store both pieces of data in the `hash table`, so we shouldn’t simply overwrite the data that happened to be placed in there first.

- We need to find a way to get both elements into the `hash table` while trying to preserve quick insertion and lookup.

___

### Resolving Collisions: _`Linear Probing`_

- In this method, if we have a `collision`, we try to place the data in the next consecutive element in the array (wrapping around to the beginning if necessary) until we find a vacancy.

- That way, if we don’t find what we’re looking for in the first location, at least hopefully the element is somewhere nearby.

![Short5_1](/IMG/Shorts5/Short5_1.png)

- `Linear probing` is subject to a problem called `clustering`. Once there’s a miss, two adjacent cells will contain data, making it more likely in the future that the cluster will grow.

- Even if we switch to another probing technique, we’re still limited. We can only store as much data as we have locations in our array.

___

### Resolving Collisions: _`Chaining`_

- Let’s start to pull it all together.

- What if instead of each element of the array holding just one piece of data, it held multiple pieces of data?

- If each element of the array is a pointer to the head of a linked list, then multiple pieces of data can yield the same hash code and we’ll be able to store it all!

- We’ve eliminated `clustering`.

- We know from experience with `linked lists` that insertion (and creation, if necessary) into a linked list is an `O(1)` operation.

- For `lookup`, we only need to search through what is hopefully a small list, since we’re distributing what would otherwise be one huge list across `n` lists.

```c
node* hashtable[10];

hash(“Joey”); returns 6
hash(“Ross”); returns 2
hash(“Rachel”); returns 4
hash(“Phoebe”); returns 6
```

![Short5_1](/IMG/Shorts5/Short5_2.png)

___

## [Tries](#tries)

We have seen a few data structures that handle the mapping of `key-value` pairs.

  - `Arrays`: The key is the element index, the value is the data at that location.

  - `Hash tables`: The key is the hash code of the data, the value is a linked list of data hashing to that hash code.

What about a slightly different kind of data structure where the key is guaranteed to be unique, and the value could be as simple as a Boolean that tells you whether the data exists in the structure?

___

`Tries` combine structures and pointers together to store data in an interesting way.

- The data to be searched for in the trie is now a roadmap. 
  - If you can follow the map from beginning to end, the data exists in the trie.
  - If you can’t, it doesn’t.

- Unlike with a `hash table`, there are `no collisions`, and no two pieces of data (unless they are identical) have the same path.

___

- Let’s map `key-value` pairs where the keys are four-digit years `(YYYY)` and the values are names of universities founded during those years.

- In a `trie`, the paths from a central `root` node to a `leaf` node (where the school names would be), would be labeled with digits of the year.

- Each node on the path from `root` to `leaf` could have 10 `pointers`
emanating from it, one for each `digit`.

___

<center>

## _`Insert`_

</center>


- To `insert` an element into the `trie`, simply build the correct path from the `root` to the `leaf`.

```c
typedef struct _trie 
{ 
    char university[20]; 
    struct _trie* paths[10]; 
} 
trie;
```

<center>

![Short5_34](/IMG/Shorts5/Short5_34.png)

```txt
Insert “Harvard”, founded 1636
```

![Short5_35](/IMG/Shorts5/Short5_35.png)
![Short5_36](/IMG/Shorts5/Short5_36.png)
![Short5_37](/IMG/Shorts5/Short5_37.png)

```txt
Insert “Yale”, founded 1701
```

![Short5_38](/IMG/Shorts5/Short5_38.png)
![Short5_39](/IMG/Shorts5/Short5_39.png)

```txt
Insert “Dartmouth”, founded 1769
```

![Short5_40](/IMG/Shorts5/Short5_40.png)
![Short5_41](/IMG/Shorts5/Short5_41.png)
![Short5_42](/IMG/Shorts5/Short5_42.png)

___

## _`Search`_

</center>

To `search` for an element in the `trie`, use successive digits to navigate from the `root`, and if you can make it to the end without hitting a dead end (a `NULL pointer`), you’ve found it.

<center>

```txt
Search for “Harvard”, founded 1636
```

![Short5_43](/IMG/Shorts5/Short5_43.png)
![Short5_44](/IMG/Shorts5/Short5_44.png)
![Short5_45](/IMG/Shorts5/Short5_45.png)

```
...
```

![Short5_46](/IMG/Shorts5/Short5_46.png)

```txt
Search for “Princeton”, founded 1746
```

</center>

![Short5_47](/IMG/Shorts5/Short5_47.png)

___

## [Queue](#queue)

- A `queue` is a special type of structure that can be used to maintain data in an organized way.

- This data structure is commonly implemented in one of two ways: as an `array` or as a `linked list`.

- In either case, the important rule is that when data is added to the queue, it is `tacked onto the end`, and so if an element needs to be removed, the element at the front is the only element that can legally be removed.

  - First in, first out (`FIFO`)

___

- There are only `two operations` that may legally be performed on
a `queue`.

  - `Enqueue`: Add a new element to the end of the queue.

  - `Dequeue`: Remove the oldest element from the front of the queue.

___

### `Array`-based implementation

```c 
typedef struct _queue 
{ 
    VALUE array[CAPACITY]; // CAPACITY = 10 for demonstration purposes
    int front; 
    int size; 
} 
queue;
```

```c
queue q;
q.front = 0; // In `Green` is the `front` of the queue;
q.size = 0; // In `Red` is the `size` of the queue.
```

![Short5_48](/IMG/Shorts5/Short5_48.png)

### `Enqueue`: add a new element to the end of the queue

___

In the general case, `enqueue()` needs to:

- `Accept a pointer` to the queue.

- `Accept data of type` VALUE to be added to the queue.

- `Add that data` to the queue at the `end` of the queue.

- `Change the size` of the queue.

```c
void enqueue(queue* q, VALUE data);
```

```c
enqueue(&q, 28);

// Front of the queue remains at 0
// Size of the queue is now 1
```

![Short5_49](/IMG/Shorts5/Short5_49.png)

```c
enqueue(&q, 33);

// Front of the queue remains at 0
// Size of the queue is now 2
```

![Short5_49](/IMG/Shorts5/Short5_50.png)

```c
enqueue(&q, 19);

// Front of the queue remains at 0
// Size of the queue is now 3
```
![Short5_51](/IMG/Shorts5/Short5_51.png)

### `Dequeue`: Remove the most recent element from the front of the queue

___

In the general case, `dequeue()` needs to:

- Accept a pointer to the queue.

- Change the location of the front of the queue.

- Decrease the size of the queue.

- Return the value that was removed from the queue.

```c
VALUE dequeue(queue* q);
```

![Short5_52](/IMG/Shorts5/Short5_52.png)

```c
int x = dequeue(&q);

// Front of the queue is now 1
// Size of the queue is now 2
```

![Short5_53](/IMG/Shorts5/Short5_53.png)

```c
enqueue(&q, 40);

// Front of the queue is now 2
// Size of the queue is now 2
```

![Short5_54](/IMG/Shorts5/Short5_54.png)

We may eventually need to `mod by the size of CAPACITY`.

- So if we get to element number 10, if we're replacing it in element number 10, we'd actually put it in array location 0.

- If we added them up together, and we got to number 11, which doesn't exist in this array--it would be going out of bounds.

___

### `Linked list`-based implementation

```c
typedef struct _queue 
{ 
    VALUE val; 
    struct _queue *prev; 
    struct _queue *next; 
} 
queue;
```

Just make sure to always maintain pointers to the `head` and `tail` of the linked list! (probably global)

To `enqueue`:

- Dynamically allocate a new node;

- Set its next pointer to NULL, set its prev pointer to the tail;

- Set the tail’s next pointer to the new node;

- Move the tail pointer to the newly-created node.

![Short5_55](/IMG/Shorts5/Short5_55.png)
![Short5_56](/IMG/Shorts5/Short5_56.png)
![Short5_57](/IMG/Shorts5/Short5_57.png)
![Short5_58](/IMG/Shorts5/Short5_58.png)
![Short5_59](/IMG/Shorts5/Short5_59.png)
![Short5_60](/IMG/Shorts5/Short5_60.png)

To `dequeue`:

- Traverse the `linked list` to its second element (if it exists);

- Free the head of the list;

- Move the `head pointer` to the (former) second element;

- Make that node’s `prev pointer` point to `NULL`.

![Short5_61](/IMG/Shorts5/Short5_61.png)
![Short5_62](/IMG/Shorts5/Short5_62.png)
![Short5_63](/IMG/Shorts5/Short5_63.png)
![Short5_64](/IMG/Shorts5/Short5_64.png)
![Short5_65](/IMG/Shorts5/Short5_65.png)
![Short5_66](/IMG/Shorts5/Short5_66.png)

___

<center>

## [Stacks](#stacks)

</center>

- A stack is a special type of structure that can be used to maintain data in an organized way.

- This data structure is commonly implemented in one of two ways: as an `array` or as a `linked list`. 

- In either case, the important rule is that when data is added to the stack, it sits “on top,” and so if an element needs to be removed, the most recently added element is the only element that can legally be removed.

  - Last in, first out (`LIFO`)

___

There are only two operations that may legally be performed on a `stack`.

- `Push`: Add a new element to the top of the stack.

- `Pop`: Remove the most recently-added element from the top of the stack.

### `Array`-based implementation

```c
typedef struct _stack 
{ 
    VALUE array[CAPACITY]; 
    int top; // element most recently added
} 
stack;
```

```c
stack s;
s.top = 0;

// The Green box is the `top` of the stack;
```

![Short5_67](/IMG/Shorts5/Short5_67.png)

`Push`: Add a new element to the top of the stack.

In the general case, `push()` needs to: • • • •

- Accept a `pointer to the stack`.

- Accept data of type VALUE to be added to the stack.

- Add that data to the stack at the top of the stack.

- Change the location of the top of the stack.

___

```c
void push(stack* s, VALUE data);
```

```c
stack s;
s.top = 0;
push(&s, 28);

// top of the stack is now 1
```

![Short5_68](/IMG/Shorts5/Short5_68.png)

```c
push(&s, 33);

// top of the stack is now 2
```

![Short5_69](/IMG/Shorts5/Short5_69.png)

```c
push(&s, 19);

// top of the stack is now 3
```

![Short5_70](/IMG/Shorts5/Short5_70.png)

`Pop`: Remove the most recent element from the top of the stack.

In the general case, `pop()` needs to:

- Accept a `pointer to the stack`.

- `Change` the location of the `top of the stack`.

- `Return the value` that was removed from the stack.

```c
VALUE pop(stack* s);
```

![Short5_70](/IMG/Shorts5/Short5_70.png)
![Short5_71](/IMG/Shorts5/Short5_71.png)

```c
// Pop 19 out of the stack
```

![Short5_72](/IMG/Shorts5/Short5_72.png)
![Short5_73](/IMG/Shorts5/Short5_73.png)

```c
//  Pop 33 out of the stack
```

![Short5_75](/IMG/Shorts5/Short5_75.png)

```c
// Push 40 to the top of the stack
```

### `Linked list`-based implementation

```c
typedef struct _stack 
{ 
    VALUE val; 
    struct _stack *next; 
} 
stack;

// NOTE: very similar to Singly Linked List
```

- Just make sure to always maintain a pointer to the head of the `linked list`!

- To `push`, dynamically allocate a new node, set its next pointer to point to the current head of the list, then move the head pointer to the newly-created node.

![Short5_76](/IMG/Shorts5/Short5_76.png)
![Short5_77](/IMG/Shorts5/Short5_77.png)
![Short5_78](/IMG/Shorts5/Short5_78.png)
![Short5_79](/IMG/Shorts5/Short5_79.png)
![Short5_80](/IMG/Shorts5/Short5_80.png)

To `pop`, traverse the `linked list` to its second element (if it exists), free the head of the list, then move the head pointer to the (former) second element.

![Short5_81](/IMG/Shorts5/Short5_81.png)
![Short5_82](/IMG/Shorts5/Short5_82.png)
![Short5_83](/IMG/Shorts5/Short5_83.png)
![Short5_84](/IMG/Shorts5/Short5_84.png)
![Short5_85](/IMG/Shorts5/Short5_85.png)

=======================

#### Return to [`CS50x`](/README.md)

=======================