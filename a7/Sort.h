#ifndef SORT_H
#define SORT_H

// ======================================================
// Quicksort: A sorting algorithim used to sort an array.
// ======================================================

// Swaps the left element with the right element in an array
// list if the left value is greater than the right.
//
// INPUT: An array list.
// INPUT: The index of the left value.
// INPUT: The index of the right value.
void swap(char* string, int left, int right);

// Quick sort sorting alogrithm.
//
// INPUT: An array list.
// INPUT: The first index in the unsorted array.
// INPUT: The last index in the unsorted array.
void quicksort(char* string, int start, int end);

// The main process in the quicksort method. Puts values
// smaller than it before, larger than it after.
//
// INPUT: An array list.
// INPUT: The pivot index in the unsorted array.
// INPUT: The last index in the unsorted array.
int partition(char* string, int pivot, int end);

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
void insertionsort(char* string, int start, int end);

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
void selectionsort(char* string, int start, int end);

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
void hybridquicksort(char* string, int start, int end);

#endif
