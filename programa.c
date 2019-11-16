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

	while(!sair){

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
								retornoAluno = inserir_Pessoa(lista_aluno, qtd_aluno);
								if(retornoAluno == SUCESSO_CADASTRO){
									printf("\nCadastro Realizado com Sucesso\n");
									qtd_aluno++;
								}else{
									printarMensagemDeErro_Pessoa(retornoAluno);
								}
							}
							else{
								printf("\nLimite de alunos alcançado\n");
							}
							break;
						}
						case 2:{
							gerenciarListagem_Pessoa(lista_aluno, qtd_aluno, "\n#### Alunos Cadastrados ###\n\n");
							break;
						}
						case 3:{
							retornoAluno = desativar_Pessoa(lista_aluno, qtd_aluno);
							if(retornoAluno == SUCESSO_DESATIVAR)
								printf("\nAluno deletado com Sucesso\n");
							else
								printarMensagemDeErro_Pessoa(retornoAluno);
							break;
						}
						case 4:{
							printf("\nNao implementado\n\n");
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
								retornoProfessor = inserir_Pessoa(lista_professor, qtd_professor);
								if(retornoProfessor == SUCESSO_CADASTRO){
									printf("\nCadastro Realizado com Sucesso\n");
									qtd_professor++;
								}else{
									printarMensagemDeErro_Pessoa(retornoProfessor);
								}
							}
							else{
								printf("\nLimite de professores alcançado\n");
							}
							break;
						}
						case 2:{
							gerenciarListagem_Pessoa(lista_professor, qtd_professor, "\n#### Professores Cadastrados ###\n\n");
							break;
						}
						case 3:{
							retornoProfessor = desativar_Pessoa(lista_professor, qtd_professor);
							if(retornoProfessor == SUCESSO_DESATIVAR)
								printf("\nProfessor deletado com Sucesso\n");
							else
								printarMensagemDeErro_Pessoa(retornoProfessor);
							break;
						}
						case 4:{
							printf("\nNao implementado\n\n");
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
	scanf("%d",&opcao_principal);

	return opcao_principal;
}
