#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

// Cria e retorna um novo nó
No *criarNo(Funcionario f) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return NULL;
    }
    novo->dados = f;
    novo->left  = NULL;
    novo->right = NULL;
    return novo;
}

// Insere na árvore — só chame após validar com cpfJaCadastrado()
No *inserir(No *raiz, Funcionario f) {
    if (raiz == NULL) return criarNo(f);

    int cmp = strcmp(f.cpf, raiz->dados.cpf);

    if (cmp < 0)
        raiz->left  = inserir(raiz->left,  f);
    else if (cmp > 0)
        raiz->right = inserir(raiz->right, f);

    return raiz;
}