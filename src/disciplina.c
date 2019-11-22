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

	printf("\nMatricula da Disciplina\n");
	scanf("%d", &lista_disciplina[qtd_disciplina].matricula);
	getchar();

	if (lista_disciplina[qtd_disciplina].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nNome da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].nome, 50, stdin);

	size_t ln = strlen(lista_disciplina[qtd_disciplina].nome) - 1;
	if (lista_disciplina[qtd_disciplina].nome[ln] = '\n')
		lista_disciplina[qtd_disciplina].nome[ln] = '\0';

	printf("\nSemestre da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].semestre, 50, stdin);

	printf("\nProfessor da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].professor, 100, stdin);

	ln = strlen(lista_disciplina[qtd_disciplina].professor) - 1;
	if (lista_disciplina[qtd_disciplina].professor[ln] = '\n')
		lista_disciplina[qtd_disciplina].professor[ln] = '\0';

	for (i = 0; i < qtd_professor; i++)
		if (lista_disciplina[qtd_disciplina].professor != lista_professor[i].nome)
			return PROFESSOR_NAO_ENCONTRADO;

	return SUCESSO_CADASTRO;
}

void remover_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina)
{
	int matriculaDisciplina, indiceDaDisciplina = 0;
	printf("DIgite a matricula da disciplina que deseja remover\n");
	scanf("%d", &matriculaDisciplina);
	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	for (int cont = indiceDaDisciplina; cont < qtd_disciplina; cont++)
	{
		lista_disciplina[cont] = lista_disciplina[cont + 1];
	}
}

void listar_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina)
{
	int i;

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

int editar_Disciplina(Disciplina lista[], int quantidade)
{
	int matricula;
	printf("\nDigite a Matricula para procurar\n");
	scanf("%d", &matricula);
	limpaBuffer();

	int resultado = ERRO_MATRICULA_NAO_ENCONTRADA;
	int indice = procurarPorMatricula_Disciplina(lista, quantidade, matricula);

	if (indice >= 0)
	{
		Disciplina disciplina;
		//resultado = criar_disciplina(&disciplina); É correto mexer diretamente com a Struct?
		if (resultado == SUCESSO_EDITAR)
			lista[indice] = disciplina;
	}

	return resultado;
}


int matricularAlunos(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno, int qtd_matriculados)
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

	lista_disciplina[indiceDaDisciplina].alunosMatriculados[qtd_matriculados] = lista_aluno[indiceDoAluno];
	return SUCESSO_CADASTRO;
}

void desmatricularAluno(Disciplina lista_disciplina[], int qtd_disciplina, Pessoa lista_aluno[], int qtd_aluno, int qtd_matriculados)
{
	int matriculaDisciplina, matriculaAluno, indiceDaDisciplina = 0, indiceDoAluno = 0, indiceDoMatriculado = 0;
	printf("Digite a matricula da disciplina\n");
	scanf("%d", &matriculaDisciplina);
	printf("Digite a matricula do aluno\n");
	scanf("%d", &matriculaAluno);
	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	while (lista_disciplina[indiceDaDisciplina].alunosMatriculados[indiceDoMatriculado].matricula != matriculaAluno && indiceDoAluno < qtd_matriculados)
		indiceDoMatriculado++;
	for (int cont = indiceDoMatriculado; cont < qtd_matriculados; cont++)
	{
		lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont] = lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont + 1];
	}
}

void listarMatriculados(Disciplina lista_disciplina[], int qtd_disciplina, int qtd_matriculados)
{
	int matriculaDisciplina, indiceDaDisciplina = 0;
	printf("Digite o codigo da disciplina\n");
	scanf("%d", &matriculaDisciplina);

	while (lista_disciplina[indiceDaDisciplina].matricula != matriculaDisciplina && indiceDaDisciplina < qtd_disciplina)
		indiceDaDisciplina++;
	printf("Os alunos matriculados sao:\n");
	for (int cont = 0; cont < qtd_matriculados; cont++)
	{
		printf("%s\n", lista_disciplina[indiceDaDisciplina].alunosMatriculados[cont].nome);
	}
}

int procurarPorMatricula_Disciplina(Disciplina lista[], int quantidade, int matricula)
{
	int indice = -1, i;
	for (i = 0; i < quantidade && indice == -1; i++)
		if (lista[i].matricula == matricula)
			indice = i;
	return indice;
}

