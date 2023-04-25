# Multiplicaçao de matrizes de forma sequencial e paralela
	Projeto da primeira unidade da disciplina de sistemas operacionais 2023.1 
	com intuito de multiplicar matrizes usando processos e threads.
## Alunos: Jamerson Lucas da Silva e Jose Lucio da Silva Junior

## Como executar:
	-abra o terminal linux e entre na pasta do projeto
	-sequencial:
		-digite o comando: gcc matrizSequencial.c -o sequencial
		-aperte enter
		-digite: ./sequencial linha_1 coluna_1 linha_2 coluna_2
		-linha_1 e coluna_1 sao os tamanhos que voce deve escolher para a matriz 1
		-linha_2 e coluna_2 sao os tamanhos que voce deve escolher para a matriz 2
		-a saida do programa eh o tempo que levou para multiplicar a matriz
	-processos:
		-digite o comando: gcc matrizProcessos.c -o processos
		-aperte enter
		-digite: ./processos linha_1 coluna_1 linha_2 coluna_2 valor_P
		-linha_1 e coluna_1 sao os tamanhos que voce deve escolher para a matriz 1
		-linha_2 e coluna_2 sao os tamanhos que voce deve escolher para a matriz 2
		-valor_P se refere ao numero de processos que voce deseja criar para o programa
		-a saida do programa eh o tempo que levou para multiplicar a matriz
	-threads:
		-digite o comando: gcc matrizThreads.c -o threads -pthread
		-aperte enter
		-digite: ./threads linha_1 coluna_1 linha_2 coluna_2 valor_P
		-linha_1 e coluna_1 sao os tamanhos que voce deve escolher para a matriz 1
		-linha_2 e coluna_2 sao os tamanhos que voce deve escolher para a matriz 2
		-valor_P se refere ao numero de processos que voce deseja criar para o programa
		-a saida do programa eh o tempo que levou para multiplicar a matriz
