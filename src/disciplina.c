#include <stdio.h>

#include "../include/disciplina.h"

int menu_Disciplina()
{

	int opcao_Disciplina;

	printf("\n### Menu Disciplina ### \n\n");
	printf("1 - Cadastrar\n");
	printf("2 - Listar Disciplinas\n");
	printf("3 - Matricular Aluno\n");
	printf("4 - Desmatricular Aluno\n");
	printf("5 - Listar Matriculados\n");
	printf("6 - Deletar Disciplina\n");
	printf("7 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d", &opcao_Disciplina);

	return opcao_Disciplina;
}

int inserir_Disciplina(Disciplina lista_disciplina[], Pessoa lista_professor[], int qtd_disciplina, int qtd_professor)
{

	int i;

	printf("\nDigite a Matricula da Disciplina\n");
	scanf("%d", &lista_disciplina[qtd_disciplina].matricula);
	getchar();

	if (lista_disciplina[qtd_disciplina].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].nome, 50, stdin);

	size_t ln = strlen(lista_disciplina[qtd_disciplina].nome) - 1;
	if (lista_disciplina[qtd_disciplina].nome[ln] = '\n')
		lista_disciplina[qtd_disciplina].nome[ln] = '\0';

	printf("\nDigite o Semestre da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].semestre, 50, stdin);

	printf("\nDigite o Professor da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].professor, 100, stdin);

	lista_disciplina[qtd_disciplina].qtd_matriculados=0;

	ln = strlen(lista_disciplina[qtd_disciplina].professor) - 1;
	if (lista_disciplina[qtd_disciplina].professor[ln] = '\n')
		lista_disciplina[qtd_disciplina].professor[ln] = '\0';

	for (i = 0; i < qtd_professor; i++)
		if (lista_disciplina[qtd_disciplina].professor != lista_professor[i].nome)
			return PROFESSOR_NAO_ENCONTRADO;



	return SUCESSO_CADASTRO;
}

int remover_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina)
{
	int matriculaDisciplina, indiceDaDisciplina = 0;
	printf("Digite a matricula da disciplina que deseja remover\n");
	scanf("%d", &matriculaDisciplina);
	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	for (int cont = indiceDaDisciplina; cont < qtd_disciplina; cont++)
	{
		lista_disciplina[cont] = lista_disciplina[cont + 1];
	}
	return SUCESSO_CADASTRO;
}

void listar_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina)
{
	int i;
	if (qtd_disciplina > 0)
	{
		for (i = 0; i < qtd_disciplina; i++)
		{
			printf("-------\n");
			printf("Matricula: %d\n", lista_disciplina[i].matricula);
			printf("Nome: %s\n", lista_disciplina[i].nome);
			printf("Semestre %s", lista_disciplina[i].semestre);
			printf("Professor: %s\n", lista_disciplina[i].professor);
		}

		printf("----------\n");
	}
	else
		printf("Nenhuma disciplina cadastrada\n");
}

int matricularAlunos(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno)
{
	int matriculaDisciplina, matriculaAluno, indiceDaDisciplina = 0, indiceDoAluno = 0;
	printf("Digite a matricula da disciplina\n");
	scanf("%d", &matriculaDisciplina);
	printf("Digite a matricula do aluno\n");
	scanf("%d", &matriculaAluno);
	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	while (lista_aluno[indiceDoAluno].matricula != matriculaAluno && indiceDoAluno < qtd_aluno)
		indiceDoAluno++;

	int qtd_matriculados = lista_disciplina[indiceDaDisciplina].qtd_matriculados;
	lista_disciplina[indiceDaDisciplina].alunosMatriculados[qtd_matriculados] = lista_aluno[indiceDoAluno];
	qtd_matriculados++;
	lista_disciplina[indiceDaDisciplina].qtd_matriculados = qtd_matriculados;	
	return SUCESSO_CADASTRO;
}

int desmatricularAluno(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno)
{
	int matriculaDisciplina, matriculaAluno, indiceDaDisciplina = 0, indiceDoAluno = 0, indiceDoMatriculado = 0;
	printf("Digite a matricula da disciplina\n");
	scanf("%d", &matriculaDisciplina);
	printf("Digite a matricula do aluno\n");
	scanf("%d", &matriculaAluno);
	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	int qtd_matriculados = lista_disciplina[indiceDaDisciplina].qtd_matriculados;
	while (lista_disciplina[indiceDaDisciplina].alunosMatriculados[indiceDoMatriculado].matricula != matriculaAluno && indiceDoAluno < qtd_matriculados)
		indiceDoMatriculado++;
	for (int cont = indiceDoMatriculado; cont < qtd_matriculados; cont++)
	{
		lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont] = lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont + 1];
	}
	qtd_matriculados--;
	lista_disciplina[indiceDaDisciplina].qtd_matriculados = qtd_matriculados;
	return SUCESSO_CADASTRO;
}

void listarMatriculados(Disciplina lista_disciplina[], int qtd_disciplina)
{
	int matriculaDisciplina, indiceDaDisciplina = 0;
	printf("Digite o codigo da disciplina\n");
	scanf("%d", &matriculaDisciplina);

	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	int qtd_matriculados = lista_disciplina[indiceDaDisciplina].qtd_matriculados;
	printf("A quantidade de matriculados eh: %d\n", qtd_matriculados);
	printf("Os alunos matriculados sao:\n");
	for (int cont = 0; cont < qtd_matriculados; cont++)
	{
		printf("%s\n", lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont].nome);
	}
}
