# Projeto Escola

Repositório do trabalho desenvolvido para a disciplina INF029 - Laboratório de Programação

# O que faz

O projeto é um protótipo de um sistema para uma escola o qual possibilitará gerenciar alunos, professores e disciplinas.

### Aluno:

**Funcionalidades básicas:**
- Cadastrar;
- Deletar;
- Editar;
- Consultar (All);

**Relatórios:**
- Listar por sexo (M/F);
- Listar ordenado por nome;
- Listar ordenado por nascimento;
- Pegar alunos aniversariantes do mês;
- Pesquisar aluno por nome (min. 3 letras);
------------------------------------------------------------
### Professor:

**Funcionalidades básicas:**
- Cadastrar;
- Deletar;
- Editar;
- Consultar (All);

**Relatórios:**
- Listar por sexo (M/F);
- Listar ordenado por nome;
- Listar ordenado por nascimento;
- Pegar professores aniversariantes do mês;
- Pesquisar professor por nome (min. 3 letras);
------------------------------------------------------------
### Disciplina:

**Funcionalidades básicas:**
- Cadastrar;
- Deletar;
- Editar;
- Consultar (All);

**Relatórios:**
- Inserir aluno na disciplina;
- Remover aluno da disciplina;
- Consultar uma disciplina (listando os alunos);

# Organização

├───README.md<br/>
├───programa.c<br/>
├───db /\* para arquivos de dados usados na aplicação \*/<br/>
├───include /\* *para arquivos de cabeçalho (.h)* \*/<br/>
├───obj /\* *para arquivos objeto (.o) resultantes de compilação* \*/<br/>
└───src /\* *para arquivos de recurso (bibliotecas, etc)*  \*/<br/>

### Compilar e executar
#### Windows
	Para compilar e executar, caso esteja usando o MinGW, basta processar o comando "gcc programa.c -o obj/programa", para executar "programa" no terminal.

#### Linux
	Para compilar execute o comando "gcc programa.c -o obj/programa", para executar "./programa".