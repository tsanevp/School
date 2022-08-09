# Assignment A7: Hashtables

## My Name:
Peter Tsanev

##  Objectives
* Create a hashtable given the starter code.
* The code successfully parses through a given .txt file and stores words in hashtable.
* Any collisions that occur within the hash table are chained using a linked list.

## Summary
The purpose of this assignment was to familiarize us with hashtables and their use. We were given a large .txt with over
400,000 words, where we must store each individual word within the hash table. To do so, we must parse through the text
file line by line, sort the word, pass it through a hashing function, pass the hash value to a hashtoindex function, and
then store in the hashtable. Since there are so many words to store, inevitably a collision will occur. There are two
cases of collisions that can occur. One case is that when two different words get sorted, they have the same sorted
string, which leads to them having the same hash and index value. In this case, I directly chain the two original
strings in a linked list since they are anagrams. In the other case, two different words get sorted, have different
sorted strings and hash values, but produce the same index in the hashtable. This is a bad collision. I decided to
handle these collisions by incrementing a copy of the hash value until I come accross an empty bucket, in other words I
apply linear probing.

## Things Considered
~~It was unclear in the assignment description and on piazza for what to do if a collision, where two keys are not the~~
~~same, occurs. If we were to perform linear probing or any other method, we lose the O(1) look-up time of a real hash~~
~~table, thus, I just chained all collisions.~~

~~EDIT: I have fixed the error where chaining occurs with even non-anagrams. However, you losed O(1) lookup time, and thus~~
~~I have left my old code in, but commented out. To still get O(1) look up time, comment out the while loop in~~
~~PutInHashTable, and uncomment the block underneath.~~

EDIT: After reviewing the problem with Drew in class (4/14), the original intent behind how Drew would have implemented
the hashtable became clear. However, as seen above, prior to class, the problem description and what was expected
overall with chaining and handling collisions was quite unclear. Furthermore, the assignment definition states that we
have freedom to decide what route to take, and as long as the list of anagrams are printed, we are good. This is why I
decide to go the route of chaining good collisions, when two anagrams collide, and then perfrom linear probing for when
a bad collision occurs.

## Collaboration
For this assignment, I discussed some methods with Lena and Brian and we helped each other solve some errors with our
code a few times.

## External Resources Used
* https://stackoverflow.com/questions/37178921/is-it-possible-to-set-the-size-of-an-array-within-structure-during-runtime/37178989#37178989
* https://wiki.sei.cmu.edu/confluence/display/c/DCL38-C.+Use+the+correct+syntax+when+declaring+a+flexible+array+member
* https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input#:~:text=You%20can%20simply%20do%20if,stdin)%20%3D%3D%20NULL)%20%7B%7D%20.&text=Not%20sure%20why%20you%20would,of%20%22removing%22%20the%20newline.

## Running my code
* To run my program, one needs Main.c and all its dependencies. To do so, call `make run` and Main.c and all necessary files will compile and run.
* Running only `make` will run all the implemented tests for my code.

### Expected Output
When `make run` is called is called, the program will iterate though the hashable buckets and print the linked list
stored. Thus, the expected output is thousands of lines of linked lists that contain anagrams printed to the command
line.

## File Decriptions
* Hashtable.h - Header file for Hashtable.c that contains all the struct definitions and method signitures to create a
                hashtable
* Hashtable.c - C file that creates each method and builds the hashtable to meet the assignment requirements
* LinkedList.h - Header file for LinkedList.c that contains all the struct definitions and method signitures to create a
  linked list
* LinkedList.c - C file that creates each method needed to build and create a linked list
* Sort.h - Header file for Sort.c that contains all the method signitures used in Sort.c
* Sort.c - C file that creates each sorting method. For this assignment, we use a hybrird quicksort to sort the words

## Time Spent On Assignment:
Overall, I spent over 24 hours on this assignment. The main reason being is that the given starter code took me a while
to understand, and made the assignment a bit more difficult to actually start. After, I had to deal with tons of memory
leaks from poor malloc definitions.

## What did you like about this assignment?
This assignment helped me really understand the importance of tracking pointers and allocating memory correctly. It also
helped me develop my skills in debugging memory leaks and errors.

## How could this assignment be improved?
This assignment could be improved in a few ways. The given starter code ended up making the assignment a little more
confusing, and ended up making me spend more hours trying to understand it, than actually writing code. A bit more
intro and descriptions would have been helpful. 

EDIT: Giving us the instructions to chain collisions is too vauge. One can not neccessary tell if you define a collision
as two words that are anagrams of each other and share the same key and index, or if you mean two words who are
completely unrelated, share different keys, but have the same index. In a normal map, if there is a collision where the
keys are the same, the value gets replaces. Thus, giving us the instruction to chain collisions can very easily be
understood as chain only anagrams.

One good way to give assigment descriptions would be to show a quick figure of the expected output, similar to leetcode
problems.

## Testing and Clint.py
All methods in Hashtable.c have been tested and verified they word. Testing has been implemented using GoogleTest and
allowed for the proper testing of the methods.

All .h and .c files have also been cleared of any pystyle errors.
