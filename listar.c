#include <stdio.h>
#include "arvore.h"

// Listar funcionarios em pré ordem --- RAIZ -> SAE -> SAD

void listar(No *raiz){
    if (raiz == NULL){
        return;
    }

    printf("\n----------------------------\n");
    printf("Matricula : %d\n", raiz->dados.matricula);
    printf("Nome      : %s\n", raiz->dados.nome);
    printf("Cargo     : %s\n", raiz->dados.cargo);
    printf("Salario   : R$ %.2f\n", raiz->dados.salario);
    printf("----------------------------\n");
 
    listarPreOrdem(raiz->left);
    listarPreOrdem(raiz->right);


}