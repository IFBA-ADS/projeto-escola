#ESTRUTURA DO PROGRAMA

O programa fará apenas 2 coisas: cadastrar e gerar relatórios. Acho que apenas esses 2 arquivos (3 se contarmos com o programa gerado) já seriam suficientes para dar conta do trabalho.

Vou tentar descrever quais e funções acho que precisaremos.

## CADASTRO
1. ALUNOS
   *Matrícula, Nome, Sexo, Data Nascimento, CPF (1ª função: cadastro pessoal. Recebe 6 parâmetros: o tipo da pessoa e seus 5 dados básicos)
2. PROFESSORES
   *Matrícula, Nome, Sexo, Data Nascimento, CPF (1ª função: cadastro pessoal - mesma função anterior)
3. DISCIPLINAS
   *Nome, Código, Semestre, Professor (2ª função: cadastro de disciplina. Recebe esses 4 parâmetros ao lado )
   *Inserir/Excluir aluno de uma disciplina (3ª função: matrícula. Recebe 3 parâmetros: Nome do aluno, nome da disciplina, e se vamos inserir ou excluir ele)
  
## RELATÓRIOS
(4ª função: listagem de pessoal por nome. Recebe 2 parâmetros: o tipo da pessoa e o sexo, o sexo seria uma parâmetro opcional, permitindo a listagem de ambos os sexos):
Listar Alunos ordenados por Nome
Listar Professores ordenados por Nome
Listar Alunos por sexo (Masculino/Feminino)
Listar Professores por sexo (Masculino/Feminino)

(5ª função: listagem de pessoal por nascimento. Recebe apenas 1 parâmetro: tipo de pesssoa):
Listar Alunos ordenados por data de nascimento
Listar Professores ordenados por data de nascimento

(6ª função: listagem de disciplinas. Recebe apenas 1 parâmetro: o nome da disciplina)
Listar Disciplinas (dados da disciplina sem os alunos)

(7ª função: Listagem de matriculados. Recebe apenas 1 parâmetro: nome da disciplina)
Listar uma disciplina (dados da disciplina e os alunos matriculados)

(8ª função: aniversariantes do mẽs. Não recebe parâmetros. Usa alguma função em C para pegar a data que estamos e verifica com o cadastro)
Aniversariantes do mês

(9ª função: busca. Recebe apenas 1 parâmetro que é a própria busca)
Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome.

###Observações do professor:
Por Cadastro entenda Incluir, excluir, atualizar
Valide todos os campos necessários (ex. Data nascimento, CPF)
