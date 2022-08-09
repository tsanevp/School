#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

// ===================================================
// Global Variables
// ===================================================

#define MAX_NUM_RESULTS 100
#define MAX_LINE_LENGTH 8192

// Section size each thread should handle when searching array
int sectionSize;

// File path of text file containing numbers
char* fileName;

// Number of lines in text file containing numbers
int numLines;

// Number of threads to create
int numThreads;

// Array of numbers to search
int *data;

// Number to be found
int target;

// Array of indices of target number
int *results;

// Number of results we have so far
int num_results = 0;

// Thread lock to prevent multiple threads from writing simultaneously
pthread_mutex_t lock;

// Semaphore that allows threads to wait for file to be read
sem_t semaphore;

// All the threads (an array)
pthread_t* threads;

// ===================================================
// Functions
// ===================================================

// Method to return the min of two integers
//
// INPUTS:
//  num1 - The first number
//  num2 - The second number
//
// Returns the minimum of num1 and num2
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

// The function that each thread will run to look for the target value in
// the array. The argument provided is the current number thread created
// passed as an int pointer. The int is then used to create the start and
// end index the thread will look in.
// Each thread will look at a max of section_size elements.
//
// INPUTS:
//  arguments - A generic input. In this case it the current thread number
//              passed as an int.
void* DoSearch(void* arguements) {
    int i = *(int*)arguements;

    // Create the start and end index of the thread should look in
    int start = i * sectionSize;
    int end = min((i + 1) * sectionSize, numLines);

    // Causes the threads to wait for the data file to read
    sem_wait(&semaphore);

    // Serach for target in current thread's assigned section
    for (start; start < end; start++) {
        if (data[start] == target) {
            // If there is a match, lock thread, write, unlock
            pthread_mutex_lock(&lock);
            results[num_results] = start + 1;
            num_results++;
            pthread_mutex_unlock(&lock);
        }
    }
    free(arguements);
}

// Creates all the threads and starts them running.
// Makes sure the thread IDs are stored in the global threads array.
void MakeThreads() {
    threads = (pthread_t*)malloc(sizeof(pthread_t) * numThreads);

    int i;
    for (i = 0; i < numThreads; i++) {
        int* arg = (int*)malloc(sizeof(*arg));
        *arg = i;
        if (pthread_create(&threads[i], NULL, &DoSearch, arg) != 0) {
            perror("Failed to create thread i...");
        }
    }
}

// Joins all the threads after they are done searching for the target
void JoinThreads() {
    int i;
    for (i = 0; i < numThreads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread i...");
        }
    }
    free(threads);
}

// Opens the file called filename. Reads line by line, adding each number
// to the global data array.
void ReadFile(char* filename) {
    FILE *wordFile = fopen(fileName, "r");
    if (wordFile == NULL) {
        perror("Unable to open args[1], try again....");
    }

    data = (int*)malloc(sizeof(*data) * numLines);
    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), wordFile)) {
        data[i] = atoi(line);
        i++;
    }
    fclose(wordFile);

    // Allows threads to continue running once file has been fully read
    for (i = 0; i < numThreads; i++) {
        sem_post(&semaphore);
    }
}

// Prints out the results, stored in the global "results" array.
void PrintResults() {
    printf("---------------------------------------------------------------\n");
    printf("Line numbers that hold the target value are: ");
    int i;
    for (i = 0; i < num_results; i++) {
        if (&(results[i]) != NULL && i == num_results - 1) {
            printf("%d\n", results[i]);
        } else if (&(results[i]) != NULL) {
            printf("%d, ", results[i]);
        }
    }
    printf("---------------------------------------------------------------\n");
}

int main(int num_args, char* args[]) {
//    clock_t begin = clock();

    // Initialize thread lock and semaphore
    pthread_mutex_init(&lock, NULL);
    sem_init(&semaphore, 0, 0);

    // Ensure that the required number of args are passed and file path is valid
    if (num_args != 5) return -1;
    if (args[1] == NULL) return -2;

    fileName = args[1];
    target = atoi(args[2]);
    numThreads = atoi(args[3]);
    numLines = atoi(args[4]);

    results = (int*)malloc(sizeof(*results) * MAX_NUM_RESULTS);
    sectionSize = numLines/numThreads;

    // Create the threads
    MakeThreads();
    // Read the file
    ReadFile(fileName);
    // Join the threads
    JoinThreads();
    // Prints results
    PrintResults();

    // Destroy lock and semaphore & free allocated memory
    pthread_mutex_destroy(&lock);
    sem_destroy(&semaphore);
    free(data);
    free(results);
/*
    clock_t end = clock();
    double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 10e6;
    printf("The execution time is: %f\n", time_spent);
*/
    return 0;
}
