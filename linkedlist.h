/*
 * linkedlist.h
 *
 * Header file for linkedlist.c
 */

//protection and headers
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 50
// Node definition
typedef struct node {
    char name[WORD_LENGTH];
    int value;
    int value2;
    struct node *next;
}Node, List;

// LinkedList prototypes
Node *createList(void);
void insert(List **, char *, int bookNum);
void insertFront(List **, Node *);
void printFirst25(List *);
void printFirstAndLast(List *list);
void freeList(List *);
int wordCount(List *list);
int compareWords(Node *, Node *);
int compareDifferences(Node *, Node *);
#endif 
