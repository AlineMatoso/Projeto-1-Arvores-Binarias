#include <stdio.h>
#include <string.h>
#include "arvore.h"

No *atualizar(No *raiz, int matricula){
    // aqui ele vai buscar o funcionario (nó) pelo numero da matricula
    No *no = buscar (raiz, matricula);

    if (no == NULL){
        printf("Funcionario com matricula %d não localizado. \n", matricula);
        return raiz;
    }

    int opcao;

    printf("\n--- ATUALIZACAO CADASTRO FUNCIONÁRIO ---\n");
    printf("Funcionario encontrado: %s\n", no->dados.nome);
    printf("O que deseja atualizar?\n");
    printf("1 - Nome\n");
    printf("2 - Cargo\n");
    printf("3 - Salario\n");
    printf("4 - Todos os campos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa o buffer


    switch (opcao){
        case 1: // atualizar o nome do funcionário 
        printf("NOME COMPLETO: ");
        fgets(no->dados.nome, 100, stdin);
        no->dados.nome[strcspn(no->dados.nome, "\n")] = '\0';
        printf("ALTERACAO SALVA. \n");
        break;

        case 2: // atualizar o cargo do funcionario
        printf("CARGO: ");
        fgets(no->dados.cargo, 100, stdin);
        no->dados.cargo[strcspn(no->dados.cargo, "\n")] = '\0';
        printf("ALTARACAO SALVA. \n");
        break;

        case 3: // atualizar o salario do funcionario
        printf("SALARIO: ");
        scanf("%f", &no->dados.salario);
        printf("ALTERACAO SALVA. \n");
        break;

        case 4: // alterar todos os campos. 
        printf("NOME COMPLETO: ");
            fgets(no->dados.nome, 100, stdin);
            no->dados.nome[strcspn(no->dados.nome, "\n")] = '\0';
 
            printf("CARGO: ");
            fgets(no->dados.cargo, 100, stdin);
            no->dados.cargo[strcspn(no->dados.cargo, "\n")] = '\0';
 
            printf("SALARIO: ");
            scanf("%f", &no->dados.salario);

            printf("ALTERACOES REALIZADAS. \n");
            break;
        
        default:
        printf("Digite uma opcao valida. \n");
        break;

    }

    return raiz;
}