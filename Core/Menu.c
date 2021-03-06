#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Tree.h"
#include "../Headers/Menu.h"

void menu(Tree * tree) {
    int option = 0;
    do {
        printf("\n\n\t\tMenu de Opções");
        printf("\n01. Inserir uma faixa de inteiros.");
        printf("\n02. Remover uma faixa de inteiros.");
        printf("\n03. Retornar a quantidade de nós na árvore e a quantidade de memória alocada pelos nós.");
        printf("\n04. Salvar o conteúdo da árvore em ordem crescente.");
        printf("\n05. Imprimir árvore.");
        printf("\n06. Sair");
        printf("\nEscolha a opção(Apenas Números): ");

        scanf("%d", &option);    
        fflush(stdin);

        switch(option) {
            case 1:
                add_value_range(tree);                
                break;
            case 2:
                remove_value_range(tree);                
                break;
            case 3:
                count_node_tree(tree);
                break;
            case 4:
                save_file(tree);
                break;
            case 5:
                print_tree(tree);
                break;
            case 6:
                break;
            default:
                system("clear");
                return menu(tree);
                break;
        }        
    } while(option != 6);
}

void add_value_range(Tree * tree) {
    int start, end;

    printf("Digite o valor inicial: ");
    scanf("%d", &start);
    fflush(stdin);

    printf("Digite o valor final: ");
    scanf("%d", &end);
    fflush(stdin);    

    for( ; start <= end; start++) {        
        add_node(tree, start);
    }

}

void remove_value_range(Tree * tree) {
    int start, end;

    printf("Digite o valor inicial: ");
    scanf("%d", &start);
    fflush(stdin);

    printf("Digite o valor final: ");
    scanf("%d", &end);
    fflush(stdin);    

    for( ; start <= end; start++) {        
        remove_node(tree, start);
    }
}

void save_file(Tree * tree) {
	FILE * file = fopen("file.txt", "w");
	save_file_in_order(tree, file);
	fclose(file);
	printf("Arquivo salvo com sucesso\n");
}

void count_node_tree(Tree * tree) {
    int count = count_node(tree);
    int memory = allocated_memory(tree, count);
    if(count != 0) {
        printf("Quantidade de nós na árvore: %d", count);
        printf("\nMemória alocada: %d", memory);
    } else
        printf("Árvore vazia");
}