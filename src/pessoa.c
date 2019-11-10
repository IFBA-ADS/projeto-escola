#include <stdio.h>
#include <string.h>

#include "../include/pessoa.h"

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

int inserir_Pessoa(Pessoa lista[], int qtd){

	printf("Digite a Matricula\n");
	scanf("%d", &lista[qtd].matricula);
	getchar();
	if (lista[qtd].matricula <= 0)
		return ERRO_CADASTRO_MATRICULA;

	printf("\nDigite o Nome\n");
	fgets(lista[qtd].nome, 100, stdin);

	size_t ln = strlen(lista[qtd].nome) - 1;
	if(lista[qtd].nome[ln] = '\n') // SUBSTITUO O \n por \0
		lista[qtd].nome[ln] = '\0';

	printf("\nDigite o Sexo\n");
	scanf("%c", &lista[qtd].sexo);

	lista[qtd].sexo = toupper(lista[qtd].sexo); //Converte Minuscula para Maiuscula
	if(lista[qtd].sexo != 'M' && lista[qtd].sexo != 'F')
		return ERRO_CADASTRO_SEXO;
	
	int idade;
	printf("\nDigite a Idade no formato xx/xx/xxxx\n");
	scanf("%d", &idade);
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

void listar_Pessoa(Pessoa lista[], int qtd, char sexo){
	int i;

	ordenarListaPorNome(lista, qtd);

	for(i = 0; i < qtd; i++){
		printf("------\n");
		printf("Matricula: %d\n", lista[i].matricula);
		printf("Nome: %s\n", lista[i].nome);
		printf("Sexo: %c\n", lista[i].sexo);
		printf("Data de Nascimento %d/%d/%d\n", lista[i].data_nascimento.dia, lista[i].data_nascimento.mes, lista[i].data_nascimento.ano);
		printf("CPF: %s\n", lista[i].cpf);
	}

	printf("------\n\n");
}

void ordenarListaPorNome(Pessoa lista[], int max){
    Pessoa aux;
    int k, j;
    for (k = 0; k < max - 1; k++) {
        for (j = 0; j < max - k - 1; j++) {
            if (stricmp(lista[j].nome, lista[j + 1].nome) > 0) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}
