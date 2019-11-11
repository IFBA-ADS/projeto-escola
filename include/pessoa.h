#ifndef PESSOA_H
#define PESSOA_H

#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define ERRO_CADASTRO_CPF 4

#define TAM_CPF 15

typedef struct dma{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct pessoa{
	int matricula;
	Data data_nascimento;
	char nome[100];
	char cpf[TAM_CPF];
	char sexo;
} Pessoa;

int menu_Pessoa();

int inserir_Pessoa(Pessoa lista[], int qtd);

void printarMensagemDeErro_Pessoa(int codigo);

void listar_Pessoa(Pessoa lista[], int qtd, char sexo);

void ordenarListaPorNome(Pessoa lista[], int max);

int validarCPF(char string[TAM_CPF]);

void removerChar(char string[], int tamanho, char remover);

#endif
