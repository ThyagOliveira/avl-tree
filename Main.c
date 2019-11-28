#include "Headers/Tree.h"
#include "Headers/Menu.h"

int main(int argc, char const *argv[]) {    
    Tree * tree = create();
    menu(tree);
    
    destroy_tree(tree);
    return 0;
}
