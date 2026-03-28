#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "validador.h"

// ─────────────────────────────────────────
//  Inicializa a árvore
// ─────────────────────────────────────────
void inicializarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

// ─────────────────────────────────────────
//  Lê e valida FORMATO do CPF
// ─────────────────────────────────────────
void lerCPF(char *cpfLimpo) {
    char entrada[20];
    while (1) {
        printf("  CPF (com ou sem pontuação): ");
        scanf(" %19s", entrada);
        limparCPF(entrada, cpfLimpo);
        if (validarFormatoCPF(cpfLimpo)) break;
        printf("  ✗ CPF inválido! Verifique os dígitos e tente novamente.\n");
    }
}

// ─────────────────────────────────────────
//  Lê os dados completos de um funcionário
// ─────────────────────────────────────────
Funcionario lerFuncionario(Arvore *arvore) {
    Funcionario f;

    // Valida formato E se já está cadastrado
    char entrada[20];
    while (1) {
        printf("  CPF (com ou sem pontuação): ");
        scanf(" %19s", entrada);
        limparCPF(entrada, f.cpf);

        if (!validarFormatoCPF(f.cpf)) {
            printf("  ✗ CPF inválido! Verifique os dígitos e tente novamente.\n");
            continue;
        }

        if (cpfJaCadastrado(arvore->raiz, f.cpf)) {
            char cpfFormatado[15];
            formatarCPF(f.cpf, cpfFormatado);
            printf("  ✗ CPF %s já está cadastrado no sistema!\n", cpfFormatado);
            continue;
        }

        break; // CPF válido e livre!
    }

    printf("  Nome    : "); scanf(" %99[^\n]", f.nome);
    printf("  Cargo   : "); scanf(" %99[^\n]", f.cargo);
    printf("  Salário : "); scanf("%f", &f.salario);
    return f;
}

// ─────────────────────────────────────────
//  Menu principal
// ─────────────────────────────────────────
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

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    Arvore arvore;
    inicializarArvore(&arvore);

    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Funcionario f = lerFuncionario(&arvore);
                arvore.raiz = inserir(arvore.raiz, f);
                printf("\n  ✓ Funcionário inserido com sucesso!\n");
                break;
            }
            case 2: {
                char cpf[12];
                lerCPF(cpf);
                No *resultado = buscar(arvore.raiz, cpf);
                exibirFuncionario(resultado);
                break;
            }
            case 3: {
                char cpf[12];
                lerCPF(cpf);
                atualizar(arvore.raiz, cpf);
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

    } while (opcao != 0);

    return 0;
}