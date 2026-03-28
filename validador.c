#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validador.h"
#include "arvore.h"

// ─────────────────────────────────────────
//  Remove pontos e traços do CPF
// ─────────────────────────────────────────
void limparCPF(const char *entrada, char *saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isdigit(entrada[i])) {
            saida[j++] = entrada[i];
        }
    }
    saida[j] = '\0';
}

// ─────────────────────────────────────────
//  Formata CPF para exibição
//  Ex: "12345678901" → "123.456.789-01"
// ─────────────────────────────────────────
void formatarCPF(const char *cpf, char *saida) {
    snprintf(saida, 15, "%c%c%c.%c%c%c.%c%c%c-%c%c",
        cpf[0], cpf[1], cpf[2],
        cpf[3], cpf[4], cpf[5],
        cpf[6], cpf[7], cpf[8],
        cpf[9], cpf[10]);
}

// ─────────────────────────────────────────
//  Valida formato e dígitos verificadores
//  Retorna 1 = válido | 0 = inválido
// ─────────────────────────────────────────
int validarFormatoCPF(const char *cpf) {
    char limpo[12];
    limparCPF(cpf, limpo);

    // Deve ter exatamente 11 dígitos
    if (strlen(limpo) != 11) return 0;

    // Rejeita sequências iguais (ex: 111.111.111-11)
    int todosIguais = 1;
    for (int i = 1; i < 11; i++) {
        if (limpo[i] != limpo[0]) { todosIguais = 0; break; }
    }
    if (todosIguais) return 0;

    // 1º dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++)
        soma += (limpo[i] - '0') * (10 - i);
    int resto = (soma * 10) % 11;
    if (resto == 10 || resto == 11) resto = 0;
    if (resto != (limpo[9] - '0')) return 0;

    // 2º dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++)
        soma += (limpo[i] - '0') * (11 - i);
    resto = (soma * 10) % 11;
    if (resto == 10 || resto == 11) resto = 0;
    if (resto != (limpo[10] - '0')) return 0;

    return 1;
}

// ─────────────────────────────────────────
//  Verifica se CPF já existe na árvore
//  Retorna 1 = já cadastrado | 0 = livre
// ─────────────────────────────────────────
int cpfJaCadastrado(No *raiz, const char *cpf) {
    if (raiz == NULL) return 0;

    int cmp = strcmp(cpf, raiz->dados.cpf);

    if (cmp == 0) return 1;               // Encontrou!
    if (cmp < 0)  return cpfJaCadastrado(raiz->left,  cpf);
    else          return cpfJaCadastrado(raiz->right, cpf);
}