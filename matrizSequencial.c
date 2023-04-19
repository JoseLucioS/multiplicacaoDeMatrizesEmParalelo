#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Esse programa realiza a multiplicacao das matrizes de forma sequencial*/

void preencherMatriz(int tam_linhas, int tam_colunas, int matriz[tam_linhas][tam_colunas]){
	for(int i = 0; i < tam_linhas; i++){
		for(int j = 0; j < tam_colunas; j++){
			matriz[i][j] = rand() % 100;
		}
	}
}

void imprimirMatriz(int tam_linhas, int tam_colunas, int matriz[tam_linhas][tam_colunas]){
	for(int i = 0; i < tam_linhas; i++){
		for(int j = 0; j < tam_colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	//recebendo as dimensoes das matrizes atraves da linha de comando
	int linhas_matriz_1 = atoi(argv[1]);
	int colunas_matriz_1 = atoi(argv[2]);

	int linhas_matriz_2 = atoi(argv[3]);
	int colunas_matriz_2 = atoi(argv[4]);

	int matriz_um[linhas_matriz_1][colunas_matriz_1]; 
	int matriz_dois[linhas_matriz_2][colunas_matriz_2];

	//verificar se a multiplicacao entre as matrizes eh permitida
	//se nao for, mostrar uma mensagem e encerrar o programa
	if(colunas_matriz_1 != linhas_matriz_2){
		printf("Impossivel multiplicar essas matrizes\n");
		exit(0);
	} else {

		//preencher cada uma das matrizes usando numeros aleatorios
		preencherMatriz(linhas_matriz_1, colunas_matriz_1, matriz_um);
		preencherMatriz(linhas_matriz_2, colunas_matriz_2, matriz_dois);

		//testando
		printf("Matriz um...\n");
		imprimirMatriz(linhas_matriz_1, colunas_matriz_1, matriz_um);
		printf("\n\n");
		printf("Matriz dois...\n");
		imprimirMatriz(linhas_matriz_2, colunas_matriz_2, matriz_dois);

		//realizar a multiplicacao
		//clock_t inicio = clock();

		//clock_t fim = clock();
		//double tempo_gasto = (double) (fim - inicio) / CLOCKS_PER_SEC;

		//imprimir o tempo que se passou para a multiplicacao
	
	}
	
	return 0;
}