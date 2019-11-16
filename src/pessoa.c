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
	printf("4 - Editar\n");
	printf("5 - Voltar\n\n");

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

int criar_Pessoa(Pessoa* novaPessoa, int ativo){
	printf("\nDigite a Matricula\n");
	scanf("%d%*c", &novaPessoa->matricula);
	
	if (novaPessoa->matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome\n");
	cfgets(novaPessoa->nome, TAM_NOME, stdin);

	printf("\nDigite o Sexo [M/F]\n");
	scanf("%c", &novaPessoa->sexo);
	limpaBuffer();
	
	novaPessoa->sexo = toupper(novaPessoa->sexo);
	if(novaPessoa->sexo != 'M' && novaPessoa->sexo != 'F')
		return ERRO_CADASTRO_SEXO;
	
	char nascimento[TAM_DATA];

	printf("\nDigite a data de nascimento no formato 99/99/9999\n");
	cfgets(nascimento, TAM_DATA, stdin);

	if(validarData(nascimento, strlen(nascimento), &novaPessoa->data_nascimento) == 0)
		return ERRO_CADASTRO_DATA;

	printf("\nDigite o CPF no formato 999.999.999-99\n");
	cfgets(novaPessoa->cpf, TAM_CPF, stdin);

	if(validarCPF(novaPessoa->cpf, strlen(novaPessoa->cpf)) == 0)
	 	return ERRO_CADASTRO_CPF;

	novaPessoa->ativo = ativo;

	return SUCESSO_CADASTRO;
}

int desativar_Pessoa(Pessoa lista[], int quantidade){
	int matricula;
	printf("\nDigite a Matricula para procurar\n");
	scanf("%d%*c", &matricula);

	int resultado = ERRO_MATRICULA_NAO_ENCONTRADA;
	int index = procurarPorMatricula_Pessoa(lista, quantidade, matricula);

	if(index >= 0){
		lista[index].ativo = 0;
		resultado = SUCESSO_DESATIVAR;
	}
	return resultado;
}

int editar_Pessoa(Pessoa lista[], int quantidade){
	int matricula;
	printf("\nDigite a Matricula para procurar\n");
	scanf("%d%*c", &matricula);

	int resultado = ERRO_MATRICULA_NAO_ENCONTRADA;
	int indice = procurarPorMatricula_Pessoa(lista, quantidade, matricula);

	if(indice >= 0){
		Pessoa pessoa;
		resultado = criar_Pessoa(&pessoa, lista[indice].ativo);
		if(resultado == SUCESSO_EDITAR)
			lista[indice] = pessoa;
	}

	return resultado;
}

void printarMensagemDeErro_Pessoa(int codigo){
	printf("\nNao foi possivel executar a acao. Erro: ");
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
		case ERRO_MATRICULA_NAO_ENCONTRADA:{
			printf("Matricula nao encontrada\n");
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
			Pessoa listaFiltrada[quantidade];
			int total = filtrarAtivos_Pessoa(lista, quantidade, listaFiltrada);
			listar_Pessoa(listaFiltrada, total);
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
				Pessoa listaFiltrada[quantidade];
				int total = filtrarPorSexo_Pessoa(lista, quantidade, sexo, listaFiltrada);
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
			Pessoa listaFiltrada[quantidade];
			int total = filtrarPorNome_Pessoa(lista, quantidade, busca, listaFiltrada);
			listar_Pessoa(listaFiltrada, total);
			break;
		}
		case 5: {
			printf("%s", cabecalho);
			Pessoa listaFiltrada[quantidade];
			int total = filtrarAniversariantes_Pessoa(lista, quantidade, dataAtual().mes, listaFiltrada);
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
		ordenarListaPorNome_Pessoa(lista, quantidade);
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

void ordenarListaPorNome_Pessoa(Pessoa lista[], int max){
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

int filtrarAtivos_Pessoa(Pessoa listaIn[], int quantidadeIn, Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if(listaIn[i].ativo){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int filtrarPorSexo_Pessoa(Pessoa listaIn[], int quantidadeIn, char sexo, Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if((sexo == '-' || listaIn[i].sexo == toupper(sexo) && listaIn[i].ativo)){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int filtrarPorNome_Pessoa(Pessoa listaIn[], int quantidadeIn, char busca[TAM_NOME], Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if((strcmp(busca, "---") == 0 || compararStrings(listaIn[i].nome, busca) && listaIn[i].ativo)){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int filtrarAniversariantes_Pessoa(Pessoa listaIn[], int quantidadeIn, int mes, Pessoa listaOut[]){
	int i, outI;
	for(i = 0, outI = 0; i < quantidadeIn; i++){
		if(listaIn[i].data_nascimento.mes == mes && listaIn[i].ativo){
			listaOut[outI] = listaIn[i];
			outI++;
		}
	}
	return outI;
}

int procurarPorMatricula_Pessoa(Pessoa lista[], int quantidade, int matricula){
	int indice = -1, i;
	for(i = 0; i < quantidade && indice == -1; i++)
		if(lista[i].matricula == matricula && lista[i].ativo)
			indice = i;
	return indice;
}
