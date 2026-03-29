// ═══════════════════════════════════════════════════════════════
// INSERIR.C - Função de Inserção na Árvore Binária
// ═══════════════════════════════════════════════════════════════
// Implementa inserção recursiva mantendo ordem de CPF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: criarNo()
// Aloca memória e cria um novo nó com os dados do funcionário
//
// PARÂMETROS:
//   - f: estrutura Funcionario com CPF, nome, cargo, salário
//
// RETORNO:
//   - Ponteiro para o novo nó alocado
//   - NULL em caso de erro de alocação de memória
//
// OBS: Os ponteiros left e right são inicializados como NULL
// ───────────────────────────────────────────────────────────────
No *criarNo(Funcionario f) {
    // Aloca espaço em memória para um novo nó
    No *novo = (No *)malloc(sizeof(No));
    
    // Verifica se a alocação foi bem-sucedida
    if (novo == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return NULL;
    }
    
    // Copia os dados do funcionário para o novo nó
    novo->dados = f;
    
    // Inicializa os filhos como vazios (NULL)
    novo->left  = NULL;
    novo->right = NULL;
    
    return novo;
}

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: inserir()
// Insere um novo funcionário na árvore binária de busca de forma
// recursiva, mantendo a ordem lexicográfica de CPF
//
// PARÂMETROS:
//   - raiz: ponteiro para o nó atual (null para árvore vazia)
//   - f:    estrutura Funcionario a ser inserido
//
// RETORNO:
//   - Ponteiro para a raiz (pode ser diferente se raiz era NULL)
//
// ALGORITMO:
//   1. Se nó é NULL → cria novo nó e o retorna
//   2. Compara CPF novo com CPF do nó atual
//   3. Se menor → insere recursivamente à ESQUERDA
//   4. Se maior → insere recursivamente à DIREITA
//   5. Se igual → não insere (evita duplicatas) - requer validação prévia
//
// COMPLEXIDADE: O(log n) melhor caso | O(n) pior caso (árvore degenerada)
//
// OBS: O código assume que cpfJaCadastrado() foi chamado antes!
//      Esta função NÃO verifica duplicatas (responsabilidade de main.c)
// ───────────────────────────────────────────────────────────────
No *inserir(No *raiz, Funcionario f) {
    
    // Caso base: posição vazia encontrada → cria novo nó
    if (raiz == NULL) 
        return criarNo(f);

    // Compara o CPF a inserir com o CPF do nó atual
    int cmp = strcmp(f.cpf, raiz->dados.cpf);

    // CPF menor → vai para a esquerda
    if (cmp < 0)
        raiz->left  = inserir(raiz->left,  f);
    
    // CPF maior → vai para a direita
    else if (cmp > 0)
        raiz->right = inserir(raiz->right, f);
    
    // Se cmp == 0: CPF duplicado (não insere, mantém nó original)

    // Retorna o nó (pode ser diferente na primeira chamada)
    return raiz;
}