#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quicksort.h"

// ======================================================================
// The following section contains methods to define and create int arrays
// ======================================================================

// Method to create an array list
AList* create(int val) {
    int* l = (int*)malloc(sizeof(int));

    if (l == NULL) return;
    l[0] = val;

    AList* alist = (AList*)malloc(sizeof(AList));
    if (alist == NULL) return;
    alist->list = l;    // Assign l to 0 index
    alist->length = 1;  // Set initial length

    return alist;
}

// Method to add an element to the end of an array list
void add(AList* alist, int val) {
    int* arr = (int*)malloc(sizeof(int) * (alist->length + 1));
    if (arr == NULL) return;

    int* temp = alist->list;

    int i;
    for (i = 0; i < alist->length; i++) {
        arr[i] = alist->list[i];
    }
    arr[alist->length] = val;
    alist->list = arr;
    alist->length = alist->length + 1;
    free(temp);
}

// Method to print an array
void printAll(AList* alist) {
    int i;
    for (i = 0; i < alist->length; i++) {
        printf("%d ", alist->list[i]);
    }
    printf("\n");
}

// Method to swap two elements within an array
void swap(AList* alist, int left, int right) {
    int temp = alist->list[left];
    alist->list[left] = alist->list[right];
    alist->list[right] = temp;
}

// Method to destroy the array and each of its elements
void destroyArrayList(AList* alist) {
    if (alist == NULL) return;

    free(alist->list);
    free(alist);
}

// ======================================================================
// The following section contains methods to sort an interger array
// ======================================================================

// Standard insertion sort algorithm
void insertionsort(AList* alist, int start, int end) {
    int curr, i, j;
    i = start + 1;\

    // Sort assumes 0 index to be sorted, start at index 1
    for (i; i <= end; i++) {
        curr = alist->list[i];
        j = i - 1;
        while (j >= 0 && alist->list[j] > curr) {
            alist->list[j+1] = alist->list[j];
            j--;
        }
        alist->list[j+1] = curr;
    }
}

// Standard selection sort algorithm
void selectionsort(AList* alist, int start, int end) {
    int curr, i, j, minIndex;

    for (i = start; i <= end; i++) {
        curr = alist->list[i];
        minIndex = i;
        j = i + 1;
        while (j <= end) {
            if (alist->list[minIndex] > alist->list[j]) {
                minIndex = j;
            }
            j++;
        }
        if (i != minIndex) {
            swap(alist, i, minIndex);
        }
    }
}

// Standard quicksort algorithm
void quicksort(AList* alist, int start, int end) {
    // Check for base cases
    if (start >= end) return;

    // Select a pivot
    // Partition around pivot
    int pivot = partition(alist, start, end);

    // Recurse on the left and right
    quicksort(alist, start, pivot - 1);
    quicksort(alist, pivot + 1, end);
}

// Methods to calculate current pivot within quicksort
int partition(AList* alist, int pivot, int end) {
    // Check for base cases
    // If pivot == end || end - pivot == 1 && list[end] > list[pivot] return
    // If value to right is larger, swap with end
    // If value to right is smaller, swap with pivot
    if (pivot == end || (end - pivot == 1 &&
        alist->list[pivot] < alist->list[end])) {
        return pivot;
    }
    if (alist->list[pivot] < alist->list[pivot + 1]) {
        swap(alist, pivot + 1, end);
        return partition(alist, pivot, end - 1);
    } else {
        swap(alist, pivot, pivot + 1);
        return partition(alist, pivot + 1, end);
    }
}

// Hybrid sorting algorithm that combines quicksort and insertion sort.
void hybridquicksort(AList* alist, int start, int end) {
    while (start < end) {
        int maxLen = 10;
        if ((end - start) <  maxLen) {
            insertionsort(alist, start, end);
            break;
        } else {
            int pivot = partition(alist, start, end);
            if (pivot - start < end - pivot) {
                hybridquicksort(alist, start, pivot - 1);
                start = pivot + 1;
            } else {
                hybridquicksort(alist, pivot + 1, end);
                end = pivot - 1;
            }
        }
    }
}

