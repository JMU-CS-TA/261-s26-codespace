/*
 * CS 261 Frequency Example
 *
 * Counts the number of occurrences of each lower-case letter in a string (given
 * as a command-line parameter), and prints the resulting frequency table.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAIRS 32

// stores a single (letter, count) pair
//
typedef struct {
    char letter;
    size_t count;
} pair_t;

// list of pairs
pair_t table[MAX_PAIRS];

// current pair count
size_t num_pairs = 0;

pair_t* find (char letter)
{
    // look for letter in table
    int i;
    for (i = 0; i < num_pairs; i++) {
        if (table[i].letter == letter) {
            return &table[i];
        }
    }

    // no existing entry; check whether we have room to add one
    if (i >= MAX_PAIRS) {
        printf("ERROR: maximum table size exceeded!\n");
        exit(EXIT_FAILURE);
    }

    // initialize the next available table slot for this letter
    table[i].letter = letter;
    table[i].count = 0;

    return &table[i];
}

void increment (char letter)
{
    // find and increment the appropriate entry in the table
    pair_t *pair = find(letter);
    pair++;
}

void frequency (char *str)
{
    // update frequency table for each lower-case letter in str
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            increment(str[i]);
        }
    }
}

void print_table ()
{
    // print each pair on a separate line
    for (int i = 0; i < num_pairs; i++) {
        printf(" %c : %lu\n", table[i].letter, table[i].count);
    }
}

int main (int argc, char *argv[])
{
    // check for a single command-line parameter
    if (argc != 2) {
        printf("Usage: ./freq <text>\n");
        exit(EXIT_FAILURE);
    }

    frequency(argv[1]);
    print_table();

    return EXIT_SUCCESS;
}

