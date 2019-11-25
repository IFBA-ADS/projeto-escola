#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define PROFESSOR_NAO_ENCONTRADO 3
#define LIMITE_DA_SALA 20

// Defines: desativar
#define SUCESSO_DESATIVAR 1
#define ERRO_MATRICULA_NAO_ENCONTRADA 6

// Defines: editar
#define SUCESSO_EDITAR 1

#define TAM_NOME 100

typedef struct disciplina
{
	int matricula;
	char nome[100];
	char semestre[50];
	int matriculaProfessor;
	int qtd_matriculados;
	Pessoa alunosMatriculados[LIMITE_DA_SALA];
} Disciplina;

int menu_Disciplina();

void printarMensagemDeErro_Disciplina(int codigoErro);

int criar_Disciplina(Disciplina *novaDisciplina, Pessoa lista_professor[], int qtd_professor);

void listar_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_professor[], int qtd_professor);

int editar_Disciplina(Disciplina lista[], int quantidade, Pessoa lista_professor[], int qtd_professor);

int matricularAlunos(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno);

int desmatricularAluno(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno);

void listarMatriculados(Disciplina lista_disciplina[], int qtd_disciplina);

int procurarPorMatricula_Disciplina(Disciplina lista[], int quantidade, int matricula);

#endif
