/*
 * sort.c
 *
 * Code provided in the example files!
 */

#include "sort.h"

/*
 * This function takes in a list and a compare function.
 */
void bubble_sort_list(List **list, int (*compare)(List *one, List *two)) {
    int i, size, sorted = 0;
    List *back, *cur, *front;
    // Count the number of nodes in the list and store in size:
    for (size = 0, cur = *list; cur; size++, cur = cur->next)
        ;
    // Reduce the size by one
    size--;
    while (size && !sorted) {
        // Set pointers
        back = NULL;
        cur = *list;
        front = (*list)->next;
        sorted = 1;
        // Update list pointer by swapping pointers
        // Done at the start of every bubble process
        if (compare(*list, front) > 0) {
            sorted = 0;
            cur->next = front->next;
            *list = front;
            front->next = cur;
            front = cur->next;
            back = *list;
            // If nothing swapped, move on
        } else {
            back = cur;
            cur = front;
            front = front->next;
        }
        // Start with the second node in the list
        for (i = 1; front && i < size; i++) {
            // Swap if needed
            if (compare(cur, front) >= 0) {
                sorted = 0;
                back->next = front;
                cur->next = front->next;
                front->next = cur;
                back = front;
                front = cur->next;
                // If nothing swapped, move on
            } else {
                back = cur;
                cur = front;
                front = front->next;
            }
        }
        // Node is now in correct order
        size--;
    }
}
