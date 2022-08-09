all: sort run 

sort: sort.c linkedlist.c sort.h quicksort.c quicksort.h main.c
	gcc main.c sort.c linkedlist.c quicksort.c -g -o sort

test: linkedlist.c main.c
	gcc -g maintest.c linkedlist.c -o linkedListtest

run: sort
	./sort

clean: 
	rm sort *.~
