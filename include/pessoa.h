#ifndef PESSOA_H
#define PESSOA_H

// Defines: cadastrar
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define ERRO_CADASTRO_CPF 4
#define ERRO_CADASTRO_DATA 5

// Defines: desativar
#define SUCESSO_DESATIVAR 1
#define ERRO_MATRICULA_NAO_ENCONTRADA 6

// Defines: editar
#define SUCESSO_EDITAR 1

#define TAM_NOME 100

typedef struct pessoa{
	int matricula;
	Data data_nascimento;
	char nome[TAM_NOME];
	char cpf[TAM_CPF];
	char sexo;
} Pessoa;

int menu_Pessoa();

int menuListar_Pessoa();

int criar_Pessoa(Pessoa* pessoa);

int deletar_Pessoa(Pessoa lista[], int quantidade);

void printarMensagemDeErro_Pessoa(int codigo);

void gerenciarListagem_Pessoa(Pessoa lista[], int quantidade, char cabecalho[50]);

void listar_Pessoa(Pessoa lista[], int quantidade);

void ordenarListaPorNome_Pessoa(Pessoa lista[], int max);

void ordenarListaPorData_Pessoa(Pessoa lista[], int max);

int filtrarPorSexo_Pessoa(Pessoa listaIn[], int quantidadeIn, char sexo, Pessoa listaOut[]);

int filtrarPorNome_Pessoa(Pessoa listaIn[], int quantidadeIn, char busca[TAM_NOME], Pessoa listaOut[]);

int filtrarAniversariantes_Pessoa(Pessoa listaIn[], int quantidadeIn, int mes, Pessoa listaOut[]);

int procurarPorMatricula_Pessoa(Pessoa lista[], int quantidade, int matricula);

void copiarLista_Pessoa(Pessoa listaIn[], int quantidadeIn, Pessoa listaOut[]);

#endif
