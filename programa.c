#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_LISTA_PESSOA 5

#include "src/util.c"
#include "src/pessoa.c"
#include "src/disciplina.c"

#define TAM_LISTA_PROFESSOR TAM_LISTA_PESSOA
#define TAM_LISTA_ALUNO TAM_LISTA_PESSOA
#define TAM_DISCIPLINA TAM_LISTA_PESSOA

int menu_Principal();

void main(){
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

	while (!sair)
	{

		opcaoPrincipal = menu_Principal();

		switch(opcaoPrincipal){

			case 1:{	// Menu Aluno

				voltarAluno = 0;

				while( ! voltarAluno){

					printf("\n### Menu Aluno ### \n\n");
					opcaoAluno = menu_Pessoa(); 
					
					switch(opcaoAluno){
						case 1:{
							if(qtd_aluno + 1 <= TAM_LISTA_ALUNO){
								retornoAluno = criar_Pessoa(&lista_aluno[qtd_aluno]);
								if(retornoAluno == SUCESSO_CADASTRO){
									printf("\nCadastro Realizado com Sucesso\n");
									qtd_aluno++;
								}else{
									printarMensagemDeErro_Pessoa(retornoAluno);
								}
							}
							else{
								printf("\nLimite de alunos alcancado\n");
							}
							break;
						}
						case 2:{
							gerenciarListagem_Pessoa(lista_aluno, qtd_aluno, "\n#### Alunos Cadastrados ###\n\n");
							break;
						}
						case 3:{
							retornoAluno = deletar_Pessoa(lista_aluno, qtd_aluno);
							if(retornoAluno == SUCESSO_DESATIVAR){
								qtd_aluno--;
								printf("\nAluno deletado com Sucesso\n");
							}
							else
								printarMensagemDeErro_Pessoa(retornoAluno);
							break;
						}
						case 4:{
							retornoAluno = editar_Pessoa(lista_aluno, qtd_aluno);
							if(retornoAluno == SUCESSO_EDITAR)
								printf("\nAluno editado com Sucesso\n");
							else
								printarMensagemDeErro_Pessoa(retornoAluno);
							break;
						}
						case 5:{
							limparTela();
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

			case 2:{	//Menu Professor

				voltarProfessor = 0;

				while( ! voltarProfessor){

					printf("\n### Menu Professor ### \n\n");
					opcaoProfessor = menu_Pessoa();

					switch(opcaoProfessor){
						case 1:{
							if(qtd_professor + 1 <= TAM_LISTA_PROFESSOR){
								retornoProfessor = criar_Pessoa(&lista_professor[qtd_professor]);
								if(retornoProfessor == SUCESSO_CADASTRO){
									printf("\nCadastro Realizado com Sucesso\n");
									qtd_professor++;
								}else{
									printarMensagemDeErro_Pessoa(retornoProfessor);
								}
							}
							else{
								printf("\nLimite de professores alcancado\n");
							}
							break;
						}
						case 2:{
							gerenciarListagem_Pessoa(lista_professor, qtd_professor, "\n#### Professores Cadastrados ###\n\n");
							break;
						}
						case 3:{
							retornoProfessor = deletar_Pessoa(lista_professor, qtd_professor);
							if(retornoProfessor == SUCESSO_DESATIVAR){
								qtd_professor--;
								printf("\nProfessor deletado com Sucesso\n");
							}
							else
								printarMensagemDeErro_Pessoa(retornoProfessor);
							break;
						}
						case 4:{
							retornoProfessor = editar_Pessoa(lista_professor, qtd_professor);
							if(retornoProfessor == SUCESSO_EDITAR)
								printf("\nProfessor editado com Sucesso\n");
							else
								printarMensagemDeErro_Pessoa(retornoProfessor);
							break;
						}
						case 5:{
							limparTela();
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
							retornoDisciplina = criar_Disciplina(&lista_disciplina[qtd_disciplina], lista_professor, qtd_professor);
							if(retornoDisciplina == SUCESSO_CADASTRO){
								printf("\nCadastro Realizado Com Sucesso\n");
								qtd_disciplina++;
							}else{
								printarMensagemDeErro_Disciplina(retornoDisciplina);
							}
							break;
						}
						case 2:{
							listar_Disciplina(lista_disciplina, qtd_disciplina, lista_professor, qtd_professor);
							break;
						}
						case 3:{
							retornoDisciplina = matricularAlunos(lista_disciplina, qtd_disciplina, lista_aluno, qtd_aluno);
							if (retornoDisciplina == SUCESSO_CADASTRO)
								printf("Aluno matriculado com sucesso!\n");
							else
								printf("Matricula não realizada. Por favor, tente novamente\n");
							break;
						}
						case 4:{
							retornoDisciplina = desmatricularAluno(lista_disciplina, qtd_disciplina, lista_aluno, qtd_aluno);
							if (retornoDisciplina == SUCESSO_CADASTRO)
								printf("Desmatricula realizada com sucesso\n");
							else
								printf("Por favor, tente novamente\n");
						}
						case 5:{
							listarMatriculados(lista_disciplina, qtd_disciplina);
							break;
						}
						case 6:{
							retornoDisciplina = remover_Disciplina(lista_disciplina, qtd_disciplina);
							if (retornoDisciplina == SUCESSO_CADASTRO){
								qtd_disciplina--;
								printf("Disciplina removida com sucesso\n");
							}
							else
								printf("Por favor, tente novamente\n");
							break;
						}
						case 7:{
							retornoDisciplina = editar_Disciplina(lista_disciplina, qtd_disciplina, lista_professor, qtd_professor);
							if(retornoDisciplina == SUCESSO_EDITAR)
								printf("\nDisciplina editada com Sucesso\n");
							else
								printarMensagemDeErro_Disciplina(retornoDisciplina);
							break;
						}
						case 8:{
							limparTela();
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
	scanf("%d", &opcao_principal);
	limpaBuffer();

	return opcao_principal;
}
