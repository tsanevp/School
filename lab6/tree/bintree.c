#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    int* value;
    struct Tree* left;
    struct Tree* right;
    int size;
}Tree;

void printAllValues(Tree* t) {
    if(t == NULL) return;

    printf("value is %d\n", *(t->value));
    printAllValues(t->left);
    printAllValues(t->right);
}

Tree* construct(int i) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    int* v = (int*)malloc(sizeof(int));
    *v = i;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    t->size = 0;
    return t;
}

int preOrder(Tree* t, int i) {
    if(t == NULL) return 0;

    int ret = *(t->value) == i;
    int left = preOrder(t->left, i);
    int right = preOrder(t->right, i);

    return ret || left || right;
}

void add(Tree* t, int i){
    int* val = (int*)malloc(sizeof(int));
    *val = i;

    if(t->left == NULL && t->right == NULL) {
        Tree* nt = construct(i);    
        if(i <= *(t->value)) {
            t->left = nt;
        } else {
            t->right = nt;
        }

        return;
    }

    t->size++;
    
    /*
    if(t->left == NULL) {
        //add to left
        Tree* nt = construct(i);    
        t->left = nt;
        return;       
    } else if(t->right == NULL) {
        Tree* nt = construct(i);    
        t->right = nt;
        return;
    }


    Tree* next;
    if(t->left->size < t->right->size) {
        next = t->left;
    } else {
        next = t->right;
    }
    */


    if(i <= *(t->value)) {
        if(t->left == NULL) {
            Tree* nt = construct(i);
            t->left = nt;
            return;
        } else {
            add(t->left, i);
        }
    } else {
        if(t->right == NULL){
            Tree* nt = construct(i);
            t->right = nt;
            return;
        } else {
            add(t->right, i);
        }
    }
    /*
    if(t->left != NULL && i <= t->value) {
        add(t->left, i);
    } else if(t->right != NULL
    add(next, i);*/
}

int sizeBST(Tree* t) {
    if (t->left == NULL && t->right == NULL) {
        return 1;
    } else if (t->right != NULL && t->left == NULL) {
        return 1 + sizeBST(t->right);
    } else if (t->right == NULL && t->left != NULL) {
        return 1 + sizeBST(t->left);
    } else {
        return (1 + sizeBST(t->left) + sizeBST(t->right));
    }
}
/*
int isBST(Tree* t, int* root) {
    printf("tree root value rn %d\n", *(t->value));
    if (t->left == NULL && t->right == NULL) {
        return 0;
    } 
    
    if (t->left != NULL) {
        if (*(t->value) >= *((t->left)->value) && *root >= *((t->left)->value)) {
            return 0 + isBST(t->left, t->value);
        } else {
            return 1;
        }
    } 
    if (t->right != NULL) {
        if (*(t->value) <= *((t->right)->value) && *root <= *((t->right)->value)) {
            return 0 + isBST(t->right, t->value);
        } else {
            return 1;
        }
    }
    
    if (t->left != NULL && *root <= *((t->left)->value)) {
        return 1;
    }

    if (t->right != NULL && *root >= *((t->right)->value)) {
        return 1;
    }

    return isBST(t->left) && isBST(t->right); 
}*/
int rleftbst(Tree* t, int* prevNode) {
    if (t == NULL) {
        return 1;
    }
    printf("current root %d\n", *(t->value));
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }

    if (t->left != NULL && *(t->value) <= *((t->left)->value)) {
        return 0;
    }

    if (t->right != NULL) {
        if ((*(t->value) >= *((t->right)->value) || *((t->right)->value) >= *prevNode)) {
            return 0;
        }
    }
    return rleftbst(t->left, t->value) && rleftbst(t->right, t->value);
}

int rrightbst(Tree* t, int* prevNode) {
    if (t == NULL) {
        return 1;
    }

    printf("current root %d\n", *(t->value));
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    printf("sus\n");
    if (t->right != NULL && *(t->value) >= *((t->right)->value)) {
        return 0;
    }
    printf("damn\n");
    if (t->left != NULL) {
        if ((*(t->value) <= *((t->left)->value)) || *((t->left)->value) <= *prevNode) {
            printf("(((dfg\n");
            return 0;
        }
    }
    printf(":(n\n");
    return rrightbst(t->right, t->value) && rrightbst(t->left, t->value);
}

int isBST(Tree* t) {
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    printf("left %d\n", rleftbst(t->left, t->value));
    printf("right %d\n", rrightbst(t->right, t->value));
    return rleftbst(t->left, t->value) && rrightbst(t->right, t->value);
}

int main() {
    Tree* t1 = construct(10);
    add(t1, 7);
    add(t1, 6);
    add(t1, 4);
    add(t1, 3);
    add(t1, 8);
    add(t1, 12);
    add(t1, 14);
    add(t1, 11);
    add(t1, 20);
    printAllValues(t1);
    printf("The tree has size: %d\n", sizeBST(t1));
    printf("The tree is a BST: %d\n", isBST(t1));
    printf("has value is %d\n", preOrder(t1, 2));

    Tree* t2 = construct(10);

    int i = 6;
    int* val = (int*)malloc(sizeof(int));
    *val = i;
    Tree* nt = construct(i);   
    t2->left = nt;

    int j = 4;
    int* val1 = (int*)malloc(sizeof(int));
    *val1 = j;
    Tree* nt1 = construct(j);   
    (t2->left)->left = nt1;

    int k = 3;
    int* val2 = (int*)malloc(sizeof(int));
    *val2 = k;
    Tree* nt2 = construct(k);   
    (t2->left)->left->left = nt2;
    
    int p = 8;
    int* val3 = (int*)malloc(sizeof(int));
    *val3 = p;
    Tree* nt3 = construct(p);   
    (t2->left)->right = nt3;
    
    int z = 12;
    int* val7 = (int*)malloc(sizeof(int));
    *val7 = z;
    Tree* nt7 = construct(z);   
    (t2->right) = nt7;

    int a = 11;
    int* val4 = (int*)malloc(sizeof(int));
    *val4 = a;
    Tree* nt21 = construct(a);   
    (t2->right)->left = nt21;
    printf("=========================\n\n");
    printAllValues(t2);
    
    printf("The tree has size: %d\n", sizeBST(t2));
    printf("The tree is a BST: %d\n", isBST(t2));
}

