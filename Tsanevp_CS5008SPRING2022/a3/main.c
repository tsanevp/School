#include <stdio.h>
#include <time.h>
#include "sort.h"
#include "linkedlist.h"
#include "quicksort.h"

// ***************************************************************************
// Below are some helper methods used to help with timing how long sorts take.
// ***************************************************************************

// A method to find the time it takes to sort a linked list using insertion
// sort.
double timeInsertionSortLL(int numValues) {
    LinkedListPtr LinkedList = CreateLinkedList();
    if (LinkedList == NULL) return;

    int i;
    clock_t begin, end;
    srand(time(NULL));

    // Creates linked list with size numValues
    for (i = 0; i < numValues; i++) {
        int r = rand() % numValues;
        AppendLinkedList(LinkedList, r);
    }

    // Time sort operation
    begin = clock();
    Sort(LinkedList);
    end = clock();
    double timeSpent = ((double)(end - begin)*1e6) / CLOCKS_PER_SEC;

    // Free linked list
    DestroyLinkedList(LinkedList);

    return timeSpent;
}

// A method to create an interger array whose size is passes as an input.
//
// Returns: A pointer to the array in memory.
AList* makeIntArray(int numValues) {
    // Create first random element in interger array
    srand(time(NULL));
    int head = rand() % numValues;
    AList* alist = create(head);

    // For loop to add numValues more random value elements to array
    int i;
    for (i = 0; i < numValues; i++) {
        int r = rand() % numValues;
        add(alist, r);
    }

    return alist;
}

// Method that calculates the time taken for each sort to complete, if print
// is enabled, will print the progress of each sort.
//
// The method takes the number of random values to add to the list as one input,
// while the rest of the inputs are pointers to the memory locations of where to
// store the sort times.
void timeOfSorts(int numValues, double *timeQuick, double *timeInsertion,
        double *timeSelection, double *timeHybrid, int print) {
    int num_sorts = 4;
    int i;

    for (i = 0; i < num_sorts; i++) {
        AList* alist = makeIntArray(numValues);
        if (print == 1) {
            printf("----- Unsorted Array List -----\n");
            printAll(alist);
            printf("----- ...Sorting array... -----\n");
        }
        clock_t begin, end;
        if (i == 0) {
            begin = clock();
            quicksort(alist, 0, alist->length-1);
            end = clock();
            *timeQuick = ((double)(end - begin)*1e6) / CLOCKS_PER_SEC;
            if (print == 1) {
                printf("----- Quicksort complete -----%48s\n");
                printAll(alist);
                printf("================================================\n");
            }
        } else if (i == 1) {
            begin = clock();
            insertionsort(alist, 0, alist->length-1);
            end = clock();
            *timeInsertion = ((double)(end - begin)*1e6) / CLOCKS_PER_SEC;
            if (print == 1) {
                printf("----- InsertionSort Complete -----\n");
                printAll(alist);
                printf("================================================\n");
            }
        } else if (i == 2) {
            begin = clock();
            selectionsort(alist, 0, alist->length-1);
            end = clock();
            *timeSelection = ((double)(end - begin)*1e6) / CLOCKS_PER_SEC;
            if (print == 1) {
                printf("----- SelectionSort Complete -----\n");
                printAll(alist);
                printf("================================================\n");
            }
        } else {
            begin = clock();
            hybridquicksort(alist, 0, alist->length-1);
            end = clock();
            *timeHybrid = ((double)(end - begin)*1e6) / CLOCKS_PER_SEC;
            if (print == 1) {
                printf("----- Hybrid QuickSort Complete -----\n");
                printAll(alist);
                printf("================================================\n");
            }
        }
        destroyArrayList(alist);
    }
    if (print == 1) {
        printf("----- End Of Testing Part 2 -----\n");
    }
}

