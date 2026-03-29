#ifndef VALIDADOR_H
#define VALIDADOR_H

// Remove pontos e traços: "123.456.789-01" → "12345678901"
void limparCPF(const char *entrada, char *saida);

// Formata CPF para exibição: "12345678901" → "123.456.789-01"
void formatarCPF(const char *cpf, char *saida);

// Valida formato e dígitos verificadores do CPF
// Retorna 1 = válido | 0 = inválido
int validarFormatoCPF(const char *cpf);

// Verifica se o CPF já está cadastrado na árvore
// Retorna 1 = já existe | 0 = não existe
// OBS: forward declaration para evitar dependência circular
struct No;
int cpfJaCadastrado(struct No *raiz, const char *cpf);

#endif