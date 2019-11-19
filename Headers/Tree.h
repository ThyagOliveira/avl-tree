typedef struct tree Tree;

Tree * create();

void destroy_tree(Tree * tree);
void add_node(Tree * tree, int value);