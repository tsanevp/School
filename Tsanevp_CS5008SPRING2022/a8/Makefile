all: build clean

mt_search: mt_search.c
	gcc -pthread -o mt_search mt_search.c

build: mt_search
	./mt_search inputs/nums1000.txt 1 50 1000

run valgrind: mt_search
	valgrind --leak-check=full -s ./mt_search inputs/nums1000.txt 1 50 1000 

clean:
	rm mt_search
