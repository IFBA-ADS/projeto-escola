#include <stdio.h>
#include <string.h>
#include <time.h>

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

int menuListar_Pessoa(){

	int opcao;

	printf("\n");
	printf("1 - Ordenado por nome\n");
	printf("2 - Ordenado por data de nascimento\n");
	printf("3 - Filtrar por sexo\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao);
	fflush(stdin);

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
	scanf("%1c", &lista[qtd].sexo);
	fflush(stdin);

	lista[qtd].sexo = toupper(lista[qtd].sexo); //Converte Minuscula para Maiuscula
	if(lista[qtd].sexo != 'M' && lista[qtd].sexo != 'F')
		return ERRO_CADASTRO_SEXO;
	
	char nascimento[TAM_DATA];
	printf("\nDigite a data de nascimento no formato 99/99/9999\n");
	fgets(nascimento, TAM_DATA, stdin);
	fflush(stdin);

	if(validarData(nascimento, &lista[qtd].data_nascimento) == 0)
		return ERRO_CADASTRO_DATA;

	printf("\nDigite o CPF no formato 999.999.999-99\n");
	fgets(lista[qtd].cpf, TAM_CPF, stdin);
	if(validarCPF(lista[qtd].cpf) == 0)
		return ERRO_CADASTRO_CPF;

	printf("\n");

	return SUCESSO_CADASTRO;
}

void printarMensagemDeErro_Pessoa(int codigo){
	printf("Nao foi possivel fazer o Cadastro. Erro: ");
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

void gerenciarListagem_Pessoa(Pessoa lista[], int qtd, char cabecalho[50]){
	int opcao = menuListar_Pessoa();
	switch(opcao){
		case 1: {
			printf("%s", cabecalho);
			listar_Pessoa(lista, qtd, '-');
			break;
		}
		case 2: {
			printf("Nao implementado\n\n");
			break;
		}
		case 3: {
			printf("Digite o sexo pelo qual deseja filtrar [m/f]\n");
			char sexo;
			scanf("%1c", &sexo);

			sexo = toupper(sexo);
			if(sexo == 'M' || sexo == 'F'){
				printf("%s", cabecalho);
				listar_Pessoa(lista, qtd, sexo);
			}else{
				printf("Sexo Invalido\n");
			}
			break;
		}
		default: {
			printf("\nOpcao Invalida\n");
			break;
		}
	}
}

void listar_Pessoa(Pessoa lista[], int qtd, char sexo){
	int i;

	ordenarListaPorNome(lista, qtd);

	for(i = 0; i < qtd; i++){
		if(sexo == '-' || lista[i].sexo == toupper(sexo)){
			printf("------\n");
			printf("Matricula: %d\n", lista[i].matricula);
			printf("Nome: %s\n", lista[i].nome);
			printf("Sexo: %c\n", lista[i].sexo);
			printf("Data de Nascimento %d/%d/%d\n", lista[i].data_nascimento.dia, lista[i].data_nascimento.mes, lista[i].data_nascimento.ano);
			printf("CPF: %s\n", lista[i].cpf);
		}
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

int validarCPF(char string[TAM_CPF]){
	char cpf[11];
	strcpy(cpf, string);
    removerChar(cpf, TAM_CPF, '-');
    removerChar(cpf, TAM_CPF, '.');
    
    int i, j, continua = 1;
    
    for(j = 1; j <= 10; j++)
        if(cpf[j - 1] == cpf[j])
            continua = 0;
        else
            continua = 1;
    
    if(continua == 0)
        return 0;
    
    int soma = 0;
    for(i = 10, j = 0; i >= 2; i--, j++)
        soma += (cpf[j] - '0') * i;
    
    int verificador = (soma * 10) % 11;
    
    if(verificador == 10)
        verificador = 0;
    
    if(verificador != (cpf[9] - '0'))
        return 0;
    
    soma = 0;
    for(i = 11, j = 0; i >= 2; i--, j++)
        soma += (cpf[j] - '0') * i;
    
    verificador = (soma * 10) % 11;
    
    if(verificador == 10)
        verificador = 0;
    
    
    return verificador == (cpf[10] - '0');
}

void removerChar(char string[], int tamanho, char remover){
	int i, j;
	for(i = j = 0; j < tamanho; i++, j++){
		if(string[j] == remover)
			j++;
		string[i] = string[j];
	}
	string[i + 1] = '\0';
}

int validarData(char strData[TAM_DATA], Data* data){
	int tamanhoCompactado = 8;
	char nascimento[TAM_DATA];
	strcpy(nascimento, strData);
	removerChar(nascimento, TAM_DATA, '/');
	if(strlen(nascimento) != tamanhoCompactado)
		return 0;

	int i, valido = 1;
	for(i = 0; i < tamanhoCompactado && valido == 1; i++)
		if(nascimento[i] < 48 || nascimento[i] > 57)
			valido = 0;
	
	if(valido == 0)
		return valido;

	int dia, mes, ano;
	dia = ((nascimento[0] - '0') * 10) + (nascimento[1] - '0');
	mes = ((nascimento[2] - '0') * 10) + (nascimento[3] - '0');
	if(mes < 1 || mes > 12)
		return 0;
	
	ano = ((nascimento[4] - '0') * 1000) + ((nascimento[5] - '0') * 100) + ((nascimento[6] - '0') * 10) + (nascimento[7] - '0');
	if(ano < 1900 || ano > anoAtual())
		return 0;

	if (((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) ||
		(dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))) ||
		((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) ||
		((dia >= 1 && dia <= 28) && (mes == 2))){

		data->dia = dia;
		data->mes = mes;
		data->ano = ano;

		return 1;
	}

	return 0;
}

int anoAtual(){
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    return tm.tm_year + 1900;
}
