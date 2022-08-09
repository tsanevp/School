#include <stdio.h>
#include "history.h"

// Prints all the values in the doubly linked list. The values stored represent
// all the commands passed to the custom K-SEA-SHELL.
int PrintLinkedList(LinkedListPtr linkedList) {
    // Check if doubly LL is NULL, create/validate temp head node
    if (linkedList == NULL) return 1;
    LinkedListNode* temp = linkedList->head;
    if (temp == NULL) return 2;

    // Iterate through doubly LL and print each element
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
    return 0;
}

// Creates an individual linked list node
LinkedListNode* CreateLinkedListNode(char* data) {
    // Malloc memeory for DLL node and check it was successful
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(newNode));
    if (newNode == NULL) return;

    // Initialize and return DLL node
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Creates an initial empty linked list
LinkedListPtr CreateLinkedList() {
    // Malloc memeory for DLL and check it was successful
    LinkedListPtr newList = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
    if (newList == NULL) return NULL;

    // Initialize and return DLL
    newList->num_elements = 0;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Determines if the linked list is empty, check head and tail for NULL
int isEmpty(LinkedListPtr linkedList) {
    return (linkedList->head == NULL && linkedList->tail == NULL);
}

// Returns the number of nodes/elements in a linked list
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    if (list == NULL) return;
    return list->num_elements;
}

// Adds a node to tail of a linked list
int addRight(LinkedListPtr linkedList, char* value) {
    // Check if DLL is NULL, create/validate new node to add
    if (linkedList == NULL) return 1;
    LinkedListNodePtr newNode = CreateLinkedListNode(value);
    if (newNode == NULL) return 2;

    // If empty, makes new  node head/tail node. Else adds new node to DLL tail
    if (isEmpty(linkedList)) {
        linkedList->head = newNode;
        linkedList->tail = newNode;
    } else {
        // Create/validate DLL temp tail node
        LinkedListNodePtr prevNode = linkedList->tail;
        if (prevNode == NULL) return 3;

        // Add new node to DLL tail
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = NULL;
        linkedList->tail = newNode;
    }

    // Increment the number of elements DLL has and return insertion successful
    linkedList->num_elements++;
    return 0;
}

// Calls free() on an entire linkedList. First free's each node, then the list
void DestroyLinkedList(LinkedListPtr linkedList) {
    // Check if DLL is NULL, create/validate new node to search for
    if (linkedList == NULL) return;
    LinkedListNode* temp = linkedList->head;
    if (temp == NULL) return;

    // Iterates through DLL and destroys each node
    while (temp != NULL) {
        DestroyLinkedListNode(temp);
        temp = temp->next;
    }

    // Free DLL
    free(linkedList);
}

// Calls free() on a single node
int DestroyLinkedListNode(LinkedListNode* node) {
    if (node == NULL) return 1;

    free(node);
    return 0;
}
