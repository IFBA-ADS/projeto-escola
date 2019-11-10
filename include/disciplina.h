#ifndef DISCIPLINA_H
#define DISCIPLINA_H

/* function headers here */


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

#endif
