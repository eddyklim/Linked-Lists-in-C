/*
 * eduardk_hw6.c
 *
 *  Created on: Feb 16, 2018
 *  Author: Eduard Klimenko
 *
 *  This program takes in two input files in .txt format and reads
 *  word by word (separated by whitespace). Inserts alphabetically
 *  and prints out the first 25 words including the number of occurrences
 *  in each file and also the difference in occurrences. Then the list is
 *  sorted based on difference and if same then based on word length, and
 *  if same then alphabetically. Then prints first 25 and also last 5.
 */

// header
#include <stdio.h>

#include "linkedlist.h"
#include "sort.h"
/*
 * This is the main function. Opens first file and inserts words into the
 * linked list. Opens the second file and inserts the words also. Prints out
 * the list and then bubble sorts and reprints.
 */
int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    char name[WORD_LENGTH];
    List *list = createList();
    FILE *in = fopen("RedBadge.txt", "r");
    // Checks if file opened
    if (in == NULL) {
        printf("File did not open.");
        return 1;
    }
    while (fscanf(in, "%s", name) != EOF) {
        insert(&list, name, 1);
    }
    fclose(in);
    FILE *in2 = fopen("LittleRegiment.txt", "r");
    // Checks if file opened
    if (in2 == NULL) {
        printf("File did not open.");
        return 1;
    }
    while (fscanf(in2, "%s", name) != EOF) {
        insert(&list, name, 2);
    }
    fclose(in2);
    bubble_sort_list(&list, compareWords);
    printf("There are %d unique words!\nSorted by words:\n", wordCount(list));
    printFirst25(list);
    bubble_sort_list(&list, compareDifferences);
    printFirstAndLast(list);
    freeList(list);
    return 0;
}
