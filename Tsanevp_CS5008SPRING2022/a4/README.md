# Assignment A4

## My Name:
Peter Tsanev

##  Objectives
* Start working with `structs`, `header files`, `doubly linked lists`, `deque`.
* Doing more advanced things with `structs` and `data structures`.
* Work with `doubly linked lists` and then using `doubly linked list` to implement `deque`.

## Summary/Overview
For part 1 of this assignment, we started playing around with `doubly linked lists` and `deque`. In A3, it just so
happens that I already implemented a `doubly linked list`, therefore, I just had to make adjustments to the method
requirements for this assignment. For, part 2, I used my `doubly linked list` methods to create a `deque`. Then, in my
main.c function I print each part, where the number of elements in each is up to the user, and test that each method is
functional.

To run the program, type `make -f Makefile` in the command line, and either part 1 or part 2 will run. To run the other
part of the code, you just have to comment the current part that runs, and uncomment the other.

### About The Code
The code does not reley on any external libraries except <stdio.h>, <stdlib.h>, and <time.h>.

## Running and testing a4.c
As mentioned, to run both part 1 and part 2, type `make -f Makefile` in the terminal, and the code will compile and execute.

## Time Spent On Assignment:
Overall I spent about a 15 hours on this assignment. It was a bit more time than I had expected, since I had already
finished the doubly linked list in the previous assignment. I ran into an issue in main that took me a while to realize
my issue. I was not able run part 1 and part 2 concurrently, which I didn't realize, and I was running into seg faults.
I spent too much time trying to looking at my deque.c code thinking it was wrong, when it was just that I needed to
comment out part 1 for it to work.

## What did you like about this assignment?
I really liked working with doubly linked lists and creating a deque.

## How could this assignment be improved?
This assignment could have been improved if the method signitures for the required methods were complete. It was unclear
at first what exactly was expected from us.

## What I learned and found challenging
As mentioned before, I learned that sometimes the issues are not found in the implementation of the data structures but
in the place you least expect, main.c. I spent a good three hours debugging my C code, because the errors did not point
to the fact that I was "redefining a linked list". The issue I was running into was that as soon as I created a deque
with a size larger than my linked list, it would start reaccessing previous memory locations and messing up my deque
order. In the end it would never NULL terminate. Finding and realizing that error was the most challenging and hard part
of the assignment. Other than that, both parts were fairly simple and straightforward. A deque is essentially a linked
list, so it was not hard to create.



