// ═══════════════════════════════════════════════════════════════
// ATUALIZAR.C - Função de Atualização de Dados
// ═══════════════════════════════════════════════════════════════
// Permite atualizar um ou mais campos de um funcionário existente

#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

// ───────────────────────────────────────────────────────────────
// FUNÇÃO: atualizar()
// Busca um funcionário pelo CPF e permite atualizar seus dados
// (nome, cargo e/ou salário)
//
// PARÂMETROS:
//   - raiz: ponteiro para a raiz da árvore
//   - cpf:  CPF do funcionário a atualizar (11 dígitos sem formatação)
//
// RETORNO:
//   - 1: funcionário encontrado e operação realizada
//   - 0: funcionário não encontrado
//
// COMPORTAMENTO:
//   - Busca o funcionário usando a função buscar()
//   - Se não encontrar → exibe mensagem e retorna 0
//   - Se encontrar → exibe menu com opções de atualização:
//     • 1: Atualizar apenas NOME
//     • 2: Atualizar apenas CARGO
//     • 3: Atualizar apenas SALÁRIO
//     • 4: Atualizar TODOS os campos
//     • 0: Cancelar (não faz nada)
//
// OBS: A atualização é direta na estrutura encontrada (in-place)
//      Não precisa reinserir na árvore
// ───────────────────────────────────────────────────────────────
int atualizar(No *raiz, const char *cpf) {
    
    // Busca o funcionário pelo CPF
    No *no = buscar(raiz, cpf);

    // Se não encontrou, exibe mensagem e retorna sem fazer nada
    if (no == NULL) {
        char cpfFormatado[15];
        formatarCPF(cpf, cpfFormatado);
        printf("Funcionario com CPF %s nao localizado.\n", cpfFormatado);
        return 0;
    }

    // Funcionário encontrado - exibe opções de atualização
    int opcao;
    printf("\n--- ATUALIZACAO CADASTRO FUNCIONARIO ---\n");
    printf("Funcionario encontrado: %s\n", no->dados.nome);
    printf("O que deseja atualizar?\n");
    printf("1 - Nome\n");
    printf("2 - Cargo\n");
    printf("3 - Salario\n");
    printf("4 - Todos os campos\n");
    printf("0 - Cancelar\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar();  // Remove '\n' do buffer de entrada

    // Menu de atualização
    switch (opcao) {
        
        // OPÇÃO 1: Atualizar apenas o NOME
        case 1:
            printf("NOME COMPLETO: ");
            fgets(no->dados.nome, 100, stdin);
            // Remove o '\n' adicionado por fgets
            no->dados.nome[strcspn(no->dados.nome, "\n")] = '\0';
            printf("ALTERACAO SALVA.\n");
            break;
        
        // OPÇÃO 2: Atualizar apenas o CARGO
        case 2:
            printf("CARGO: ");
            fgets(no->dados.cargo, 100, stdin);
            // Remove o '\n' adicionado por fgets
            no->dados.cargo[strcspn(no->dados.cargo, "\n")] = '\0';
            printf("ALTERACAO SALVA.\n");
            break;
        
        // OPÇÃO 3: Atualizar apenas o SALÁRIO
        case 3:
            printf("SALARIO: ");
            scanf("%f", &no->dados.salario);
            printf("ALTERACAO SALVA.\n");
            break;
        
        // OPÇÃO 4: Atualizar TODOS os campos (nome, cargo e salário)
        case 4:
            // Atualiza NOME
            printf("NOME COMPLETO: ");
            fgets(no->dados.nome, 100, stdin);
            no->dados.nome[strcspn(no->dados.nome, "\n")] = '\0';
            
            // Atualiza CARGO
            printf("CARGO: ");
            fgets(no->dados.cargo, 100, stdin);
            no->dados.cargo[strcspn(no->dados.cargo, "\n")] = '\0';
            
            // Atualiza SALÁRIO
            printf("SALARIO: ");
            scanf("%f", &no->dados.salario);
            printf("ALTERACOES REALIZADAS.\n");
            break;
        
        // OPÇÃO 0: Cancelar a operação
        case 0:
            printf("Atualizacao cancelada.\n");
            break;
        
        // Opção inválida
        default:
            printf("Opcao invalida.\n");
    }
    
    return 1;  // Operação realizada com sucesso
}