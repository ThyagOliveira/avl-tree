#include <stdio.h>

typedef struct tree Tree;

Tree * create();

void destroy_tree(Tree * tree);
void add_node(Tree * tree, int value);
void remove_node(Tree * tree, int value);
void print_tree(Tree * tree);
void save_file_in_order(Tree * tree, FILE * file);
int allocated_memory(Tree * tree, int value);

int height(Tree * tree);
int count_node(Tree * tree);