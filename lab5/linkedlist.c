#include <stdio.h>
#include "linkedlist.h"

// Prints all the values in the linked list
int PrintLinkedList(LinkedListPtr linkedList) {
    if(linkedList == NULL) {
        return 1;
    }

    LinkedListNode* temp = linkedList->head;

    if(temp == NULL) {
        return 2;
    }

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

// Creates an individual linked list node
LinkedListNode* CreateLinkedListNode(int data) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(newNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Creates an initial empty linked list
LinkedListPtr CreateLinkedList() {
    LinkedListPtr newList = (LinkedListPtr)malloc(sizeof(LinkedListPtr));

    if(newList == NULL) {
        return NULL;
    }

    newList->num_elements = 0;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Adds a node to the end of a linked list
int AppendLinkedList(LinkedListPtr linkedList, int value) {
    if(linkedList == NULL) {
        return 1;
    }

    LinkedListNodePtr newNode = CreateLinkedListNode(value);
    if(newNode == NULL) {
        return 2;
    }

    if(linkedList->head == NULL && linkedList->tail == NULL) {
        // No nodes are before or after first node
        newNode->prev = NULL;
        newNode->next = NULL;

        // Assign first node to linkedlist
        linkedList->head = newNode;
        linkedList->tail = newNode;
    }

    if(linkedList->head != NULL) {
        // Get the previous node in linkedlist
        LinkedListNodePtr prevNode = linkedList->tail;

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = NULL;
        linkedList->tail = newNode;
    }
    linkedList->num_elements++;
    return 0;
}

// Inserts a node in the linked list at the specified index
int InsertInsideLinkedList(LinkedListPtr list, int value, int pos) {
    if(list == NULL) {
        return 1;
    }

    LinkedListNode* newNode = CreateLinkedListNode(value);

    if(newNode == NULL) {
        return 2;
    }

    // If the pos is greater than the last index in the list or list is empty, append new node
    if((list->head == NULL && list->tail == NULL) || (pos > (NumElementsInLinkedList(list)-1))) {
        return AppendLinkedList(list, value);
    }

    LinkedListNodePtr tempHead = list->head;

    // For loop to get to node where we want to insert new node
    int i;
    for(i=0;i<pos;i++) {
        tempHead = tempHead->next;
    }

    LinkedListNodePtr tempNode = tempHead;
    tempHead = newNode;
    (tempNode->prev)->next = tempHead;
    tempHead->prev = (tempNode->prev);
    tempHead->next = tempNode;
    tempNode->prev = tempHead;
    list->num_elements++;
    return 0;
}

// Returns the number of nodes/elements in a linked list
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    if(list == NULL) return;
    return list->num_elements;
}

// Inserts a node in a linked list at the head position
int InsertLinkedList(LinkedListPtr linkedList, int value) {
    if(linkedList == NULL) return 1;

    LinkedListNode* newNode = CreateLinkedListNode(value);

    if(newNode == NULL) return 2;

    if(linkedList->head == NULL && linkedList->tail == NULL) {
        return AppendLinkedList(linkedList, value);
    }

    if(linkedList->head != NULL) {
        LinkedListNode* tempHead = linkedList->head;
        tempHead->prev = newNode;
        newNode->next = tempHead;
        newNode->prev = NULL;
        linkedList->head = newNode;
    }
    linkedList->num_elements++;
    return 0;
}

// Calls free() on an entire linkedList. First free's each node, then the list
void DestroyLinkedList(LinkedListPtr linkedList) {
    if(linkedList == NULL) return;

    LinkedListNode* temp = linkedList->head;

    while(temp != NULL) {
        DestroyLinkedListNode(temp);
        temp = temp->next;
    }

    free(linkedList);
}

// Calls free() on a single node
int DestroyLinkedListNode(LinkedListNode* node) {
    if(node == NULL) return 1;

    free(node);
    return 0;
}

int RemoveLLElem(LinkedListPtr linkedList, LinkedListNodePtr nodePtr) {
    if (linkedList == NULL) {
        return 1;
    }

    if (nodePtr == NULL) {
        return 2;
    }

    LinkedListNode* tempNode = nodePtr;
    LinkedListNode* temp = linkedList->head;

    while (temp->data != tempNode->data) {
        if (temp->next == NULL) {
            DestroyLinkedListNode(temp);
            DestroyLinkedListNode(tempNode);
            return 3;
        }
        temp = temp->next;
    }

    // In the case the node is head
    if (temp == linkedList->head) {
        (temp->next)->prev = NULL;
        linkedList->head = temp->next;
        temp->next = NULL;    
    }

    // Checks all nodes after head until tail
    else if (temp != linkedList->head && temp != linkedList->tail) {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
    }

    // In the case the node is tail
    else if (temp == linkedList->tail) {
        (temp->prev)->next = NULL;
        linkedList->tail = temp->prev;
        temp->prev = NULL;

    }
    linkedList->num_elements--;
    DestroyLinkedListNode(temp);
    DestroyLinkedListNode(tempNode);
    return 0;
}
