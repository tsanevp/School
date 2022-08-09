# Assignment 8: Multi-threaded Searching

## My Name:
Peter Tsanev

##  Objectives
* Write a multi-threaded program to search a giant array for a given value.
* Create multiple threads, thread locks, and semaphores.
* Protect shared resources properly.
* Distribute work efficiently among multiple threads/workers.

## Summary
The purpose of this assignment was to familiarize us with multi-threading and distributing work among multiple threads.
The main text file used for this assigment contains 1000 numbers 0-999, where each number is on its own line. The intent
is that each number in the text file will be read and stored into an array, and then array will be evenly split into
sections, where each thread is responsible for search their assigned section. Each thread searches for a given "target"
number, where if found, the number of results is incremented by 1, and the array line the number is on is store in an
array of results. The big focus of this assignment is that all the threads must first be created, THEN the text file
must be read. After it is read, the threads can resume and they can begin searching for the target value.

## Time Spent On Assignment
I spent about 10 hours on this assignment. After watching the youtube channel linked in the external resources used
section, I had pretty good understanding on how to complete the assignment and went for it.

## Collaboration
For this assignment, I did not collaborate with anyone.

## External Resources Used
* https://www.youtube.com/watch?v=xoXzp4B8aQk&ab_channel=CodeVault
Specifically, I watched his entire playlist on Unix Threads in C

## Running my code
* To run my program and ```mt_search.c```, one can call the following commands:
    - Build and run ```mt_search.c``` by calling ```make``` on the command line. This will run the program with my
      defined input file and arguements. This runs the command ```./mt_search inputs/nums1000.txt 1 10 1000```.
    - To run with different parameters, you need to call something like: 
        + ```./mt_search <inputfile> <num_to_find> <num_threads> <num_numbers>```.
    - To run first option with valgrind, call ```make run valgrind```. This runs the command +
        ```valgrind --leak-check=full -s ./mt_search inputs/nums1000.txt 1 10 1000```.
* ```inputs``` is a folder that has files of numbers appropriate for A8. 
    - To see how many numbers are in the file: ```wc -l nums1000.txt``` , where "nums1000.txt" is the file you want to see the number of lines for. 
    - To see which lines (which index) a certain number is on, use the command: ```grep -n 805 nums10000.txt``` (where "805" is the number to search for and "nums10000.txt" is the file to search). This reports line number, which should correspond to the indices of the array you read the values into. It gives you the "right" answer :) 

## Observations Noticed
After running my code on a VM with various numbers of threads and various number of processors, I noticed a
trend in the execution time. As the numbers of threads increased, the longer it took to execute. This is because even
though we assume more threads will mean faster execution, all the threads have a ```SHARED RESOURCE``` which, even if
not all the threads access that resource, they will have to wait on some threads, resulting in slower execution. Thus,
in this implementation, increasing the threads will actually slow down the program.
