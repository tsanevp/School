#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"
#include "Sort.h"
#include "LinkedList.h"

// Method to convert string to hash-value
uint64_t FNVHash64(char *buffer, unsigned int len) {
    static const uint64_t FNV1_64_INIT = 0xcbf29ce484222325ULL;
    static const uint64_t FNV_64_PRIME = 0x100000001b3ULL;
    unsigned char *bp = (unsigned char *) buffer;
    unsigned char *be = bp + len;
    uint64_t hval = FNV1_64_INIT;
    /*
     * FNV-1a hash each octet of the buffer
     */
    while (bp < be) {
        /* xor the bottom with the current octet */
        hval ^= (uint64_t) * bp++;
        /* multiply by the 64 bit FNV magic prime mod 2^64 */
        hval *= FNV_64_PRIME;
    }
    /* return our new hash value */
    return hval;
}

// Method to allocate memory for and create an empty key-value pair
HTKeyValuePtr CreateKVP() {
    HTKeyValuePtr pair = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
    if (pair == NULL) return NULL;
    pair->key = 0;
    pair->value = CreateLinkedList();
    return pair;
}

// Method to allocate memory for and create and empty hashtable
Hashtable CreateHashtable(int num_buckets) {
    // Used flexible array for hashtable->buckets definition
    Hashtable hashTable = (Hashtable)malloc(sizeof(HashT) +
            num_buckets * sizeof(HTKeyValuePtr));

    if (hashTable == NULL) return NULL;
    hashTable->num_buckets = num_buckets;
    hashTable->num_elements = 0;

    // For each bucket in the hashtable, create a kvp pointer
    int i;
    for (i = 0; i < num_buckets; i++) {
        hashTable->buckets[i] = CreateKVP();
    }
    return hashTable;
}

// Method to obtain the number of elements in the hashtable
int NumElementsInHashtable(Hashtable ht) {
    if (ht == NULL) return -1;
    return ht->num_elements;
}

// Method to resize the hashtable once the load factor is reached
Hashtable ResizeHashtable(Hashtable *ht) {
    Hashtable newTable = CreateHashtable(((*ht)->num_buckets) * 100);
    if (newTable == NULL) return NULL;

    int i;
    for (i = 0; i < (*ht)->num_buckets; i++) {
        HTKeyValuePtr currPair = (*ht)->buckets[i];
        if (currPair->key != 0) {
            // Destroys new kvp and replaces it with one from current ht
            DestroyKVP(newTable->buckets[HashKeyToBucketNum(newTable,
                        abs(currPair->key))]);
            newTable->buckets[HashKeyToBucketNum(newTable, abs(currPair->key))]
                = currPair;
            newTable->num_elements++;
        } else {
            // Destroys kvp from current ht bc it stores an empty kvp
            DestroyKVP(currPair);
        }
    }
    free(*ht);
    return newTable;
}

// Method to get the hashtable index to store the string given a hashvalue
int HashKeyToBucketNum(Hashtable ht, uint64_t key) {
    if (ht == NULL || key == 0) return -1;
    return key % (ht->num_buckets - 1);
}

// Method to get the load factor of the current hashtable
double GetAlpha(Hashtable hashtable) {
    double alpha = ((double)hashtable->num_elements) /
        ((double)hashtable->num_buckets);
    return alpha;
}

// Method to insert the passed string into the hashtable
int PutInHashtable(Hashtable ht, char string[]) {
    if (ht == NULL || string == NULL) return 1;

    // Allocate memory for string that is actually stored within hashtable
    char* tempString = (char*)malloc(sizeof(string) * strlen(string) + 1);
    int j = snprintf(tempString, sizeof(string) * strlen(string) + 1, string);
    if (j < 0) return -1;  /* Error copying string to buffer */

    // Sort the current string, get hash value, and goto index in hashtable
    hybridquicksort(string, 0, strlen(string) - 1);
    uint64_t key = FNVHash64(string, strlen(string));  /* Key to store */
    uint64_t keyToItt = FNVHash64(string, strlen(string));  /* Key to iterate */

    // While loop to iterate key until empty bucket is found
    while (1) {
        HTKeyValuePtr currIndexKVP =
            ht->buckets[HashKeyToBucketNum(ht, keyToItt)];
        if (currIndexKVP == NULL) return 1;
        if (currIndexKVP->key == 0) {  /* Case where bucket is empty */
            currIndexKVP->key = key;
            addRight(currIndexKVP->value, tempString);
            ht->num_elements++;
            return 0;
        } else if (currIndexKVP->key == key &&  /* Chain anagram collision */
                !LinkedListContains(currIndexKVP->value, tempString)) {
            addRight(currIndexKVP->value, tempString);
            return 2;
        }
        keyToItt++;  /* Else iterate key by 1 to see if empty bucket is found */
    }
    return 1;
}

// Method to lookup a passed string in the hashtable and return its pointer
int LookupInHashtable(Hashtable ht, uint64_t key, HTKeyValuePtr *result) {
    if (ht == NULL || result == NULL) return -2;
    HTKeyValuePtr indexAtKey = ht->buckets[HashKeyToBucketNum(ht, key)];
    if (indexAtKey == NULL) return -1;

    int TRUE = 0;
    if (indexAtKey->key == key) {  /* If key matches instantly */
        TRUE = 1;
    } else {  /* Scan hashtable to see if key appears in it */
        int i;
        for (i = 0; i < ht->num_buckets; i++) {
            indexAtKey = ht->buckets[i];
            if (indexAtKey == NULL) return -1;
            if (indexAtKey->key == key) {  /* If key at current index matches */
                TRUE = 1;
                break;
            }
        }
    }
    if (!TRUE) return -1;  /* Return error code if key not in hashmap */
    // Frees pointer contents and assigns it to index contents
    free(*result);
    *result = indexAtKey;
    return 0;
}

// Method to remove the passed string from the hashtable, if possible
int RemoveFromHashtable(Hashtable ht, uint64_t key, HTKeyValuePtr *junk_kvp) {
    if (ht == NULL || junk_kvp == NULL) return -2;
    HTKeyValuePtr pairToRemove = ht->buckets[HashKeyToBucketNum(ht, key)];
    if (pairToRemove == NULL) return -1;

    int TRUE = 0;
    if (pairToRemove->key == key) {  /* If key matches instantly */
        TRUE = 1;
    } else {  /* Scan hashtable to see if key appears in it */
        int i;
        for (i = 0; i < ht->num_buckets; i++) {
            pairToRemove = ht->buckets[i];
            if (pairToRemove == NULL) return -1;
            if (pairToRemove->key == key) {  /* If key at currIndex matches */
                TRUE = 1;
                break;
            }
        }
    }
    if (!TRUE) return -1;  /* Return error code if key not in hashmap */
    // Frees pointer contents and assigns it to index contents, removes index
    free(*junk_kvp);
    *junk_kvp = pairToRemove;
    ht->buckets[HashKeyToBucketNum(ht, key)] = CreateKVP();
    ht->num_elements--;
    return 0;
}

// Method to destroy the hashtable by free'ing it all
void DestroyHashtable(Hashtable ht) {
    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        DestroyLinkedList(ht->buckets[i]->value);
        free(ht->buckets[i]);
    }
    free(ht);
}

// Method to only destroy and free a key value pair
void DestroyKVP(HTKeyValuePtr pair) {
    DestroyLinkedList(pair->value);
    free(pair);
}
