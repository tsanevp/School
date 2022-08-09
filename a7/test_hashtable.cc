#include "gtest/gtest.h"
extern "C" {
#include "Hashtable.h"
#include "LinkedList.h"
#include "Sort.h"
}
const char* first = "first";
const char* second="second";
const char* third = "third";
const char* fourth = "fourth";

#define MAX_VALUE_LEN 75

TEST(Test, Test) {
    EXPECT_TRUE(true);
}

TEST(Hashtable, Create) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_FALSE(ht == NULL);
    EXPECT_FALSE(ht->buckets == NULL);
    EXPECT_EQ(NumElementsInHashtable(ht), 0);
    EXPECT_EQ(ht->num_buckets, 5);
    DestroyHashtable(ht);
}

TEST(HTKeyValue, Create) {
    HTKeyValuePtr kvp = CreateKVP();
    EXPECT_FALSE(kvp == NULL);
    EXPECT_FALSE(kvp->value == NULL);
    EXPECT_EQ(kvp->key, 0);
    DestroyKVP(kvp);
}

TEST(Hashtable, AddOneRemoveOne) {
    Hashtable ht = CreateHashtable(5);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    char const* newString = "hello";
    PutInHashtable(ht, string);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    int i;
    for(i = 0; i < ht->num_buckets; i++) {
        HTKeyValuePtr kvp = ht->buckets[i];
        if (kvp->key != 0) {
            EXPECT_TRUE(!strcmp(kvp->value->head->data, newString));
        }
    }
    HTKeyValuePtr junk = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
    RemoveFromHashtable(ht, FNVHash64(string, strlen(string)), &junk);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);
    DestroyHashtable(ht);
    DestroyKVP(junk);
}

TEST(Hashtable, AddOneElemDestroy) {
    Hashtable ht = CreateHashtable(5);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    PutInHashtable(ht, string);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    DestroyHashtable(ht);
}

TEST(Hashtable, AddOneElemTwoTimes) {
    Hashtable ht = CreateHashtable(5);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    int result = PutInHashtable(ht, string);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    // Trying to put it in again should result in an error
    result = PutInHashtable(ht, string);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    // Define string to add to hashtable
    char string2[] = "SIR";
    result = PutInHashtable(ht, string2);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 2);

    DestroyHashtable(ht);
}

TEST(Hashtable, AddOneRemoveTwice) {
    Hashtable ht = CreateHashtable(5);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    char const* newString = "hello";
    int result = PutInHashtable(ht, string);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    HTKeyValuePtr junk = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));

    result = RemoveFromHashtable(ht, FNVHash64(string, strlen(string)), NULL);
    EXPECT_EQ(result, -2);

    result = RemoveFromHashtable(NULL, FNVHash64(string, strlen(string)), &junk);
    EXPECT_EQ(result, -2);

    result = RemoveFromHashtable(ht, FNVHash64(string, strlen(string)), &junk);
    EXPECT_EQ(result, 0);
    EXPECT_TRUE(!strcmp(junk->value->head->data, newString));

    result = RemoveFromHashtable(ht, FNVHash64(string, strlen(string)), &junk);
    EXPECT_EQ(result, -1);

    DestroyHashtable(ht);
    DestroyKVP(junk);
}

TEST(Hashtable, AddMultipleItems) {
    Hashtable ht = CreateHashtable(100);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    int result = PutInHashtable(ht, string);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    // Define string to add to hashtable
    char string1[] = "omg";
    result = PutInHashtable(ht, string1);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 2);

    // Define string to add to hashtable
    char string2[] = "yerd";
    result = PutInHashtable(ht, string2);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 3);

    DestroyHashtable(ht);
}

TEST(Hashtable, LookupInHashtable) {
    Hashtable ht = CreateHashtable(100);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    char const* newString = "hello";
    int result = PutInHashtable(ht, string);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    // Define string to add to hashtable
    char string1[] = "omg";
    result = PutInHashtable(ht, string1);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 2);

    // Define string to add to hashtable
    char string2[] = "yerd";
    result = PutInHashtable(ht, string2);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 3);

    HTKeyValuePtr lookup_result = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));

    result = LookupInHashtable(ht, FNVHash64(string, strlen(string)), NULL);
    EXPECT_EQ(result, -2);

    result = LookupInHashtable(NULL, FNVHash64(string, strlen(string)), &lookup_result);
    EXPECT_EQ(result, -2);

    // Now, lookup:
    result = LookupInHashtable(ht, FNVHash64(string, strlen(string)), &lookup_result);
    EXPECT_EQ(result, 0);
    EXPECT_TRUE(!strcmp(lookup_result->value->head->data, newString));
    EXPECT_EQ(NumElementsInHashtable(ht), 3);

    // Test looking up something not in the table
    HTKeyValuePtr lookup_invalid = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
    // Now, lookup:
    char string3[] = "cow";
    result = LookupInHashtable(ht, FNVHash64(string3, strlen(string3)), &lookup_invalid);
    EXPECT_EQ(result, -1);
    DestroyHashtable(ht);
    free(lookup_invalid);
}

TEST(Hashtable, TwoElemsOneBucket) {
    Hashtable ht = CreateHashtable(100);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);

    // Define string to add to hashtable
    char string[] = "hello";
    char const* newString = "hello";
    int result = PutInHashtable(ht, string);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 1);

    // Define string to add to hashtable
    char string1[] = "omg";
    result = PutInHashtable(ht, string1);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 2);

    // Define string to add to hashtable
    char string2[] = "yerd";
    result = PutInHashtable(ht, string2);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElementsInHashtable(ht), 3);

    HTKeyValuePtr lookup_result = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));

    // Now, lookup:
    result = LookupInHashtable(ht, FNVHash64(string, strlen(string)), &lookup_result);
    EXPECT_EQ(result, 0);
    EXPECT_TRUE(!strcmp(lookup_result->value->head->data, newString));
    EXPECT_EQ(NumElementsInHashtable(ht), 3);

    char string5[] = "elloh";
    result = PutInHashtable(ht, string5);
    EXPECT_EQ(NumElementsInHashtable(ht), 3);
    HTKeyValuePtr pair = ht->buckets[HashKeyToBucketNum(ht, FNVHash64(string, strlen(string)))];
    LinkedListPtr ll = pair->value;
    EXPECT_EQ(NumElementsInLinkedList(ll), 2);

    DestroyHashtable(ht);
}

TEST(Hashtable, Resize) {
    Hashtable ht = CreateHashtable(15);

    EXPECT_EQ(NumElementsInHashtable(ht), 0);
    EXPECT_EQ(ht->num_buckets, 15);

    FILE *wordFile = fopen("words.txt", "r");
    if (wordFile == NULL) {
        perror("Unable to open FILENAME... try again");
        exit(1);
    }

    char line[8192];
    int k = 0;
    while (fgets(line, sizeof(line), wordFile) && k < 50) {
        line[strcspn(line, "\n")] = 0;
        if (GetAlpha(ht) > 0.5) {
            EXPECT_TRUE(GetAlpha(ht) > 0.5);
            ht = ResizeHashtable(&ht);
        }
        PutInHashtable(ht, line);
        k++;
    }

    // Resize correctly adjusts size as expected
    EXPECT_EQ(ht->num_buckets, 1500);
    fclose(wordFile);
    DestroyHashtable(ht);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
