/*
 * sort.h
 *
 * Header file for sort.c
 */
#ifndef SORT_H
#define SORT_H
#include "linkedlist.h"

void bubble_sort_list(List **list, int (*compare)(List *one, List *two));

#endif
