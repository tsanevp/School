#ifndef QUICKSORT_H
#define QUICKSORT_H

// ======================================================
// Array: This sections contains structs and methods used
// to create/modify the int arrays used in the sorting
// algorithms below.
// ======================================================

// STRUCT DEFINITIONS

// This struct represents the entire int array. We provide
// struct declaration (but not definition) in quicksort.h;
// this is the associated definition. This struct contains
// metadata about the int array.
typedef struct AList {
    int* list;
    int length;
}AList, *AListPtr;

// Prints out the given array list.
//
// INPUT: An array list.
void printAll(AList* alist);

// Inserts an element to the end of the array, with the given value.
//
// INPUT: An array list.
// INPUT: The value to be added to the array list.
void add(AList* alist, int val);

// Creates an Array list whose initial value is the given value.
//
// INPUT: The first value of an array list.
//
// Returns a pointer to the first value in the array list.
AList* create(int val);

/// Destroys the interger array list. Calls free on array list itself
// and then the struct storing the list.
//
//  INPUT: An array list.
void destroyArrayList(AList* alist);

// ======================================================
// Quicksort: A sorting algorithim used to sort an array.
// ======================================================

// Swaps the left element with the right element in an array
// list if the left value is greater than the right.
//
// INPUT: An array list.
// INPUT: The index of the left value.
// INPUT: The index of the right value.
void swap(AList* alist, int left, int right);

// Quick sort sorting alogrithm.
//
// INPUT: An array list.
// INPUT: The first index in the unsorted array.
// INPUT: The last index in the unsorted array.
void quicksort(AList* alist, int start, int end);

// The main process in the quicksort method. Puts values
// smaller than it before, larger than it after.
//
// INPUT: An array list.
// INPUT: The pivot index in the unsorted array.
// INPUT: The last index in the unsorted array.
int partition(AList* alist, int pivot, int end);

// ======================================================
// Insertionsort: A sorting algorithim used to sort an array.
// ======================================================

// The insertion sort algorith sorts an array like you would
// sort normal playing cards. It creates two subarrays, sorted
// and unsorted, and as it makes it way down the list, places
// the current value in the proper position within the sorted
// array portion.
//
// INPUT: An array list.
void insertionsort(AList* alist, int start, int end);

// ======================================================
// Selectionsort: A sorting algorithim used to sort an array.
// ======================================================

// The selection sort algorithm sorts an array by repeatedly
// finding the smallest value in the unsorted portion of the list
// and swapping it with the first value in the unsorted portion of
// the list. The sort starts at the 0 index of the list and continues
// till listlength-1 is reached. The algorithm maintains two subarrays,
// the sorted and the unsorted.
//
// INPUT: An array list.
void selectionsort(AList* alist, int start, int end);

// ======================================================
// HybringQuickSort: A hybrid sorting algorith mixed with
//                   quicksort and insertion sort.
// ======================================================

// This hybrid sorting algorithm mixes quicksort with insertion sort.
// Quicksort is efficient when the size of the array is very large,
// but insertion sort is more efficient than quicksort when the size
// is about ten elements or less. Thus, this sorting algorith will
// apply insertion sort if the current full/sub array has ten elemenets
// or less, and quicksort if not. This process will repeat until the
// array is fully sorted.
//
// INPUT: An array list.
// INPUT: The first index in the unsorted array.
// INPUT: The last index in the unsorted array.
void hybridquicksort(AList* alist, int start, int end);

#endif
