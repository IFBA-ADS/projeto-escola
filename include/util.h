#ifndef UTIL_H
#define UTIL_H

#define TAM_CPF 14
#define TAM_CPF_COMPACT 11
#define TAM_DATA 10
#define TAM_DATA_COMPACT 8

typedef struct dma{
	int dia;
	int mes;
	int ano;
} Data;

int validarCPF(char string[], int tamCPF);

void removerChar(char string[], int tamanho, char remover);

int validarData(char strData[], int tamanho, Data* data);

Data dataAtual();

void removerQuebraDeLinha(char string[], int tamanho);

void cfgets(char* string, int tamanho, FILE* fluxo);

void limpaBuffer();

int compararStrings(const char* string, const char* substring);

#endif
