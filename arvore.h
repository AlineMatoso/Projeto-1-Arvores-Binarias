// ═══════════════════════════════════════════════════════════════
// Árvore Binária de Funcionários
// Sistema de Gestão de Funcionários usando Árvore Binária de Busca
// Ordenada por CPF (ordem lexicográfica)
// ═══════════════════════════════════════════════════════════════

#ifndef ARVORE_H
#define ARVORE_H

#include "validador.h"

// Estrutura para armazenar dados de um funcionário
// CPF é a chave primária (11 dígitos)
typedef struct Funcionario {
    char  cpf[12];          // CPF com até 11 dígitos + '\0'
    char  nome[100];        // Nome completo do funcionário
    char  cargo[100];       // Cargo/posição do funcionário
    float salario;          // Salário em reais
} Funcionario;

// Nó da árvore binária
// Cada nó contém dados de um funcionário e referências aos filhos
typedef struct No {
    Funcionario   dados;    // Dados do funcionário armazenado neste nó
    struct No    *left;     // Filho esquerdo (CPF menor)
    struct No    *right;    // Filho direito (CPF maior)
} No;

// Estrutura principal da árvore
// Mantém apenas a referência à raiz
typedef struct Arvore {
    No *raiz;               // Ponteiro para a raiz da árvore
} Arvore;

// ─── Funções disponíveis ───────────────────────────────────────
void  inicializarArvore(Arvore *arvore);       // Inicializa árvore vazia
No   *criarNo(Funcionario f);                  // Cria novo nó
No   *inserir(No *raiz, Funcionario f);        // Insere funcionário
No   *buscar(No *raiz, const char *cpf);       // Busca por CPF
void  exibirFuncionario(No *no);               // Exibe dados formatados
int   atualizar(No *raiz, const char *cpf);    // Atualiza funcionário
void  listarEmOrdem(No *raiz);                 // Lista em ordem (in-order)

#endif