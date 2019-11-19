#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct tree {
    Node * root;
};

struct Node {
    int value;
    Node * left;
    Node * right;
};