#include <stdio.h>
#include "doubly.h"
#include "deque.h"

// Prints all the values in the Deque
int printDeque(DequePtr deque) {
    // Check if Deque is NULL, create front temp node, check it's a valid node
    if (deque == NULL) return 1;
    LinkedListNode* temp = deque->front;
    if (temp == NULL) return 2;

    // Iterate through Deque and print each element
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

// Initializes empty Deque with front/rear equal to NULL
DequePtr createDeque() {
    // Malloc memory for Deque and check it was successful
    DequePtr newDeque = (DequePtr)malloc(sizeof(DequePtr));
    if (newDeque == NULL) return NULL;

    // Initialize and return Deque
    newDeque->num_elements = 0;
    newDeque->front = NULL;
    newDeque->rear = NULL;
    return newDeque;
}

// Determines if the Deque is empty, check head and tail for NULL
int dequeIsEmpty(DequePtr deque) {
    if (deque->front == NULL && deque->rear == NULL) return 1;
    return 0;
}

// Returns the number of nodes/elements in Deque
unsigned int countDeque(DequePtr deque) {
    if (deque == NULL) return;
    return deque->num_elements;
}

// Add/Push an element to the front of the Deque
int pushLeft(DequePtr deque, int value) {
    // Check if Deque is NULL, create new node to add, check it's a valid node
    if (deque == NULL) return 1;
    LinkedListNodePtr newNode = CreateLinkedListNode(value);
    if (newNode == NULL) return 2;

    // If Deque is empty, add as first element; else, make new element new front
    if (dequeIsEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        LinkedListNodePtr tempFront = deque->front;
        tempFront->prev = newNode;
        newNode->next = tempFront;
        newNode->prev = NULL;
        deque->front = newNode;
    }

    // Increase element count and return push was successful
    deque->num_elements++;
    return 0;
}

// Peeks at front element of Deque
LinkedListNodePtr peekLeft(DequePtr deque) {
    // Check if Deque is NULL or if Deque is empty
    if (deque == NULL || dequeIsEmpty(deque)) return;

    // Return front element of Deque
    return (deque->front);
}

// Removes and returns pointer to element from front of Deque
LinkedListNodePtr popLeft(DequePtr deque) {
    // Check if Deque is NULL or if Deque is empty
    if (deque == NULL || dequeIsEmpty(deque)) return;

    // Creates a temp node Deque front and validate it's successfully created
    LinkedListNode* temp = deque->front;
    if (temp == NULL) return;

    // Removes front element from Deque; Deque becomes empty if has one element
    if (temp->next != NULL) {
        (temp->next)->prev = NULL;
        deque->front = temp->next;
        temp->next = NULL;
    } else {
        deque->front == NULL;
        deque->rear == NULL;
    }

    // Decrease num of elements in Deque and return pointer to element removed
    deque->num_elements--;
    return temp;
}

// Adds element to rear of Deque
int pushRight(DequePtr deque, int value) {
    // Check if Deque is NULL, create new node to add, check it's a valid node
    if (deque == NULL) return 1;
    LinkedListNodePtr newNode = CreateLinkedListNode(value);
    if (newNode == NULL) return 2;

    // If Deque is empty, calls pushLeft(); else, add new element to rear
    if (dequeIsEmpty(deque)) {
        pushLeft(deque, value);
    } else {
        LinkedListNodePtr rearNode = deque->rear;
        rearNode->next = newNode;
        newNode->prev = rearNode;
        deque->rear = newNode;
    }

    // Increment element count and return push was successful
    deque->num_elements++;
    return 0;
}

// Peeks at rear element of Deque
LinkedListNodePtr peekRight(DequePtr deque) {
    // Check if Deque is NULL or if Deque is empty
    if (deque == NULL || dequeIsEmpty(deque)) return;

    // Return rear element of Deque
    return (deque->rear);
}

// Removes and returns element from rear of Deque
LinkedListNodePtr popRight(DequePtr deque) {
    // Check if Deque is NULL or if Deque is empty
    if (deque == NULL || dequeIsEmpty(deque)) return;

    // Creates a temp node for Deque rear and validates it was created properly
    LinkedListNode* temp = deque->rear;
    if (temp == NULL) return;

    // Removes rear element from Deque; Deque becomes empty if has one element
    if (temp->prev != NULL) {
        (temp->prev)->next = NULL;
        deque->rear = temp->prev;
    } else {
        deque->front == NULL;
        deque->rear == NULL;
    }

    // Decrease num of elements in Deque and return pointer to element removed
    deque->num_elements--;
    return temp;
}

// Determines if the given value is within the Deque
int dequeHasValue(DequePtr deque, int value) {
    // Checks Deque is not NULL
    if (deque == NULL) return 1;

    // Creates temp node for Deque front and validates it's successful creation
    LinkedListNode* temp = deque->front;
    if (temp == NULL) return;

    // Iterates through Deque until current Deque value equals given value
    while (temp->data != value) {
        // If Deque reaches NULL termination, return not in Deque
        if (temp->next == NULL) {
            DestroyLinkedListNode(temp);
            return 2;
        }
        temp = temp->next;
    }

    DestroyLinkedListNode(temp);
    return 0;
}

// Calls free() on entire Deque. First free's each element, then the Deque
void destroyDeque(DequePtr deque) {
    if (deque == NULL) return;

    // Check if empty
    if (!dequeIsEmpty(deque)) {
        LinkedListNode* temp = deque->front;

        // Free each element
        while (temp != NULL) {
            DestroyLinkedListNode(temp);
            temp = temp->next;
        }
    }
    free(deque);
}
