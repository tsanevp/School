#include <stdio.h>
#include <time.h>
#include "doubly.h"
#include "deque.h"

int main() {
    // =========================================================
    // Assignment 4, Part 1
    // =========================================================

    int numValues = 10;  // Length linked list and num elements to add to array
    int i;

    // Random number generator
    srand(time(NULL));

    // Creates the initial empty linked list
    LinkedListPtr LinkedList = CreateLinkedList();

    // Creates linked list with size numValues
    for (i = 0; i < numValues; i++) {
        // int r = rand() % 1000;  // Can add rand ints if desired
        addRight(LinkedList, i);
    }

    // Print the following series of event for linked list:
    // - Initial doubly linked list
    // - Test of basic functionality of each required method
    // - Destroy and free linked list and its nodes
    printf("===============================================\n");
    printf("===============================================\n");
    printf("----- Start of Testing Part 1 -----\n");
    printf("----- Initial Doubly Linked List -----\n");
    PrintLinkedList(LinkedList);
    printf("================================================\n");
    printf("----- Testing add/remove Left -----\n");
    printf("Insert element with value 1000 to the head of LL\n");
    addLeft(LinkedList, 1000);
    PrintLinkedList(LinkedList);
    printf("Remove element at the head of LL\n");
    removeLeft(LinkedList);
    PrintLinkedList(LinkedList);
    printf("================================================\n");
    printf("----- Testing add/remove Right -----\n");
    printf("Insert element with value 1000 to the tail of LL\n");
    addRight(LinkedList, 1000);
    PrintLinkedList(LinkedList);
    printf("Remove element at the tail of LL\n");
    removeRight(LinkedList);
    PrintLinkedList(LinkedList);
    printf("================================================\n");
    printf("----- Testing insert/remove At -----\n");
    printf("Insert element with value 1000 at LL index 2\n");
    insertAt(LinkedList, 1000, 2);
    PrintLinkedList(LinkedList);
    printf("Remove element with value 1000 at LL index 2\n");
    removeAt(LinkedList, 2);
    PrintLinkedList(LinkedList);
    printf("================================================\n");
    printf("----- Testing hasValue -----\n");
    printf("Doubly linked list has value 10? Answer: %d\n",
    hasValue(LinkedList, 10));
    printf("Doubly linked list has value 2? Answer: %d\n",
    hasValue(LinkedList, 2));
    printf("================================================\n");
    printf("================================================\n");
    DestroyLinkedList(LinkedList);
/*
    // ===========================================================
    // Assignment 4, Part 2
    // ===========================================================

    int numElements = 10;  // Number of elements to add to Deque
    int j;

    // Random number generator
    srand(time(NULL));

    // Creates the initial empty linked list
    DequePtr deque = createDeque();
    printf("is empty??? %d\n", dequeIsEmpty(deque));

    // Creates linked list with size numValues
    for (j = 0; j < numElements; j++) {
        //int r = rand() % 1000;
        pushLeft(deque, j);
    }
    // Print the following series of event for Deque:
    // - Initial Deque
    // - Test of basic functionality of each required method
    // - Destroy and free Deque and its nodes
    printf("\n\n");
    printf("===============================================\n");
    printf("===============================================\n");
    printf("----- Start of Testing Part 2 -----\n");
    printf("----- Initial Deque -----\n");
    printDeque(deque);

    printf("================================================\n");
    printf("----- Testing push/peek/pop Left -----\n");
    printf("Push element with value 1000 to the front of Deque\n");
    pushLeft(deque, 1000);
    printDeque(deque);
    printf("Peek at front element of Deque... value is: %d\n",
    peekLeft(deque)->data);
    LinkedListNodePtr popLNode = popLeft(deque);
    printf("Pop element at front of Deque... value is: %d\n",
    popLNode->data);
    printDeque(deque);
    printf("================================================\n");
    printf("----- Testing push/peek/pop Right -----\n");
    printf("Push element with value 1000 to the rear of Deque\n");
    pushRight(deque, 1000);
    printDeque(deque);
    printf("Peek at rear element of Deque... value is: %d\n",
    peekRight(deque)->data);
    
    LinkedListNodePtr popRNode = popRight(deque);
    printf("Pop element at rear of Deque... value is: %d\n",
    popRNode->data);
    printDeque(deque);
    printf("================================================\n");
    printf("----- Testing hasValue -----\n");
    printf("Deque has value 10? Answer: %d\n",
    dequeHasValue(deque, 10));
    printf("Deque has value 2? Answer: %d\n",
    dequeHasValue(deque, 2));
    printf("================================================\n");
    printf("================================================\n");
    DestroyLinkedListNode(popLNode);
    DestroyLinkedListNode(popRNode);
    destroyDeque(deque);
*/    
    return 0;
}
