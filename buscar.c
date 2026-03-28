#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

    No *buscar(No *raiz, const char *cpf){
        if (raiz == NULL) 
        return NULL;

        int cmp = strcmp(cpf, raiz-> dados.cpf);

        if (cmp==0){
            return raiz; //encontrado
        }else if (cmp<0){
            return buscar (raiz->left, cpf);
        }eslse{
            return buscar()
        }
    }