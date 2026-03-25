#include <stdio.h>
#include <stdlib.b>
#include "arvore.h"

//inicializar a arvore

voide inicializarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

//Le os dados do funcionario

Funcionario lerFuncionario() {
    Funcionario f;
    printf("\n  Matrícula : "); 
    scanf("%d", &f.matricula);

    printf("  Nome      : "); 
    scanf(" %[^\n]", f.nome);

    printf("  Cargo     : "); 
    scanf(" %[^\n]", f.cargo);

    printf("  Salário   : "); 
    scanf("%f", &f.salario);

    return f;
}

//home

void exibirMenu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║   Sistema de Cadastro            ║\n");
    printf("║   Árvore Binária de Funcionários ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Inserir funcionário          ║\n");
    printf("║  2. Buscar funcionário           ║\n");
    printf("║  3. Atualizar funcionário        ║\n");
    printf("║  4. Listar todos                 ║\n");
    printf("║  0. Sair                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Opção: ");
}

//main

int main(){
    Arvore arvore;
    inicializarArvore(&arvore);
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: {
                Funcionario f = lerFuncionario();
                arvore.raiz = inserir(arvore.raiz, f);
                printf("\nFuncionário inserido com sucesso!\n");
                break;
            }
            case 2: {
                int mat;
                printf("\n  Matrícula a buscar: ");
                scanf("%d", &mat);
                No *resultado = buscar(arvore.raiz, mat);
                exibirFuncionario(resultado);
                break;
            }
            case 3: {
                int mat;
                printf("\n  Matrícula a atualizar: ");
                scanf("%d", &mat);
                atualizar(arvore.raiz, mat);
                break;
            }
            case 4: {
                printf("\n── Funcionários cadastrados ──\n");
                listarEmOrdem(arvore.raiz);
                break;
            }
            case 0:
                printf("\nSistema encerrado. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    }while (opcao!=0);

    return 0;
    
}