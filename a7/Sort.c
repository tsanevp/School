#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Sort.h"

#define MAXLEN 10
#define INITIALINDEX 0
#define INITIALSIZE 1
#define INCREMENTVALUE 1

// ======================================================================
// The following section contains methods to sort an interger array
// ======================================================================

// Method to swap two elements within an array
void swap(char string[], int left, int right) {
    char temp = string[left];
    string[left] = string[right];
    string[right] = temp;
}

// Standard insertion sort algorithm
void insertionsort(char string[], int start, int end) {
    int curr, i, j;

    // Sort assumes 0 index to be sorted, start at index 1
    for (i = start + INCREMENTVALUE; i <= end; i++) {
        curr = string[i];
        j = i - INCREMENTVALUE;
        while (j >= INITIALINDEX && string[j] > curr) {
            string[j + INCREMENTVALUE] = string[j];
            j--;
        }
        string[j + INCREMENTVALUE] = curr;
    }
}

// Standard quicksort algorithm
void quicksort(char string[], int start, int end) {
    // Check for base cases
    if (start >= end) return;

    // Select a pivot
    // Partition around pivot
    int pivot = partition(string, start, end);

    // Recurse on the left and right
    quicksort(string, start, pivot - INCREMENTVALUE);
    quicksort(string, pivot + INCREMENTVALUE, end);
}

// Methods to calculate current pivot within quicksort
int partition(char string[], int pivot, int end) {
    // Check for base cases
    // If pivot == end || end - pivot == 1 && list[end] > list[pivot] return
    // If value to right is larger, swap with end
    // If value to right is smaller, swap with pivot
    if (pivot == end || (end - pivot == INITIALSIZE &&
        string[pivot] < string[end])) {
        return pivot;
    }
    if (string[pivot] < string[pivot + INCREMENTVALUE]) {
        swap(string, pivot + INCREMENTVALUE, end);
        return partition(string, pivot, end - INCREMENTVALUE);
    } else {
        swap(string, pivot, pivot + INCREMENTVALUE);
        return partition(string, pivot + INCREMENTVALUE, end);
    }
}

// Hybrid sorting algorithm that combines quicksort and insertion sort.
void hybridquicksort(char string[], int start, int end) {
    while (start < end) {
        if ((end - start) <  MAXLEN) {
            insertionsort(string, start, end);
            break;
        } else {
            int pivot = partition(string, start, end);
            if (pivot - start < end - pivot) {
                hybridquicksort(string, start, pivot - INCREMENTVALUE);
                start = pivot + INCREMENTVALUE;
            } else {
                hybridquicksort(string, pivot + INCREMENTVALUE, end);
                end = pivot - INCREMENTVALUE;
            }
        }
    }
}
