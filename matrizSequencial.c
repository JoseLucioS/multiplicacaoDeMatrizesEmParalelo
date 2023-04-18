#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Esse programa realiza a multiplicacao das matrizes de forma sequencial*/

void alocarMatriz(int **matriz, int tam_linhas, int tam_colunas){
	matriz = (int**) malloc(tam_linhas * sizeof(int*));
	for(int i = 0; i < tam_linhas; i++){
		matriz[i] = (int*) malloc(tam_colunas * sizeof(int));
		printf("alocando... %d\n", i);
	}
}

void preencherMatriz(int **matriz, int tam_linhas, int tam_colunas){
	for(int i = 0; i < tam_linhas; i++){
		for(int j = 0; j < tam_colunas; j++){
			matriz[i][j] = rand() % 100;
		}
	}
}

void imprimirMatriz(int **matriz, int tam_linhas, int tam_colunas){
	for(int i = 0; i < tam_linhas; i++){
		for(int j = 0; j < tam_colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void liberarMatriz(int **matriz, int tam_linhas, int tam_colunas){
	for (int i = 0; i < tam_linhas; i++)
	{
		free(matriz[i]);
	}
	free(matriz);
}

int main(int argc, char const *argv[])
{
	//recebendo as dimensoes das matrizes atraves da linha de comando
	int linhas_matriz_1 = atoi(argv[1]);
	int colunas_matriz_1 = atoi(argv[2]);

	int linhas_matriz_2 = atoi(argv[3]);
	int colunas_matriz_2 = atoi(argv[4]);

	int** matriz_um; 
	int** matriz_dois;

	//verificar se a multiplicacao entre as matrizes eh permitida
	//se nao for, mostrar uma mensagem e encerrar o programa
	if(colunas_matriz_1 != linhas_matriz_2){
		printf("Impossivel multiplicar essas matrizes\n");
		exit(0);
	} else {
		//alocar espaco para as matrizes
		alocarMatriz(matriz_um, linhas_matriz_1, colunas_matriz_1);
		alocarMatriz(matriz_dois, linhas_matriz_2, colunas_matriz_2);

		//preencher cada uma das matrizes usando numeros aleatorios
		//preencherMatriz(matriz_um, linhas_matriz_1, colunas_matriz_1);
		//preencherMatriz(matriz_dois, linhas_matriz_2, colunas_matriz_2);

		//testando
		/*printf("Matriz um...\n");
		imprimirMatriz(matriz_um, linhas_matriz_1, colunas_matriz_1);
		printf("\n\n");
		printf("Matriz dois...\n");
		imprimirMatriz(matriz_dois, linhas_matriz_2, colunas_matriz_2); */

		//realizar a multiplicacao
		//clock_t inicio = clock();

		//clock_t fim = clock();
		//double tempo_gasto = (double) (fim - inicio) / CLOCKS_PER_SEC;

		//liberar a memoria alocada para as matrizes
		//liberarMatriz(matriz_um, linhas_matriz_1, colunas_matriz_1);
		//liberarMatriz(matriz_dois, linhas_matriz_2, colunas_matriz_2);

		//imprimir o tempo que se passou para a multiplicacao
	
	}
	
	return 0;
}