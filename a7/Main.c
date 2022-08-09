#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"
#include "LinkedList.h"
#include "Hashtable.h"

#define FILENAME "words.txt"
#define MAXLINELEN 8192
#define INITIALBUCKETS 2500

int main() {
    Hashtable ht = CreateHashtable(INITIALBUCKETS);

    FILE *wordFile = fopen(FILENAME, "r");
    if (wordFile == NULL) {
        perror("Unable to open FILENAME... try again");
        exit(1);
    }

    char line[MAXLINELEN];
    int k = 0;
    while (fgets(line, sizeof(line), wordFile)) {
        line[strcspn(line, "\n")] = 0;

        if (GetAlpha(ht) > 0.5) {
            ht = ResizeHashtable(&ht);
        }
        PutInHashtable(ht, line);
        k++;
    }

    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        HTKeyValuePtr temp = ht->buckets[i];
        PrintLinkedList(temp->value);
    }

    fclose(wordFile);
    DestroyHashtable(ht);
    return 0;
}
