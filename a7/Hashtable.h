#include <stdint.h>
#include "LinkedList.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

// Hashtables store key/value pairs. We'll define a key to be an
// unsigned 64-bit integer; it's up to the customer to figure out how
// to produce an appropriate hash key, but below we provide an
// implementation of FNV hashing to help them out.  We'll define
// a value to be a (void *), so that customers can pass in pointers to
// arbitrary structs as values, but of course we have to worry about
// memory management as a side-effect.

// STRUCT DEFINITIONS
//
// We have 2 structs: One is a HTKeyValue, and one is a Hashtable.
//
// This struct represents a hashtable key-value pair that is stored in
// each index of the hashtable's buckets. The value of the key-value pair
// stores a pointer to a LinkedList.
typedef struct {
    uint64_t   key;    // the key in the key/value pair
    LinkedListPtr value;  // the value in the key/value pair
} HTKeyValue, *HTKeyValuePtr;

// This struct represents the entire hashtable. This struct contains
// metadata about the hashtable.
typedef struct hashtableInfo {
    int num_buckets;
    int num_elements;
    HTKeyValuePtr buckets[];
}*Hashtable, HashT;

// METHOD DECLARATIONS

// Method to resize the hashtable when the defined load factor is reached.
//
// INPUT:
//   ht: The current hashtable object.
//
// Returns the same hashtable object, but resized to the new bucket size.
Hashtable ResizeHashtable(Hashtable *ht);

// Method to obtain the index value of where to store the current word given
// a key. Takes the mod of the hash key using the size of the current hashtable.
//
// INPUT:
//   ht: The current ht object.
//   key: The hashkey obtained by sorting the current word and passing it
//        thought the hash function.
//
// Returns the index value of the bucket where to store the string.
int HashKeyToBucketNum(Hashtable ht, uint64_t key);

// Method to get the load factor of the hashtable.
//
// INPUT:
//   hashtable: The current hashtable object.
//
// Returns the load factor of the hashtable which is obtained by
// dividing the number of elements by the number of buckets.
double GetAlpha(Hashtable hashtable);

// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Allocates and returns a new Key-Value pair pointer.
//
// Returns NULL if the keyvaluepair was unable to be malloc'd, else
// the keyvaluepair.
HTKeyValuePtr CreateKVP();

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
void DestroyHashtable(Hashtable ht);

// Destroys and Frees the keyvaluepair.
//
// Input:
//   pair: The keyvaluepair to be free'd. It is unsafe to use the
//    keyvaluepair after this is called.
void DestroyKVP(HTKeyValuePtr pair);

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   kvp: the key-value pair to put into the hashtable.
//
// Returns 0 if put is successful.
// Returns 1 on failure (e.g., no more memory)
// Returns 2 if the key is already in the hashtable
int PutInHashtable(Hashtable ht, char string[]);

// Looks up the given key in the hashtable.
// Returns the Key-Value pair in the provided result pointer.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup
//   result: If the key is in the hashtable, this is used
//      to return a pointer to a HTKeyValue to the caller.
//      Note, this HTKeyValue is still in the hashtable, so can't
//      be used to free the value.
//
// Returns 0 if the lookup was successful (and the result is valid).
// Returns -1 if the key was not found.
int LookupInHashtable(Hashtable ht, uint64_t key, HTKeyValuePtr *result);

// Gets the number of elements in the hashtable.
//
// INPUT:
//   ht: the Hashtable
//
// Returns the number of elements in the hashtable.
int NumElementsInHashtable(Hashtable ht);

// Removes the HTKeyValue with the given key from the
//  hashtable.
//
// INPUT:
//   ht: the hashtable
//   key: the key to remove
//   junkKVP: a pointer to the removed HTKeyValue, to
//     allow the value to be freed by the caller.
//
// Returns 0 if the key was found successfully (and junkKVP is valid)
// Returns -1 if the key was not found in the hashtable.
int RemoveFromHashtable(Hashtable ht, uint64_t key, HTKeyValuePtr *junk_kvp);

// Computes an int from a string, to be used for a key in a HTKeyValue.
//
// INPUT:
//   buffer: a pointer to the array holding the string
//   len: the length of the string
//
// Returns an int to be used as an input to FNVHashInt64 for the hash value.
uint64_t FNVHash64(char *buffer, unsigned int len);

#endif  // HASHTABLE_H