int main() {
    // =========================================================
    // Assignment 3, Part 1
    // =========================================================
    int numValues = 50;  // Length linked list and num elements to add to array
    int i;

    // Random number generator
    srand(time(NULL));

    // Creates the initial empty linked list
    LinkedListPtr LinkedList = CreateLinkedList();

    // Creates linked list with size numValues
    for (i = 0; i < numValues; i++) {
        int r = rand() % 1000;
        AppendLinkedList(LinkedList, r);
    }

    // Print the following series of event for linked list:
    // - Unsorted linked list
    // - Testing InsertLinkedList and InsertInsideLinkedList functions
    // - Sorted linked list
    // - Destroy and free linked list and its nodes
    printf("\n\n");
    printf("===============================================\n");
    printf("----- Start of Testing Part 1-----\n");
    printf("----- Unsorted Linked List -----\n");
    PrintLinkedList(LinkedList);
    printf("================================================\n");
    printf("----- Tesing Linked List Functions-----\n");
    printf("Insert element with value 1000 to the head of LL\n");
    InsertLinkedList(LinkedList, 1000);
    printf("Insert an element at node 3 position with a value of 4000\n");
    InsertInsideLinkedList(LinkedList, 4000, 3);
    PrintLinkedList(LinkedList);
    printf("===============================================\n");
    printf("----- Sorted Linked List -----\n");
    Sort(LinkedList);
    PrintLinkedList(LinkedList);
    printf("===============================================\n");
    printf("----- End Of Testing Part 1-----\n");

    // ===========================================================
    // Assignment 3, Part 2
    // ===========================================================

    // Define pointers to store the execution time for each sorting algorithm
    double* timeQuick = (double*)malloc(sizeof(double));
    double* timeInsertion = (double*)malloc(sizeof(double));
    double* timeSelection = (double*)malloc(sizeof(double));
    double* timeHybrid = (double*)malloc(sizeof(double));

    printf("\n\n");
    printf("===============================================\n");
    printf("----- Start of Testing Part 2-----\n");

    // Call timeOfSorts with less elements and with print enabled
    timeOfSorts(25, timeQuick, timeInsertion, timeSelection, timeHybrid, 1);

    printf("\n\n");
    printf("===============================================\n");
    printf("----- Sorts Time Comparision Part 2-----\n");

    // Get and print the time of each sort -> 5 elements
    timeOfSorts(5, timeQuick, timeInsertion, timeSelection, timeHybrid, 0);
    printf(" Size  |  Quick Sort   Insertion Sort   Selection Sort   \
    Hybrid Quick Sort\n");
    printf("  5    |    %.2f          %.2f             %.2f                \
    %.2f\n", *timeQuick, *timeInsertion, *timeSelection, *timeHybrid);

    // Get and print the time of each sort -> 50 elements
    timeOfSorts(50, timeQuick, timeInsertion, timeSelection, timeHybrid, 0);
    printf(" Size  |  Quick Sort   Insertion Sort   Selection Sort   \
    Hybrid Quick Sort\n");
    printf(" 50    |    %.2f          %.2f             %.2f                \
    %.2f\n", *timeQuick, *timeInsertion, *timeSelection, *timeHybrid);

    // Get and print the time of each sort -> 500 elements
    timeOfSorts(500, timeQuick, timeInsertion, timeSelection, timeHybrid, 0);
    printf(" Size  |  Quick Sort   Insertion Sort   Selection Sort   \
    Hybrid Quick Sort\n");
    printf(" 500   |    %.2f          %.2f             %.2f                \
    %.2f\n", *timeQuick, *timeInsertion, *timeSelection, *timeHybrid);

    // Get and print the time of each sort -> 5000 elements
    timeOfSorts(5000, timeQuick, timeInsertion, timeSelection, timeHybrid, 0);
    printf(" Size  |  Quick Sort   Insertion Sort   Selection Sort   \
    Hybrid Quick Sort\n");
    printf(" 5000  |    %.2f          %.2f        %.2f              %.2f\n",
    *timeQuick, *timeInsertion, *timeSelection, *timeHybrid);

    // Get and print the time of each sort -> 10000 elements
    timeOfSorts(10000, timeQuick, timeInsertion, timeSelection, timeHybrid, 0);
    printf(" Size  |  Quick Sort   Insertion Sort   Selection Sort   \
    Hybrid Quick Sort\n");
    printf(" 10000 |    %.2f        %.2f        %.2f           %.2f\n",
    *timeQuick, *timeInsertion, *timeSelection, *timeHybrid);

    // Repeatedly timeOfSorts with print disabled and various element sizes to
    // calculate execution times for each sorting algorithm
    DestroyLinkedList(LinkedList);
    free(timeQuick);
    free(timeInsertion);
    free(timeSelection);
    free(timeHybrid);

    return 0;
}
