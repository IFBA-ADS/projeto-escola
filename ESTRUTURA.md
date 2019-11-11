
# ESTRUTURA DO PROGRAMA

O programa fará basicamente 2 coisas: cadastrar e gerar relatórios. Acredito que apenas esses 2 arquivos (3 se contarmos com o programa gerado) já seriam suficientes para dar conta do trabalho.

Vou tentar descrever quais e funções acho que precisaremos.

## CADASTRO
1. **ALUNOS** 
*Struct*: Matrícula, Nome, Sexo, Data Nascimento, CPF
	- 1ª função: cadastro pessoal. Recebe 6 parâmetros: o tipo da pessoa e seus 5 dados básicos; ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)

2. **PROFESSORES** 
*Struct*: Matrícula, Nome, Sexo, Data Nascimento, CPF
	- 1ª função: cadastro pessoal - mesma função anterior; ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)

3. **DISCIPLINAS**
*Struct*: Nome, Código, Semestre, Professor
	- 2ª função: cadastro de disciplina. Recebe esses 4 parâmetros acima; ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
	
	- 3ª função: matrícula (Inserir/Excluir aluno). Recebe 3 parâmetros: Nome do aluno, nome da disciplina, e se vamos inserir ou excluir ele;
  
## RELATÓRIOS
- 4ª função: listagem de pessoal por nome. Recebe 2 parâmetros: o tipo da pessoa e o sexo *[parâmetro opcional]* (permitindo a listagem de ambos os sexos); ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
	#### Atende aos relatórios
		Listar Alunos ordenados por Nome
		Listar Professores ordenados por Nome
		Listar Alunos por sexo (Masculino/Feminino)
		Listar Professores por sexo (Masculino/Feminino)

- 5ª função: listagem de pessoal por nascimento. Recebe apenas 1 parâmetro: tipo de pesssoa;
	#### Atende aos relatórios
		Listar Alunos ordenados por data de nascimento
		Listar Professores ordenados por data de nascimento

- 6ª função: listagem de disciplinas. Recebe apenas 1 parâmetro: o nome da disciplina; ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
	#### Atende aos relatórios 
		Listar Disciplinas (dados da disciplina sem os alunos)

- 7ª função: Listagem de matriculados. Recebe apenas 1 parâmetro: nome da disciplina;
	#### Atende aos relatórios
		Listar uma disciplina (dados da disciplina e os alunos matriculados)

- 8ª função: aniversariantes do mês. Não recebe parâmetros. Usa alguma função em C para pegar a data que estamos e verifica com o cadastro); ![#ff9600](https://placehold.it/15/ff9600/000000?text=+)
	#### Atende aos relatórios 
		Aniversariantes do mês

- 9ª função: busca. Recebe 2 parâmetros: string de busca e tipo de pesssoa; ![#c5f015](https://placehold.it/15/c5f015/000000?text=+)
	#### Atende aos relatórios
		Pesquisar aluno por nome (min. 3 letras)
		Pesquisar professor por nome (min. 3 letras)

##### Observações do professor:
	- Por Cadastro entenda Incluir, excluir, atualizar
	- Valide todos os campos necessários (ex. Data nascimento, CPF)

##### Legenda
- ![#c5f015](https://placehold.it/15/c5f015/000000?text=+) = `Feito`
- ![#ff9600](https://placehold.it/15/ff9600/000000?text=+) = `Fazendo`
