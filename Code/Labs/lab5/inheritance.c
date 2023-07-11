// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKYELLOW "\e[38;2;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[38;2;255;0;0m"
#define GREEN "\e[38;2;0;255;0m"
#define YELLOW "\e[38;2;255;255;0m"
#define CYAN "\e[38;2;0;255;255m"
#define RESET "\e[0m"

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *child = malloc(sizeof(person));
    if (child == NULL)
    {
        return NULL;
    }

    // If there are still generations left to create (with parent data)
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        child->parents[0] = parent0;
        child->parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        child->alleles[0] = child->parents[0]->alleles[rand() % 2];
        child->alleles[1] = child->parents[1]->alleles[rand() % 2];
    }
    // If there are no generations left to create (No parent data)
    else
    {
        // TODO: Set parent pointers to NULL
        child->parents[0] = NULL;
        child->parents[1] = NULL;

        // TODO: Randomly assign alleles
        child->alleles[0] = random_allele();
        child->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return child;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }

    // TODO: Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf(
            BLACKWHITE "Child" RESET BLACKBRIGHT " (Generation %i): " RESET RED "blood type " RESET GREEN"%c%c\n" RESET, 
            generation, p->alleles[0], p->alleles[1]
        );
    }
    else if (generation == 1)
    {
        printf(
            BLACKWHITE "Parent" RESET BLACKBRIGHT " (Generation %i): " RESET RED "blood type " RESET GREEN "%c%c\n" RESET, 
            generation, p->alleles[0], p->alleles[1]
        );
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf(
            BLACKWHITE "Grandparent" RESET BLACKBRIGHT " (Generation %i): " RESET RED "blood type " RESET GREEN "%c%c\n" RESET, 
            generation, p->alleles[0], p->alleles[1]
        );
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
