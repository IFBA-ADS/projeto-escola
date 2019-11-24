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

int criar_Disciplina(Disciplina *novaDisciplina, Pessoa lista_professor[], int qtd_professor)
{

	int i;

	printf("\nDigite a Matricula da Disciplina\n");
	scanf("%d", &novaDisciplina->matricula);
	limpaBuffer();

	if (novaDisciplina->matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome da Disciplina\n");
	cfgets(novaDisciplina->nome, TAM_NOME, stdin);

	printf("\nDigite o Semestre da Disciplina\n");
	cfgets(novaDisciplina->semestre, 50, stdin);

	printf("\nDigite o Professor da Disciplina\n");
	cfgets(novaDisciplina->professor, 100, stdin);

	for (i = 0; i < qtd_professor; i++)
		if (novaDisciplina->professor != lista_professor[i].nome)
			return PROFESSOR_NAO_ENCONTRADO;

	lista_disciplina[qtd_disciplina].qtd_matriculados = 0;


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

int procurarPorMatricula_Disciplina(Disciplina lista[], int quantidade, int matricula)
{
	int indice = -1, i;
	for (i = 0; i < quantidade && indice == -1; i++)
		if (lista[i].matricula == matricula)
			indice = i;
	return indice;
}

