#ifndef VALIDADOR_H
#define VALIDADOR_H
 
// ─────────────────────────────────────────
//  Validação de formato do CPF
// ─────────────────────────────────────────
 
// Remove pontos e traços: "123.456.789-01" → "12345678901"
void limparCPF(const char *entrada, char *saida);
 
// Formata CPF para exibição: "12345678901" → "123.456.789-01"
void formatarCPF(const char *cpf, char *saida);
 
// Valida o formato e dígitos verificadores do CPF
// Retorna 1 = válido | 0 = inválido
int validarFormatoCPF(const char *cpf);
 
// ─────────────────────────────────────────
//  Validação de existência na árvore
// ─────────────────────────────────────────
 
// Verifica se o CPF já está cadastrado na árvore
// Retorna 1 = já existe | 0 = não existe
int cpfJaCadastrado(struct No *raiz, const char *cpf);
 
#endif // VALIDADOR_H