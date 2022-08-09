#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef DEQUE_H
#define DEQUE_H

// ======================================================
// Deque: A Deque that utilizes a Doubly-Linked List
// ======================================================

// STRUCT DEFINITIONS

// We have one struct: It is a Deque which we create an alias for the pointer.

// This struct represents the entire Deque. We provided a struct declaration
// (but not definition) in Deque.h; this is the associated definition.
// This struct contains metadata about the Deque.
typedef struct deque {
  uint64_t num_elements;   // # elements in the list
  LinkedListNodePtr front;  // head of linked list, or NULL if empty
  LinkedListNodePtr rear;  // tail of linked list, or NULL if empty
} *DequePtr;

// ======================================================
// Deque: A Deque that is implemented with a Doubly-Linked List
// ======================================================

// Creates a Deque.
// The customer is responsible for calling DestroyDeque() to destroy
// the Deque when done.
//
// Returns an empty Deque; NULL if there's an error.
DequePtr createDeque();

// Destroys a Deque.
// All structs associated with a Deque will be released and freed.
//
// INPUT: A pointer to a Deque.
void destroyDeque(DequePtr deque);

// Determines if the current deque is empty.
//
// INPUT: A pointer to the Deque.
//
// Returns 1 if empty, 0 if not.
int dequeIsEmpty(DequePtr deque);

// Returns the number of elements in the Deque.
//
// INPUT: A pointer to the Deque.
//
// Returns the number of elements in the Deque.
unsigned int countDeque(DequePtr deque);

// Adds an element to the front of Deque.
//
// INPUT: A pointer to the Deque.
// INPUT: The value to add to Deque.
//
// Returns 0 if push was successful; non-zero for failure.
int pushLeft(DequePtr deque, int value);

// Peeks at element at front of Deque.
//
// INPUT: A pointer to the Deque.
//
// Returns pointer to node at front of Deque; else returns nothing for failure
// or empty Deque.
LinkedListNodePtr peekLeft(DequePtr deque);

// Removes/deletes element from front of Deque.
//
// INPUT: A pointer to the Deque.
//
// Returns node pointer and removes node element at front of Deque if pop
// successful; else returns nothing for failure or empty Deque.
LinkedListNodePtr popLeft(DequePtr deque);

// Adds an element to rear of Deque.
//
// INPUT: A pointer to the Deque.
// INPUT: A value to add to Deque.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int pushRight(DequePtr deque, int value);

// Peaks at element at rear of Deque.
//
// INPUT: A pointer to the Deque.
//
// Returns pointer to element at rear of Deque; else returns nothing for failure
// or empty Deque.
LinkedListNodePtr peekRight(DequePtr deque);

// Removes/deletes elements from rear of Deque.
//
// INPUT: A pointer to the Deque.
//
// Returns node pointer and removes node element at rear of Deque if pop
// successful; else returns nothing for failure or empty Deque.
LinkedListNodePtr popRight(DequePtr deque);

// Determines if Deque contains value passed.
//
// INPUT: A pointer to the Deque.
// INPUT: The integer to search for within Deque.
//
// Returns 0 if the value is in the Deque; non-zero if not.
int dequeHasValue(DequePtr deque, int value);

// Prints out the given Deque.
//
// INPUT: A pointer to the Deque to be printed.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int printDeque(DequePtr deque);

#endif
