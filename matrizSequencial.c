#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Esse programa realiza a multiplicacao das matrizes de forma sequencial*/

void preencherMatriz(int** matriz, int tam_linhas, int tam_colunas){
	for(int i = 0; i < tam_linhas; i++){
		for(int j = 0; j < tam_colunas; j++){
			matriz[i][j] = rand() % 100
		}
	}
}

int main(int argc, char const *argv[])
{
	//recebendo as dimensoes das matrizes atraves da linha de comando
	int linhas_matriz_1 = atoi(argv[1]);
	int colunas_matriz_1 = atoi(argv[2]);

	int linhas_matriz_2 = atoi(argv[3]);
	int colunas_matriz_2 = atoi(argv[4]);

	int** matriz_um, matriz_dois;

	//verificar se a multiplicacao entre as matrizes eh permitida
	//se nao for, mostrar uma mensagem e encerrar o programa
	if(colunas_matriz_1 != linhas_matriz_2){
		printf("Impossivel multiplicar essas matrizes\n");
	} else {
		//alocar espaco para as matrizes

		//alocando para a matriz um
		matriz_um = (int**) malloc(linhas_matriz_1 * sizeof(int*));
		for(int i = 0; i < linhas_matriz_1; i++){
			matriz_um[i] = (int*) malloc(colunas_matriz_1 * sizeof(int));
		}

		//alocando para a matriz dois
		matriz_dois = (int**) malloc(linhas_matriz_2 * sizeof(int*));
		for(int i = 0; i < linhas_matriz_2; i++){
			matriz_dois[i] = (int*) malloc(colunas_matriz_2 * sizeof(int));
		}
	}
	//preencher cada uma das matrizes usando numeros aleatorios

	//realizar a multiplicacao

	//liberar a memoria alocada para as matrizes
	

	//imprimir o tempo que se passou para a multiplicacao

	return 0;
}