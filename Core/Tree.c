#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Tree.h"

typedef struct node Node;

struct tree {
    Node * root;
};

struct node {
    int value;
    Node * left;
    Node * right;
};

Tree * create() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void destroy_tree_rec(Node * node) {
    if(node != NULL) {
        destroy_tree_rec(node->left);
        destroy_tree_rec(node->right);
        free(node);
    }
}

void destroy_tree(Tree * tree) {
    destroy_tree_rec(tree->root);
    free(tree);
}

Node * add_node_rec(Node * node, int value) {
    if(node != NULL) {
        if(value < node->value)
            node->left = add_node_rec(node->left, value);
        else
            if(value > node->value)
                node->right = add_node_rec(node->right, value);
    } else {
        node = malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void add_node(Tree * tree, int value) {
    tree->root = add_node_rec(tree->root, value);
}