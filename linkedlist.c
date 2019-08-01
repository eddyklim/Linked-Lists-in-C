/*
 * linkedlist.c
 *
 *  Created on: Feb 16, 2018
 *  Author: Eduard Klimenko
 *
 *  This file holds all of the useful functions related to the
 *  linked list such as inserting nodes, comparing nodes (not
 *  actual sort itself), displaying nodes, and freeing the list.
 */

// header
#include "linkedlist.h"

// creates empty node
Node *createList(void) {
    return NULL;
}

/*
 * This function takes in a word and parses the word to only contain
 * alphabetic characters, apostrophes, and hyphens. If the word is in
 * the list then increments the counter based on the book, if not, adds
 * new node.
 */
void insert(List **list, char *name1, int bookNum) {
    Node *scan, *back = NULL;
    Node *newNode = malloc(sizeof(Node));
    int bool = 0;
    int start = 0;
    for (int i = 0; i < 40; i++) {
        name1[i] = tolower(name1[i]);
    }
    //finds first valid char
    while (!(name1[start] >= 97 && name1[start] <= 122) && !(name1[start] == 45)
            && !(name1[start] == 39)) {
        start++;
    }
    int stop = start;
    // finds next valid char
    while (((name1[stop] >= 97 && name1[stop] <= 122)) || (name1[stop] == 39)
            || (name1[stop] == 45)) {
        stop++;
    }
    char *name = malloc(sizeof(WORD_LENGTH));
    strncpy(name, name1 + start, stop - start);
    // adds null terminating char
    name[stop - start] = '\0';
    // put the word into the node
    strcpy(newNode->name, name);
    // adds to correct counter based on book
    if (bookNum == 1)
        newNode->value = 1;
    else
        newNode->value2 = 1;
    newNode->next = NULL;
    // if empty list add node
    if (*list == NULL)
        *list = newNode;
    else {
        scan = *list;
        // looks through list to find a match
        // if match increment correct counter
        while (scan != NULL) {
            if (strcmp(scan->name, newNode->name) == 0) {
                if (bookNum == 1)
                    scan->value = scan->value + 1;
                else
                    scan->value2 = scan->value2 + 1;
                bool = 1;
            }
            back = scan;
            scan = scan->next;
        }
        // if no match add the node
        if (bool == 0) {
            if (scan == *list) {
                insertFront(list, newNode);
            } else {
                newNode->next = scan;
                back->next = newNode;
            }
        }
    }
}

// sorts descending
int compareWords(Node *a, Node *b) {
    return strcmp(a->name, b->name);
}

int compareDifferences(Node *a, Node *b) {
    // sorts ascending by difference
    int result = abs(b->value - b->value2) - abs(a->value - a->value2);
    // if same sort by word length
    if (!result)
        result = strlen(b->name) - strlen(a->name);
    //if same sort alphabetically
    if (!result)
        result = strcmp(a->name, b->name);
    return result;
}

// inserts in the beginning of the list
void insertFront(List **list, Node *n) {
    n->next = *list;
    *list = n;
}

// prints the first 25 nodes in the list based on formatting requirements
void printFirst25(List *list) {
    if (list) {
        int count = 1;
        // prints first 25
        while (list && count <= 25) {
            printf(
                    "%d. %15s, Redbadge.txt: %5d, LittleRegiment.txt: %5d, Difference: %5d\n",
                    count, (*list).name, list->value, list->value2,
                    abs(list->value - list->value2));
            list = list->next;
            count++;
        }
    }
}

// prints the first 25 and last 5 nodes in list based on formatting requirements
void printFirstAndLast(List *list) {
    if (list) {
        printf("Sorted by difference:\n");
        printFirst25(list);
        int totalCount = wordCount(list);
        int count = 1;
        // skips to the last 5
        while (list && count <= (totalCount - 5)) {
            list = list->next;
            count++;
        }
        printf("Last 5:\n");
        // prints last 5
        while (list) {
            printf(
                    "%d. %15s, Redbadge.txt: %5d, LittleRegiment.txt: %5d, Difference: %5d\n",
                    count, (*list).name, list->value, list->value2,
                    abs(list->value - list->value2));
            list = list->next;
            count++;
        }
    }
}

// counts all the nodes in the list
int wordCount(List *list) {
    int count = 0;
    if (list) {
        while (list) {
            count++;
            list = list->next;
        }
    }
    return count;
}

// frees all the nodes recursively
void freeList(List *list) {
    if (list) {
        freeList(list->next);
        free(list);
    }
}
