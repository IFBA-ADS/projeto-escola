#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../include/util.h"

int validarCPF(char string[], int tamCPF){
	if(tamCPF != TAM_CPF && tamCPF != TAM_CPF_COMPACT)
		return 0;

	char cpf[TAM_CPF_COMPACT];

	if(tamCPF == TAM_CPF){
		char stringpy[tamCPF];
		strcpy(stringpy, string);
	    removerChar(stringpy, TAM_CPF, '-');
	    removerChar(stringpy, TAM_CPF, '.');
		strcpy(cpf, stringpy);
	} else{
		strcpy(cpf, string);
	}
    
    int i, j, continua = 1;
    
    for(j = 1; j < TAM_CPF_COMPACT; j++)
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
	string[i] = '\0';
}

int validarData(char strData[], int tamanho, Data* data){
	if(tamanho != TAM_DATA && tamanho != TAM_DATA_COMPACT)
		return 0;

	char nascimento[TAM_DATA_COMPACT];

	if(tamanho == TAM_DATA){
		char stringpy[TAM_DATA];
		strcpy(stringpy, strData);
		removerChar(stringpy, TAM_DATA, '/');
		strcpy(nascimento, stringpy);
	} else{
		strcpy(nascimento, strData);
	}

	if(strlen(nascimento) != TAM_DATA_COMPACT)
		return 0;

	int i, valido = 1;
	for(i = 0; i < TAM_DATA_COMPACT && valido == 1; i++)
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
	Data dataA = dataAtual();
	if(ano < 1900 || ano > dataA.ano)
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

Data dataAtual(){
	Data data;
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    data.dia = tm.tm_mday;
    data.mes = tm.tm_mon + 1;
    data.ano = tm.tm_year + 1900;
    return data;
}

void removerQuebraDeLinha(char string[], int tamanho){
	if(string[tamanho - 1] == '\n')
		string[tamanho - 1] = '\0';
}

void cfgets(char* string, int tamanho, FILE* fluxo){
	fgets(string, tamanho + 1, fluxo);
	removerQuebraDeLinha(string, strlen(string));
	if(strlen(string) == tamanho)
		limpaBuffer();
}

void limpaBuffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int compararStrings(const char* string, const char* substring){
    if (!substring[0])
    	return 0;
    int i, j, encontrado;
    for (i = 0; string[i]; i++){
        encontrado = 1;
        for (j = 0; substring[j] && encontrado; j++){
            if (!string[i + j])
            	return 0;
            if (tolower((unsigned char)substring[j]) !=  tolower((unsigned char)string[i + j]))
                encontrado = 0;
        }
        if (encontrado)
        	return 1;
    }
    return 0;
}

void limparTela(){
	#ifdef WIN32
		system ("cls");
	#else
		printf("\e[H\e[2J");
	#endif
}

int compararDatas(Data data1, Data data2)
{
	int maior = 0;
	maior = data1.ano > data2.ano ? 1 : data2.ano > data1.ano ? 2 : 0;
	if(maior != 0)
		return maior;
	maior = data1.mes > data2.mes ? 1 : data2.mes > data1.mes ? 2 : 0;
	if(maior != 0)
		return maior;
	maior = data1.dia > data2.dia ? 1 : data2.dia > data1.dia ? 2 : 0;
	return maior;
}
