#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef DOUBLY_H
#define DOUBLY_H

// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// STRUCT DEFINITIONS

// We have 2 structs: One is a LinkedListNode, and one is a LinkedListHead,
// which we create an alias for the pointer.
//
// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
  int data;              // Data this node holds
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
// The customer is responsible for calling DestroyLinkedList()
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

// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int addLeft(LinkedListPtr, int);

// Removes an element from the head/left position of a LinkedList.
//
// INPUT: A pointer to the LinkedList.
//
// Returns 0 if the list is already empty, or the removal was successful;
// non-zero for failure.
int removeLeft(LinkedListPtr);

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int addRight(LinkedListPtr, int);

// Removes an element from the tail/right position of a LinkedList.
//
// INPUT: A pointer to the LinkedList.
//
// Returns 0 if the list is already empty, or the removal was successful;
// non-zero for failure.
int removeRight(LinkedListPtr);

// Adds an element anywhere inside a linked list. If the given index
// to add the element to is larger than the list, append to end.
//
// INPUT: A pointer to the LinkedList that will be added to.
// INPUT: A value for a node in the linkedList.
// INPUT: The index/node position to add the new node in.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int insertAt(LinkedListPtr list, int value, int pos);

// Removes an element anywhere inside a linked list. If the given index
// to add the element to is larger than the list, append to end.
//
// INPUT: A pointer to the LinkedList that will be added to.
// INPUT: The index/node position to remove the node at.
//
// Returns 0 if the removal was successful; non-zero for failure.
int removeAt(LinkedListPtr list, int pos);

// Determines if the value passed is contained within the linked list.
//
// INPUT: A pointer to a LinkedList.
// INPUT: An interget value that we look for within the linked list.
//
// Returns 0 if the value is in the list; non-zero if not.
int hasValue(LinkedListPtr list, int value);

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
LinkedListNode* CreateLinkedListNode(int data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);

#endif
