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
    int balancing_factor;
    int height;
    Node * left;
    Node * right;
};

Tree * create() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void destroy_tree_recursive(Node * node) {
    if(node != NULL) {
        destroy_tree_recursive(node->left);
        destroy_tree_recursive(node->right);
        free(node);
    }
}

void destroy_tree(Tree * tree) {
    destroy_tree_recursive(tree->root);
    free(tree);
}

int height_recursive(Node * node) {
    if(node != NULL) {
        int height_left = height_recursive(node->left);
        int height_right = height_recursive(node->right);
        return(height_left > height_right ? height_left : height_right) + 1;
    }
    return 0;
}

int height(Tree * tree) {
    return height_recursive(tree->root);
}

int find_height(Node * node) {
    if(node != NULL) {
        return node->height;
    }
    return 0;
}

int count_node_recursive(Node * node) {
    if(node != NULL) {
        return count_node_recursive(node->left) + count_node_recursive(node->right) + 1;
    }
    return 0;
}

int count_node(Tree * tree) {
    return count_node_recursive(tree->root);
}

int allocated_memory(Tree * tree, int value) {    
    if(tree != NULL) {
        return value * sizeof(tree->root);
    }
    return 0;
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

Node * add_node_recursive(Node * node, int value) {    
    if(node != NULL) {
        if(value < node->value) {
            node->left = add_node_recursive(node->left, value);
            int balance_factor = height_recursive(node->right) - height_recursive(node->left);

            if(balance_factor == -2) {
                balance_factor = height_recursive(node->left->right) - height_recursive(node->left->left);
                if(balance_factor <= 0)
                    node = right_rotation(node);
                else
                    node = right_double_rotation(node);
            }
        }                   
        else
            if(value > node->value) {
                node->right = add_node_recursive(node->right, value);
                int balance_factor = height_recursive(node->right) - height_recursive(node->left);

                if(balance_factor == 2) {
                    balance_factor = height_recursive(node->right->right) - height_recursive(node->right->left);
                    if(balance_factor >= 0)
                        node = left_rotation(node);
                    else
                        node = left_double_rotation(node);
                }                
            }                
    } else {
        node = malloc(sizeof(Node));
        node->value = value;        
        node->balancing_factor = 0;
        node->left = NULL;
        node->right = NULL;
    }
    
    return node;
}

void add_node(Tree * tree, int value) {
    tree->root = add_node_recursive(tree->root, value);
}

Node * remove_bigger(Node * node, int bigger) {
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

Node * remove_node_recursive(Node * node, int value) {    
    if(node != NULL) {
        if(value < node->value) {        
            node->left = remove_node_recursive(node->left, value);
            int balance_factor = height_recursive(node->right) - height_recursive(node->left);

            if(balance_factor == 2) {
                balance_factor = height_recursive(node->right->right) - height_recursive(node->right->left);
                if(balance_factor >= 0)
                    node = left_rotation(node);
                else
                    node = left_double_rotation(node);
            }            
        }
        else 
            if(value > node->value) {
                node->right = remove_node_recursive(node->right, value);
                int balance_factor = height_recursive(node->right) - height_recursive(node->left);

                if(balance_factor == -2) {
                    balance_factor = height_recursive(node->left->right) - height_recursive(node->left->left);
                    if(balance_factor <= 0)
                        node = right_rotation(node);
                    else
                        node = right_double_rotation(node);
                }                
            }
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
                        int bigger;
                        node->left = remove_bigger(node->left, bigger);
                        node->value = bigger;                        
                    }
                }                
            }
    }
    return node;
}

void remove_node(Tree * tree, int value) {
    tree->root = remove_node_recursive(tree->root, value);
}

void pre_order_recursive(Node * node) {
    if(node != NULL) {
        printf("%d ", node->value);
        pre_order_recursive(node->left);
        pre_order_recursive(node->right);
    }
}

void in_order_recursive(Node * node) {
    if(node != NULL) {
        in_order_recursive(node->left);
        printf("%d ", node->value);
        in_order_recursive(node->right);
    }
}

void post_order_recursive(Node * node) {
    if(node != NULL) {
        post_order_recursive(node->left);
        post_order_recursive(node->right);
        printf("%d ", node->value);
    }
}

void print_tree(Tree * tree) {
    if(tree->root == NULL)
        printf("\t Primeiro carregue a árvore");
    else {
        in_order_recursive(tree->root);
        printf("\n");
    }               
}

void save_file_in_order_recursive(Node * node, FILE * file) {
    if(node != NULL) {
        save_file_in_order_recursive(node->left, file);
        fprintf(file, "%d \n", node->value);
        save_file_in_order_recursive(node->right, file);
    }
}

void save_file_in_order(Tree * tree, FILE * file) {
    save_file_in_order_recursive(tree->root, file);
}