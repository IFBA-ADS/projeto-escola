#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define PROFESSOR_NAO_ENCONTRADO 3
#define LIMITE_DA_SALA 20

typedef struct disciplina
{
	char nome[100];
	char professor[100];
	char semestre[50];
	int matricula;
	int qtd_matriculados;
	Pessoa alunosMatriculados[LIMITE_DA_SALA];
} Disciplina;

int menu_Disciplina();

int inserir_Disciplina(Disciplina lista_disciplina[], Pessoa lista_professor[], int qtd_disciplina, int qtd_professor);

void listar_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina);

#endif
