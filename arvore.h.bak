#ifndef ARVORE_H
#define ARVORE_H

//Estruturas

typedef struct Funcionario{
    int matricula;
    char nome[100];
    char cargo[100];
    float salario;
} Funcionario;

typedef struct No{
    Funcionario dados;
    struct No *left;
    struct No *right;
} No;

typedef struct Arvore{
    No *raiz;
} Arvore;

void inicializarArvore(Arvore *arvore);

No *criarNo(Funcionario f);

No *inserir(No *raiz, Funcionario f);

No *buscar(No *raiz, int matricula);


