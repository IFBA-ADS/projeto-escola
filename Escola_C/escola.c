/*Escola-V01.c, 11/10/2019, Autor: Reinan de Souza, orientaçao Renato Novais
Descrição: esta versão tem:
-Funções
-Struct
-size_t
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_LISTA_ALUNO 5
#define TAM_LISTA_PROFESSOR 5
#define TAM_DISCIPLINA 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define PROFESSOR_NAO_ENCONTRADO 1

typedef struct dma{
	int dia, mes, ano;

}Data;

typedef struct pessoa{
	
	int matricula;
	Data data_nascimento;
	char nome[100], cpf[15];
	char sexo;

}Pessoa;

typedef struct disciplina{

	char nome[100], professor [100], semestre[50];
	int matricula;

}Disciplina;


int menu_Principal();
int menu_Pessoa();
int menu_Disciplina();
int inserir_Pessoa();
int inserir_Disciplina();
void listar_Pessoa();
void listar_Disciplina();


int main(void){

	Pessoa lista_aluno[TAM_LISTA_ALUNO];
	Pessoa lista_professor[TAM_LISTA_PROFESSOR];
	Disciplina lista_disciplina[TAM_DISCIPLINA];

	int qtd_aluno = 0;
	int qtd_professor = 0;
	int qtd_disciplina = 0;

	int sair = 0;

	int opcaoPrincipal, opcaoAluno, opcaoProfessor, opcaoDisciplina = 0;
	int voltarAluno, voltarProfessor, voltarDisciplina;
	int retornoAluno, retornoProfessor, retornoDisciplina; 

	while(!sair){

		opcaoPrincipal = menu_Principal();

		switch(opcaoPrincipal){

			case 1:{ // Menu Aluno

				voltarAluno = 0;

				while( ! voltarAluno){

					printf("\n### Menu Aluno ### \n\n");
					opcaoAluno = menu_Pessoa(); 
					
					switch(opcaoAluno){
						case 1:{

							retornoAluno = inserir_Pessoa(lista_aluno, qtd_aluno);
							if(retornoAluno == SUCESSO_CADASTRO){
								printf("Cadastro Realizado com Sucesso\n");
								qtd_aluno++;
							}else{
								switch(retornoAluno){
									case ERRO_CADASTRO_MATRICULA:{
										printf("Matricula Invalida\n");
										break;
									}
									case ERRO_CADASTRO_SEXO:{
										printf("Sexo Invalido\n");
										break;
									}
									default:{
										printf("Erro Desconhecido\n");
										break;
									}
								}
								printf("Nao foi possivel fazer o Cadastro\n");
							}
							break;
						}
						case 2:{
							printf("\n#### Alunos Cadastrados ###\n\n");
							listar_Pessoa(lista_aluno, qtd_aluno);
							break;
						}
						case 5:{
							printf("\e[H\e[2J"); // Funciona Melhor que o System ("Clear"). 
							voltarAluno = 1;
							break;
						}
						default:{
							printf("\nOpcao Invalida\n");
							break;
						}
					}
				}
				break;
			}

			case 2:{ //Menu Professor

				voltarProfessor = 0;

				while( ! voltarProfessor){

					printf("\n### Menu Professor ### \n\n");
					opcaoProfessor = menu_Pessoa();

					switch(opcaoProfessor){
						case 1:{

							retornoProfessor = inserir_Pessoa(lista_professor, qtd_professor);
							if(retornoProfessor == SUCESSO_CADASTRO){
								printf("Cadastro Realizado com Sucesso\n");
								qtd_professor++;
							}else{
								switch(retornoProfessor){
									case ERRO_CADASTRO_MATRICULA:{
										printf("Matricula Invalida\n");
										break;
									}
									case ERRO_CADASTRO_SEXO:{
										printf("Sexo Invalido\n");
										break;
									}
									default:{
										printf("Erro Desconhecido\n");
										break;
									}
								}
								printf("Nao foi possivel fazer o Cadastro\n");
							}
							break;
						}
						case 2:{
							printf("\n#### Professores Cadastrados ###\n\n");
							listar_Pessoa(lista_professor, qtd_professor);
							break;
						}
						case 5:{
							printf("\e[H\e[2J"); // Funciona Melhor que o System ("Clear"). 
							voltarProfessor = 1;
							break;
						}
						default:{
							printf("\nOpcao Invalida\n");
							break;
						}
					}

				}

				break;
			}

			case 3:{	//Menu Disciplina

				voltarDisciplina = 0;

				while( ! voltarDisciplina){

					opcaoDisciplina = menu_Disciplina();

					switch(opcaoDisciplina){
						case 1:{
							
							retornoDisciplina = inserir_Disciplina(lista_disciplina, lista_professor, qtd_disciplina, qtd_professor);
							if(retornoDisciplina == SUCESSO_CADASTRO){
								printf("\nCadastro Realizado Com Sucesso\n");
								qtd_disciplina++;

							}else{
								switch(retornoDisciplina){
									case ERRO_CADASTRO_MATRICULA:{
										printf("Matricula Invalida\n");
										break;
									}
									case PROFESSOR_NAO_ENCONTRADO:{
										printf("Professor Nao Encontrado\n");
										break;
									}

									default:{
										printf("Erro Desconhecido\n");
										break;
									}
								}
								printf("Nao foi possivel fazer o Cadastro\n");

							}
							break;
						}
						case 2:{
							listar_Disciplina(lista_disciplina, qtd_disciplina);
							break;
						}
						case 5:{
							printf("\e[H\e[2J"); // Funciona Melhor que o System ("Clear"). 
							voltarDisciplina = 1;
							break;
						}
						default:{
							printf("\nOpcao Invalida\n");
							break;
						}
					}

				}
				break;
			}

			case 4:{
				printf("\nEncerrando Sistema\n");
				sair = 1;
				break;
			}
			default:{
				printf("\nOpcao Invalida\n");
				break;
			}
		}
	}
}

int menu_Principal(){

	int opcao_principal;

	printf("\n#### Menu Principal ###\n\n");
	printf("1 - Aluno\n");
	printf("2 - Professor\n");
	printf("3 - Disciplina\n");
	printf("4 - Sair\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao_principal);

	return opcao_principal;

}

int menu_Pessoa(){

	int opcao;

	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Consultar\n");
	printf("4 - Apagar\n");
	printf("5 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao);

	return opcao;
}

int menu_Disciplina(){

	int opcao_Disciplina;

	printf("\n### Menu Disciplina ### \n\n");
	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Consultar\n");
	printf("4 - Apagar\n");
	printf("5 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao_Disciplina);

	return opcao_Disciplina;
}

int inserir_Pessoa(Pessoa lista[], int qtd){

	printf("Digite a Matricula\n");
	scanf("%d",&lista[qtd].matricula);
	getchar();
	if (lista[qtd].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome\n");
	fgets(lista[qtd].nome, 100, stdin);

	size_t ln = strlen(lista[qtd].nome) - 1;
	if(lista[qtd].nome[ln] = '\n') // SUBSTITUO O \n por \0
		lista[qtd].nome[ln] = '\0';

	printf("\nDigite o Sexo\n");
	scanf("%c",&lista[qtd].sexo);

	lista[qtd].sexo = toupper(lista[qtd].sexo); //Converte Minuscula para Maiuscula
	if(lista[qtd].sexo != 'M' && lista[qtd].sexo != 'F')
		return ERRO_CADASTRO_SEXO;
	
	int idade;
	printf("\nDigite a Idade no formato xx/xx/xxxx\n");
	scanf("%d",&idade);
	getchar();

	lista[qtd].data_nascimento.dia = idade / 1000000;
	lista[qtd].data_nascimento.mes = idade % 1000000 / 10000;
	lista[qtd].data_nascimento.ano = idade % 1000000 % 10000;

	printf("\nDigite CPF\n");
	fgets(lista[qtd].cpf, 15, stdin);

	ln = strlen(lista[qtd].cpf) - 1;
	if(lista[qtd].cpf[ln] = '\n')
		lista[qtd].cpf[ln] = '\0';

	printf("\n");

	return SUCESSO_CADASTRO;

}

int inserir_Disciplina(	Disciplina lista_disciplina[], Pessoa lista_professor[], int qtd_disciplina, int qtd_professor){

	int i;

	printf("\nMatricula da Disciplina\n");
	scanf("%d",&lista_disciplina[qtd_disciplina].matricula);
	getchar();

	if(lista_disciplina[qtd_disciplina].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;
	
	printf("\nNome da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].nome, 50, stdin);

	size_t ln = strlen(lista_disciplina[qtd_disciplina].nome) - 1;
	if(lista_disciplina[qtd_disciplina].nome[ln] = '\n')
		lista_disciplina[qtd_disciplina].nome[ln] = '\0';

	printf("\nSemestre da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].semestre, 50, stdin);

	printf("\nProfessor da Disciplina\n");
	fgets(lista_disciplina[qtd_disciplina].professor, 100, stdin);

	ln = strlen(lista_disciplina[qtd_disciplina].professor) - 1;
	if(lista_disciplina[qtd_disciplina].professor[ln] = '\n')
		lista_disciplina[qtd_disciplina].professor[ln] = '\0';
	
	for(i = 0; i < qtd_professor; i++)
		if(lista_disciplina[qtd_disciplina].professor != lista_professor[i].nome)
			return PROFESSOR_NAO_ENCONTRADO;
	
	return SUCESSO_CADASTRO;

}
	
void listar_Pessoa(Pessoa lista[], int qtd){
	int i;

	for(i = 0; i < qtd; i++){
		printf("------\n");
		printf("Matricula: %d\n",lista[i].matricula);
		printf("Nome: %s\n",lista[i].nome);
		printf("Sexo: %c\n",lista[i].sexo);
		printf("Data de Nascimento %d/%d/%d\n",lista[i].data_nascimento.dia, lista[i].data_nascimento.mes, lista[i].data_nascimento.ano);
		printf("CPF: %s\n",lista[i].cpf);
	}

	printf("------\n\n");
}

void listar_Disciplina(Disciplina lista_disciplina[], int qtd_disciplina){
	int i;

	for(i = 0; i < qtd_disciplina; i++){
		printf("-------\n");
		printf("Matricula: %d\n", lista_disciplina[i].matricula);
		printf("Nome: %s\n", lista_disciplina[i].nome);
		printf("Semestre %s", lista_disciplina[i].semestre);
		printf("Professor: %s\n", lista_disciplina[i].professor);
	}

	printf("----------\n");
}