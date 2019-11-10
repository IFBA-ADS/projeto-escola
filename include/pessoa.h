#ifndef PESSOA_H
#define PESSOA_H

#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3

typedef struct dma{
	int dia, mes, ano;
} Data;

typedef struct pessoa{
	int matricula;
	Data data_nascimento;
	char nome[100];
	char cpf[15];
	char sexo;
} Pessoa;

int menu_Pessoa();

int inserir_Pessoa(Pessoa lista[], int qtd);

void listar_Pessoa(Pessoa lista[], int qtd);

#endif
