// ═══════════════════════════════════════════════════════════════
// BUSCAR.C - Função de Busca na Árvore Binária
// ═══════════════════════════════════════════════════════════════
// Implementa busca recursiva por CPF em uma árvore binária de busca
// Comparação lexicográfica: esq (<) | centro (=) | dir (>)

#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: buscar()
// Busca recursiva por CPF na árvore binária de busca
//
// PARÂMETROS:
//   - raiz: ponteiro para o nó atual (começa pela raiz da árvore)
//   - cpf:  CPF a procurar (string com 11 dígitos, sem formatação)
//
// RETORNO:
//   - Ponteiro para o nó encontrado (estrutura No com o funcionário)
//   - NULL se não encontrar
//
// ALGORITMO:
//   1. Se nó é NULL → não encontrou, retorna NULL
//   2. Compara CPF procurado com CPF do nó atual
//   3. Se igual → funcionário encontrado, retorna o nó
//   4. Se menor → CPF procurado está à esquerda, busca recursiva esquerda
//   5. Se maior → CPF procurado está à direita, busca recursiva direita
//
// COMPLEXIDADE: O(log n) melhor caso | O(n) pior caso (árvore degenerada)
// ───────────────────────────────────────────────────────────────
No *buscar(No *raiz, const char *cpf){
    
    // Caso base: chegou em um nó NULL = CPF não existe
    if (raiz == NULL) 
        return NULL;

    // Compara o CPF procurado com o CPF do nó atual
    // strcmp retorna: <0 (esq) | 0 (igual) | >0 (dir)
    int cmp = strcmp(cpf, raiz->dados.cpf);

    if (cmp == 0){
        // CPF encontrado! Retorna o nó com os dados do funcionário
        return raiz;
    }
    else if (cmp < 0){
        // CPF procurado é menor → busca recursiva NA SUBÁRVORE ESQUERDA
        return buscar(raiz->left, cpf);
    }
    else{
        // CPF procurado é maior → busca recursiva NA SUBÁRVORE DIREITA
        return buscar(raiz->right, cpf);
    }
}

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: exibirFuncionario()
// Exibe os dados de um funcionário formatados no console
//
// PARÂMETROS:
//   - no: ponteiro para o nó contendo os dados (resultado de busca)
//
// COMPORTAMENTO:
//   - Se no == NULL: exibe mensagem "não encontrado"
//   - Se no != NULL: exibe CPF formatado, nome, cargo e salário
//
// OBSERVAÇÃO: O CPF é formatado de "12345678901" para "123.456.789-01"
// ───────────────────────────────────────────────────────────────
void exibirFuncionario(No *no){
    
    // Verifica se o funcionário não foi encontrado
    if (no == NULL){
        printf("Funcionário não encontrado.\n");
        return;
    }
    
    // Formata o CPF para exibição (adiciona pontos e traço)
    char cpfFormatado[15];  // Buffer para "123.456.789-01"
    formatarCPF(no->dados.cpf, cpfFormatado);

    // Exibe os dados com formatação visual
    printf("\n─────────────────────────────\n");
    printf("  CPF     : %s\n",      cpfFormatado);
    printf("  Nome    : %s\n",      no->dados.nome);
    printf("  Cargo   : %s\n",      no->dados.cargo);
    printf("  Salário : R$ %.2f\n", no->dados.salario);  // 2 casas decimais
    printf("─────────────────────────────\n");
}