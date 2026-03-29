// ═══════════════════════════════════════════════════════════════
// LISTAR.C - Função de Listagem em Ordem
// ═══════════════════════════════════════════════════════════════
// Implementa travessia in-order (esquerda-raiz-direita) para
// exibir todos os funcionários em ordem crescente de CPF

#include <stdio.h>
#include "arvore.h"
#include "validador.h"

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: listarEmOrdem()
// Realiza travessia in-order (esquerda → raiz → direita) na árvore
// para exibir todos os funcionários em ordem alfabética de CPF
//
// PARÂMETROS:
//   - raiz: ponteiro para o nó atual (inicia-se à raiz da árvore)
//
// COMPORTAMENTO:
//   - Recursivamente percorre: esquerda → imprime → direita
//   - Garante ordem crescente (árvore BST é ordenada por CPF)
//   - Se árvore vazia: apenas retorna (sem erro)
//
// COMPLEXIDADE: O(n) - percorre todos os n nós exatamente uma vez
//
// VISUALIZAÇÃO:
//   Árvore:        4              in-order: 1 → 2 → 4 → 5 → 6
//          /   \
//         2     5
//        / \     \
//       1   3     6
// ───────────────────────────────────────────────────────────────
void listarEmOrdem(No *raiz) {
    
    // Caso base: chegou em NULL, retorna (sem fazer nada)
    if (raiz == NULL) 
        return;

    // Passo 1: Percorre recursivamente a SUBÁRVORE ESQUERDA
    // (todos os CPFs menores)
    listarEmOrdem(raiz->left);

    // Passo 2: Formata e exibe os dados do nó ATUAL
    
    // Formata o CPF de "12345678901" para "123.456.789-01"
    char cpfFormatado[15];
    formatarCPF(raiz->dados.cpf, cpfFormatado);

    // Exibe os dados com formatação visual
    printf("\n----------------------------\n");
    printf("  CPF     : %s\n",        cpfFormatado);
    printf("  Nome    : %s\n",        raiz->dados.nome);
    printf("  Cargo   : %s\n",        raiz->dados.cargo);
    printf("  Salario : R$ %.2f\n",   raiz->dados.salario);  // 2 casas decimais
    printf("----------------------------\n");

    // Passo 3: Percorre recursivamente a SUBÁRVORE DIREITA
    // (todos os CPFs maiores)
    listarEmOrdem(raiz->right);
}