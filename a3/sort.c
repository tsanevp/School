#include <stdio.h>
#include <time.h>
#include "linkedlist.h"

void Sort(LinkedListPtr list) {
    // Check to see if list is valid
    if (list == NULL) {
        return;
    }

    // Create a temp node pointer to head and get list length
    LinkedListNodePtr tempHead = list->head;
    int listLength = NumElementsInLinkedList(list);

    // Check to see if list is empty
    if (listLength == 0 || tempHead == NULL) {
        printf("List is empty...\n");
        return;
    }

    // Create a pointer to head that is used to loop through list
    LinkedListNodePtr currNode = tempHead->next;
    LinkedListNodePtr prevNode = tempHead;

    int indexHead = 0;
    int i, j;

    // Outermost loop, checks each value in the list, starts at second value.
    for (i = 1; i < listLength; i++) {
        // technically tail to sorted portion
        LinkedListNodePtr key = currNode->prev;
        j = i - 1;
        if (currNode->data >= prevNode->data && currNode == list->head) {
            return;
        }

        if (currNode->data >= prevNode->data && currNode != list->tail) {
            prevNode = currNode;
            currNode = currNode->next;
            continue;
        }
        while (j >= indexHead && prevNode->data > currNode->data) {
            // Case where curr node is at tail
            if (currNode == list->tail) {
                (currNode->prev)->next = NULL;
                list->tail = currNode->prev;
            // make previous node the new tail, remove current from tail
            } else if (j+1 == i) {
            // Case where curr node is not at tail and first itt of loop
                (currNode->next)->prev = prevNode;
                prevNode->next = currNode->next;
            }

            prevNode = prevNode->prev;
            if (prevNode == list->head) {
                break;
            }
            j--;
        }
        // Need to fix that prev node gets assigned to NULL
        if (prevNode == NULL) {
            prevNode = list->head;
        }

        // This is if swap spots with head
        if (prevNode == list->head && prevNode->data > currNode->data) {
            currNode->prev = NULL;
            currNode->next = prevNode;
            prevNode->prev = currNode;
            list->head = currNode;  // adds node to head
        } else {
            (prevNode->next)->prev = currNode;
            currNode->next = prevNode->next;
            prevNode->next = currNode;
            currNode->prev = prevNode;
        }

        if (prevNode->next == NULL) {
            break;
        }

        currNode = key->next;
        prevNode = key;
    }
}
