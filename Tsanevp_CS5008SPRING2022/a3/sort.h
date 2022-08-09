#include "linkedlist.h"
#ifndef SORT_H
#define SORT_H

// This sort is for part 1 of the assignment.
//
// Sort.c calls an insertion sort on a linked list. The sort works
// similar to how one sorts playing cards when holding them. It
// takes the value at the current index, and compares it to all values
// that come before it, if less moves the value to the left until it
// reaches a value it is greater than, or it reaches the list head.
//
// INPUT: A pointer to an unsorted linked list.
void Sort(LinkedListPtr);

#endif
