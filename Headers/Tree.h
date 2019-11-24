typedef struct tree Tree;

Tree * create();

void destroy_tree(Tree * tree);
void add_node(Tree * tree, int value);
void remove_node(Tree * tree, int * value);
void print_tree(Tree * tree);
int height(Tree * tree);