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

int height_rec(Node * node) {
    if(node != NULL) {
        int height_left = height_rec(node->left);
        int height_right = height_rec(node->right);
        return(height_left > height_right ? height_left : height_right) + 1;
    }
    return 0;
}

int height(Tree * tree) {
    return height_rec(tree->root);
}

Node * left_rotation(Node * node) {
    Node * help = node->right;

    node->right = help->left;
    help->left = node;

    return help;
}

Node * right_rotation(Node * node) {
    Node * help = node->left;

    node->left = help->right;
    help->right = node;

    return help;
}

Node * left_double_rotation(Node * node) {
    node->right = right_rotation(node->right);
    return left_rotation(node);
}

Node * right_double_rotation(Node * node) {
    node->left = left_rotation(node->left);
    return right_rotation(node);
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

Node * remove_bigger(Node * node, int * bigger) {
    if(node != NULL) {
        if(node->right != NULL)
            node->right = remove_bigger(node->right, bigger);
        else {
            Node * help = node;
            bigger = node->value;
            node = node->left;
            free(help);
        }
    }
    return node;
}

Node * remove_node_rec(Node * node, int * value) {
    if(node != NULL) {
        if(value < node->value)        
            node->left = remove_node_rec(node->left, value);
        else 
            if(value > node->value)
                node->right = remove_node_rec(node->right, value);
            else {
                Node * help = node;
                if(node->left == NULL && node->right == NULL) {
                    node = NULL;
                    free(help);
                } else {
                    if(node->left == NULL || node->right == NULL) {
                        node = node->left != NULL ? node->left : node->right;
                        free(help);
                    } else {
                        int * bigger;
                        node->left = remove_bigger(node->left, bigger);
                        node->value = bigger;                        
                    }
                }                
            }
    }
    return node;
}

void remove_node(Tree * tree, int * value) {
    tree->root = remove_node_rec(tree->root, value);
}

void pre_order(Node * node) {
    if(node != NULL) {
        printf("%d ", node->value);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(Node * node) {
    if(node != NULL) {
        in_order(node->left);
        printf("%d ", node->value);
        in_order(node->right);
    }
}

void post_order(Node * node) {
    if(node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d ", node->value);
    }
}

void print_tree(Tree * tree) {
    if(tree->root == NULL)
        printf("\t Primeiro carregue a árvore");
    else {
        in_order(tree->root);
        printf("\n");
    }               
}