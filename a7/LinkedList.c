#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

// Prints all the values in the doubly linked list
int PrintLinkedList(LinkedListPtr linkedList) {
    // Check if doubly LL is NULL, create/validate temp head node
    if (linkedList == NULL) return 1;
    LinkedListNode* temp = linkedList->head;
    if (temp == NULL) return 2;

    // Iterate through doubly LL and print each element
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
        if (temp == NULL) {
            printf("NULL");
        }
    }
    printf("\n");
    return 0;
}

// Creates an individual linked list node
LinkedListNode* CreateLinkedListNode(char* data) {
    // Malloc memeory for DLL node and check it was successful
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) return NULL;

    // Initialize and return DLL node
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Creates an initial empty linked list
LinkedListPtr CreateLinkedList() {
    // Malloc memeory for DLL and check it was successful
    LinkedListPtr newList = (LinkedListPtr)malloc(sizeof(LinkedList));
    if (newList == NULL) return NULL;

    // Initialize and return DLL
    newList->num_elements = 0;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Determines if the linked list is empty, check head and tail for NULL
int isEmpty(LinkedListPtr linkedList) {
    if (linkedList->head == NULL && linkedList->tail == NULL) return 1;
    return 0;
}

// Returns the number of nodes/elements in a linked list
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    if (list == NULL) return -1;
    return list->num_elements;
}


// Inserts a node in a linked list at the head position
int addLeft(LinkedListPtr linkedList, char* value) {
    // Check if DLL is NULL, create/validate new node to add
    if (linkedList == NULL) return 1;
    LinkedListNode* newNode = CreateLinkedListNode(value);
    if (newNode == NULL) return 2;

    // If empty, calls addRight to add first node. Else adds new node to head
    if (isEmpty(linkedList)) {
        return addRight(linkedList, value);
    } else {
        LinkedListNode* tempHead = linkedList->head;
        tempHead->prev = newNode;
        newNode->next = tempHead;
        newNode->prev = NULL;
        linkedList->head = newNode;
    }

    // Increment node count and return addLeft was successful
    linkedList->num_elements++;
    return 0;
}

// Removes a node from the left of the linked list, aka the head node
int removeLeft(LinkedListPtr linkedList) {
    // Checks to see if the given linked list ptr is valid
    if (linkedList == NULL) return 1;

    // Checks to see if the list is currently empty
    if (isEmpty(linkedList)) return 0;

    // Create/validate temp head node for node in list head position
    LinkedListNode* temp = linkedList->head;
    if (temp == NULL) return 2;

    // Removes head node from DLL; DLL becomes empty if has one element
    if (temp->next != NULL) {
        (temp->next)->prev = NULL;
        linkedList->head = temp->next;
        temp->next = NULL;
    }

    // Decrease num elements in DLL and destroy node; return removal complete
    linkedList->num_elements--;
    DestroyLinkedListNode(temp);
    return 0;
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

// Removes the node from the right of the linked list, aka the tail
int removeRight(LinkedListPtr linkedList) {
    // Checks to see if the given linked list ptr is valid
    if (linkedList == NULL) return 1;

    // Checks to see if the list is currently empty
    if (isEmpty(linkedList)) return 0;

    // Creates a temp node for the element in the list tail position
    LinkedListNode* temp = linkedList->tail;
    if (temp == NULL) return 2;

    // Removes tail node from DLL; DLL becomes empty if has one element
    if (temp->prev != NULL) {
        (temp->prev)->next = NULL;
        linkedList->tail = temp->prev;
        temp->prev = NULL;
    }

    // Decrease num elements in DLL and destroy node; return removal complete
    DestroyLinkedListNode(temp);
    linkedList->num_elements--;
    return 0;
}

// Inserts a node in the linked list at the specified index
int insertAt(LinkedListPtr list, char* value, int pos) {
    // Check if DLL is NULL, create/validate new node to add
    if (list == NULL) return 1;
    LinkedListNode* newNode = CreateLinkedListNode(value);
    if (newNode == NULL) return 2;

    // Checks Edge cases: return failure if pos < 0 or pos > num nodes in DLL
    if (pos < 0 || pos > NumElementsInLinkedList(list)) {
        DestroyLinkedListNode(newNode);
        return 3;
    }

    // If pos is index 0, make new node list head
    if (pos == 0) {
        return addLeft(list, value);
    }

    // If the pos is equal to last index+1, add to tail of DLL
    if (pos == (NumElementsInLinkedList(list))) {
        return addRight(list, value);
    }

    // Create/validate temp node for DLL head
    LinkedListNodePtr tempHead = list->head;
    if (tempHead == NULL) return 3;

    // For loop to get to index/node where we want to insert new node
    int i;
    for (i = 0; i < pos; i++) {
        tempHead = tempHead->next;
    }

    // Insert node at the given pos index
    (tempHead->prev)->next = newNode;
    newNode->prev = (tempHead->prev);
    newNode->next = tempHead;
    tempHead->prev = newNode;

    // Increment the number of elements DLL has and return insertion successful
    list->num_elements++;
    return 0;
}

// Remove DLL node at the specified index
int removeAt(LinkedListPtr list, int pos) {
    // Checks if DLL is NULL OR that given pos is valid index in DLL
    if (list == NULL || (pos < 0 || pos >= NumElementsInLinkedList(list))) {
        return 1;
    }

    // Checks to see if the list is currently empty
    if (isEmpty(list)) return 0;

    // If pos is at index 0, remove DLL head
    if (pos == 0) return removeLeft(list);

    // If pos is at last index in DLL, remove DLL tail
    if ((pos == (NumElementsInLinkedList(list)-1))) {
        return removeRight(list);
    }

    // Create/validate temp node for DLL head
    LinkedListNodePtr tempHead = list->head;
    if (tempHead == NULL) return 2;

    // For loop to get to index/node where we want to remove node
    int i;
    for (i = 0; i < pos; i++) {
        tempHead = tempHead->next;
    }

    // Remove node at given index from DLL
    (tempHead->prev)->next = tempHead->next;
    (tempHead->next)->prev = tempHead->prev;

    // Decrease num elements in DLL and destroy node; return removal complete
    list->num_elements--;
    DestroyLinkedListNode(tempHead);
    return 0;
}

// Determines if the given value is contained within the linked list
int LinkedListContains(LinkedListPtr linkedList, char* value) {
    // Check if DLL is NULL, create/validate new node to search for
    if (linkedList == NULL) return -1;
    LinkedListNode* temp = linkedList->head;
    if (temp == NULL) return -2;

    // Iterates through DLL and compares each node value with given value
    while (strcmp(temp->data, value)) {
        // If NULL terminator reached, return value not in DLL
        if (temp->next == NULL) {
            return 0;
        }
        temp = temp->next;
    }

    // Return value is in list
    return 1;
}


// Calls free() on an entire linkedList. First free's each node, then the list
void DestroyLinkedList(LinkedListPtr linkedList) {
    // Check if DLL is NULL, create/validate new node to search for
    if (linkedList == NULL) return;
    LinkedListNode* node = linkedList->head;

    // Iterates through DLL and destroys each node
    while (node != NULL) {
        LinkedListNode* temp = node->next;
        DestroyLinkedListNode(node);
        node = temp;
    }

    // Free DLL
    free(linkedList);
}

// Calls free() on a single node
int DestroyLinkedListNode(LinkedListNode* node) {
    if (node == NULL) return 1;
    free(node->data);
    free(node);
    return 0;
}
