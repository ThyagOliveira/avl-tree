# avl-tree

![CI status](https://github.com/ThyagOliveira/avl-tree/workflows/CI/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)


## Objetivo
Desenvolver uma aplicação em linguagem C para dar manutenção em uma árvore de pesquisa binária
balanceada AVL com grandes volumes de dados.
## Descrição
A tela do programa deverá fornecer um menu para permitir as seguintes operações:
1. Inserir na árvore uma faixa de inteiros [a .. b], onde b ≥ a ≥ 0. Qualquer valor que já existir na árvore
deve ser ignorado.
2. Remover da árvore uma faixa de inteiros [a .. b], onde b ≥ a ≥ 0.
3. Retornar a quantidade de nós na árvore e a quantidade de memória alocada pelos nós.
4. Salvar o conteúdo da árvore em ordem crescente em um arquivo TXT.
O programa deverá suportar árvores de pesquisa com pelo menos 10^7 itens. Dica: use um compilador que
gera um executável de 64 bits. Código 32 bits não consegue endereçar toda a memória dos computadores
atuais com 4GB de RAM ou mais.
