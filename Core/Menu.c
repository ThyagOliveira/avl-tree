#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Tree.h"

void save_file(Tree * tree) {
	FILE * file = fopen("file.txt", "w");
	save_file_in_order(tree, file);
	fclose(file);
	printf("Arquivo salvo com sucesso\n");
}

void menu(Tree * tree) {
    int option = 0;
    do {
        printf("\n\n\t\tMenu de Opções");
        printf("\n01. Inserir uma faixa de inteiros.");
        printf("\n02. Remover uma faixa de inteiros.");
        printf("\n03. Retornar a quantidade de nós na árvore e a quantidade de memória alocada pelos nós.");
        printf("\n04. Salvar o conteúdo da árvore em ordem crescente.");
        printf("\n05. Sair");
        printf("\nEscolha a opção(Apenas Números): ");

        scanf("%d", &option);    
        fflush(stdin);

        switch(option) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                save_file(tree);
                break;
            case 5:
                break;
            default:
                system("clear");
                return menu(tree);
                break;
        }        
    } while(option != 5);
}