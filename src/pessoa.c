#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "../include/pessoa.h"

int menu_Pessoa(){

	int opcao;

	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Apagar\n");
	printf("4 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d%*c",&opcao);

	return opcao;
}

int menuListar_Pessoa(){

	int opcao;

	printf("\n");
	printf("1 - Ordenado por nome\n");
	printf("2 - Ordenado por data de nascimento\n");
	printf("3 - Filtrar por sexo\n");
	printf("4 - Filtrar por nome\n");
	printf("5 - Aniversariantes do mes\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d%*c",&opcao);

	return opcao;
}

int inserir_Pessoa(Pessoa lista[], int quantidade){
	printf("\nDigite a Matricula\n");
	scanf("%d%*c", &lista[quantidade].matricula);
	
	if (lista[quantidade].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome\n");
	cfgets(lista[quantidade].nome, TAM_NOME, stdin);

	printf("\nDigite o Sexo [M/F]\n");
	scanf("%c", &lista[quantidade].sexo);
	limpaBuffer();
	
	lista[quantidade].sexo = toupper(lista[quantidade].sexo);
	if(lista[quantidade].sexo != 'M' && lista[quantidade].sexo != 'F')
		return ERRO_CADASTRO_SEXO;
	
	char nascimento[TAM_DATA];

	printf("\nDigite a data de nascimento no formato 99/99/9999\n");
	cfgets(nascimento, TAM_DATA, stdin);

	if(validarData(nascimento, strlen(nascimento), &lista[quantidade].data_nascimento) == 0)
		return ERRO_CADASTRO_DATA;

	printf("\nDigite o CPF no formato 999.999.999-99\n");
	cfgets(lista[quantidade].cpf, TAM_CPF, stdin);

	if(validarCPF(lista[quantidade].cpf, strlen(lista[quantidade].cpf)) == 0)
	 	return ERRO_CADASTRO_CPF;

	return SUCESSO_CADASTRO;
}

void printarMensagemDeErro_Pessoa(int codigo){
	printf("\nNao foi possivel fazer o Cadastro. Erro: ");
	switch(codigo){
		case ERRO_CADASTRO_MATRICULA:{
			printf("Matricula Invalida\n");
			break;
		}
		case ERRO_CADASTRO_SEXO:{
			printf("Sexo Invalido\n");
			break;
		}
		case ERRO_CADASTRO_CPF:{
			printf("CPF Invalido\n");
			break;
		}
		case ERRO_CADASTRO_DATA:{
			printf("Data Invalida\n");
			break;
		}
		default:{
			printf("Erro Desconhecido\n");
			break;
		}
	}
}

void gerenciarListagem_Pessoa(Pessoa lista[], int quantidade, char cabecalho[50]){
	int opcao = menuListar_Pessoa();
	switch(opcao){
		case 1: {
			printf("%s", cabecalho);
			listar_Pessoa(lista, quantidade);
			break;
		}
		case 2: {
			printf("Nao implementado\n\n");
			break;
		}
		case 3: {
			printf("\nDigite o sexo pelo qual deseja filtrar [m/f]\n");
			char sexo;
			scanf("%c", &sexo);
			limpaBuffer();
			sexo = toupper(sexo);
			if(sexo == 'M' || sexo == 'F'){
				printf("%s", cabecalho);
				Pessoa listaFiltrada[TAM_LISTA_PESSOA];
				int total = filtrarPorSexo(lista, quantidade, sexo, listaFiltrada);
				listar_Pessoa(listaFiltrada, total);
			}else{
				printf("Sexo Invalido\n");
			}
			break;
		}
		case 4: {
			char busca[TAM_NOME];
			int tamanhoBusca;
			do{
				printf("\nDigite o termo de busca\n");
				cfgets(busca, TAM_NOME, stdin);
				if(strlen(busca) < 3)
					printf("Minimo de 3 caracteres\n");
			}while(strlen(busca) < 3);
			printf("%s", cabecalho);
			Pessoa listaFiltrada[TAM_LISTA_PESSOA];
			int total = filtrarPorNome(lista, quantidade, busca, listaFiltrada);
			listar_Pessoa(listaFiltrada, total);
			break;
		}
		case 5: {
			printf("%s", cabecalho);
			Pessoa listaFiltrada[TAM_LISTA_PESSOA];
			int total = filtrarAniversariantes(lista, quantidade, dataAtual().mes, listaFiltrada);
			listar_Pessoa(listaFiltrada, total);
			break;
		}
		default: {
			printf("\nOpcao Invalida\n");
			break;
		}
	}
}

void listar_Pessoa(Pessoa lista[], int quantidade){
	if(quantidade > 0){
		int i;
		ordenarListaPorNome(lista, quantidade);
		for(i = 0; i < quantidade; i++){
			printf("------\n");
			printf("Matricula: %d\n", lista[i].matricula);
			printf("Nome: %s\n", lista[i].nome);
			printf("Sexo: %c\n", lista[i].sexo);
			printf("Data de Nascimento %d/%d/%d\n", lista[i].data_nascimento.dia, lista[i].data_nascimento.mes, lista[i].data_nascimento.ano);
			printf("CPF: %s\n", lista[i].cpf);
			printf("------\n");
		}
	}else{
		printf("-------------------------\n");
		printf("Nenum registro encontrado\n");
		printf("-------------------------\n");
	}
	printf("\n");
}

void ordenarListaPorNome(Pessoa lista[], int max){
    Pessoa aux;
    int k, j;
    for (k = 0; k < max - 1; k++) {
        for (j = 0; j < max - k - 1; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

int filtrarPorSexo(Pessoa listaIn[], int quantidadeIn, char sexo, Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if(sexo == '-' || listaIn[i].sexo == toupper(sexo)){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int filtrarPorNome(Pessoa listaIn[], int quantidadeIn, char busca[TAM_NOME], Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if(strcmp(busca, "---") == 0 || compararStrings(listaIn[i].nome, busca)){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int filtrarAniversariantes(Pessoa listaIn[], int quantidadeIn, int mes, Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if(listaIn[i].data_nascimento.mes == mes){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}
