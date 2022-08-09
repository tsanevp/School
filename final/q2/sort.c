#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct List{
    Node* head;
    int size;
}List;

List* create(int init){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = init;

    List* l = (List*)malloc(sizeof(List));
    l->head = n;
    l->size = 1;
    return l;
}

List* add(List* list, int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    
    List* l = (List*)malloc(sizeof(List));
    n->next = list->head;

    l->head = n;
    l->size = list->size + 1;
    free(list);

    return l;
}

void swap (Node* node1, Node* node2) {
    if (node1 == NULL || node2 == NULL) return;
    int tempData = node1->data;
    node1->data = node2->data;
    node2->data = tempData;
}

void sort(List* list){
    if (list == NULL || list->size == 1) return;
    
    int i; 
    for (i = 0; i < list->size; i++) {
        Node* currNode = list->head;
        while (currNode->next != NULL) {
            if (currNode->data > (currNode->next)->data) {
                swap(currNode, currNode->next);
            }
            currNode = currNode->next;
        }
    }
}

bool isSorted(List* list) {
    if(list == NULL || list->head == NULL) return false;
    if(list->head->next == NULL) return true;
    Node* curr = list->head;
    Node* temp = list->head->next;
    while(temp != NULL) {
        if(temp->data < curr->data) return false;
        curr = temp;
        temp = temp->next;
    }

    return true;
}
void print(List* l1) {
    if (l1 == NULL) return;

    Node* head = l1->head;
    while (head != NULL) {
        printf("List value is: %d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->data = 3;
    List* l1 = (List*)malloc(sizeof(List));
    l1->head = n2;
    l1 = add(l1, 9);
    l1 = add(l1, 30);
    l1 = add(l1, 4);
    l1 = add(l1, 2);
    l1 = add(l1, 20);
    l1 = add(l1, 5);
    l1 = add(l1, 15);
    bool r1 = isSorted(l1);
    printf("isSorted1: %d\n", r1);
    
    bool r2 = isSorted(l1);
    printf("isSorted2: %d\n", r2);

    print(l1);
    sort(l1);
    printf("-------\n");
    print(l1);

    bool r3 = isSorted(l1);
    printf("isSorted3: %d\n", r3);

    /*
    printf("node1 data is %d\n", n1->data);
    printf("node2 data is %d\n", n2->data);
    swap(n1, n2);
    printf("node1 data is %d\n", n1->data);
    printf("node2 data is %d\n", n2->data);
    */

    return 0;
}


