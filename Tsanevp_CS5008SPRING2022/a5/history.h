#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef HISTORY_H
#define HISTORY_H

// =========================================================================
// History: A Doubly-Linked List that can have elements be added to it, but
//          not removed. All elements are added to the tail of the list.
//          The list stores all the commands passed to the custom shell.
// =========================================================================

// STRUCT DEFINITIONS

// We have 2 structs: One is a LinkedListNode, and one is a LinkedListHead,
// which we create an alias for the pointer.
//
// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
  char* data;              // Data this node holds
  struct ll_node *next;  // next node in list, or NULL
  struct ll_node *prev;  // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
  uint64_t num_elements;   // # elements in the list
  LinkedListNodePtr head;  // head of linked list, or NULL if empty
  LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} *LinkedListPtr;

// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The user is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedListPtr CreateLinkedList();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list);

// Determines if the current linked list is empty/
//
// INPUT: A LinkedList/
//
// Returns 1 if empty, 0 if not.
int isEmpty(LinkedListPtr list);

// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList.
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedListPtr list);

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int addRight(LinkedListPtr, char*);

// Prints out the given LinkedListPtr.
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int PrintLinkedList(LinkedListPtr);

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(char* data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);

#endif
