#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

const int SIZE = 26;
const char LETTERS[] = "abcdefghijklmnopqrstuvwxyz";
const char LETTERS_UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct Pair {
    char* key;
    int* value;
}Pair;

typedef struct Node {
    Pair* pair;
    struct Node* next;
}Node;

typedef struct Map {
    Node** data;
    int size;
}Map;

Map* createMap(char* key, int* value, int size) {
    Node* n = (Node*) malloc(sizeof(Node));
    Pair* p = (Pair*)malloc(sizeof(Pair));
    p->key = key;
    p->value = value;
    n->pair = p;
    n->next = NULL;
    Map* m = (Map*)malloc(sizeof(Map));
    Node** d = (Node**)malloc(sizeof(Node*) * size);
    int index = hash(key);
    d[index] = n;

    m->data = d;
    m->size = 1;
    printf("%d\n", *(m->data[0]->pair->value));
    return m;
}

int getIndex(char c) {
    int i = 0;
    while (i < 26 && c != LETTERS[i] || c != LETTERS_UPPER[i]) {
        i++;
    }

    return i;
}

int hash(const char* key) {
    char c = key[0];
    return 0;
}

Node* get(Map* map, const char* key) {
    int index = hash(key);

    Node* temp = (Node*)malloc(sizeof(Node));
    temp = map->data[index];
    while (temp != NULL) {
        Pair* pair = temp->pair;
        const char* k = pair->key;
        printf("key is %s\n", pair->key);

        if (strcmp(key, k) == 0) {
            break;
       }

       temp = temp->next;
    }
    printf("temp is %s\n", temp->pair->key);
    return temp;
}

void put(Map* map, char* key, int* value) {
    // Given the struct definitions, I decided to handle collisions as a
    // linked list of nodes. Therefore, if there is a collision, the node
    // is appended to the curr->next value for the current node. If the
    // index is empty, the node is directly added. NOW GIVEN THE BAD HASH
    // function, all puts() will append to index 0. That is not on me lol,
    // I thought about instead going the route of linear probing, but the
    // get function is made for linked lists.
    // Implement logic here
    if (map == NULL || key == NULL || value == NULL) return;

    // Create new node that will be added
    Node* n = (Node*)malloc(sizeof(Node));
    Pair* p = (Pair*)malloc(sizeof(Pair));
    if (n == NULL || p == NULL) return;

    p->key = key;
    p->value = value;
    n->pair = p;
    n->next = NULL;

    // Find index to put new node
    int index = hash(key);

    // Case where there is a collision linked list
    if (map->data[index] != NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) return;
        temp = map->data[index];
        temp->next = n;
    } else {
        map->data[index] = n;
    }

    // Increment size of list, size includes chaining
    map->size++;
}

int isEmpty(Map* map) {
    return map->size == 0;
}

int main() {
    srand(time(NULL));

    printf("starting list operation\n");
    char* k1 = (char*)malloc(sizeof(char));
    k1 = "alpha";

    int* v1 = (int*)malloc(sizeof(int));
    *v1 = 10;

    char* k2 = (char*)malloc(sizeof(char));
    k2 = "beta";

    int* v2 = (int*)malloc(sizeof(int));
    *v2 = 20;

    Map* m = createMap(k1, v1, SIZE);
    printf("The first value is %d\n", *(m->data[0]->pair->value));

    put(m, k2, v2);

    Node** data = m->data;
    Node* n1 = data[0];
    Node* n2 = n1->next;
    Pair* p1 = n1->pair;
    Pair* p2 = n2->pair;
    printf("the value is %d\n", *(p1->value));
    printf("the value is %d\n", *(p2->value));

    // These won't work due to the way I implemented put. Fix hash
    // function and these may work.
    // Node* n2 = data[1];
    // Pair* p2 = n2->pair;
    // printf("the value is %s\n", p2->value);

    Node* gNode = get(m, k2);
    Pair* gPair = gNode->pair;

    printf("testing get %d\n", *(gPair->value));
    return 0;
}
