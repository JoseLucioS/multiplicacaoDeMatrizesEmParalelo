#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*Esse programa realiza a multiplicacao das matrizes atraves de processos*/

//variaveis globais
int LINHAS_MATRIZ_UM;
int COLUNAS_MATRIZ_UM;
int LINHAS_MATRIZ_DOIS;
int COLUNAS_MATRIZ_DOIS;

void multiplicarMatrizes(int** matriz_um, int** matriz_dois, int** matriz_resultado, int inicio, int fim) {
    // Multiplica as matrizes
    for(int i = inicio; i < fim; i++) {
        for(int j = 0; j < COLUNAS_MATRIZ_DOIS; j++) {
            for(int k = 0; k < COLUNAS_MATRIZ_UM; k++) {
                matriz_resultado[i][j] += matriz_um[i][k] * matriz_dois[k][j];
            }
        }
    }
}

int** alocarMatriz(int tam_linhas, int tam_colunas){
	int **matriz = (int**) malloc(tam_linhas * sizeof(int*));
    for (int i = 0; i < tam_linhas; i++) {
        matriz[i] = (int*) malloc(tam_colunas * sizeof(int));
    }
    return matriz;
}

void desalocarMatriz(int **matriz, int tam_linhas){
	for (int i = 0; i < tam_linhas; i++){
    	free(matriz[i]);
    }
    free(matriz);
}

int main(int argc, char const *argv[])
{
	int status;
	pid_t pid;

	//Recebendo o tamanho das matrizes pela linha de comando
	LINHAS_MATRIZ_UM = atoi(argv[1]);
	COLUNAS_MATRIZ_UM = atoi(argv[2]);
	LINHAS_MATRIZ_DOIS = atoi(argv[3]);
	COLUNAS_MATRIZ_DOIS = atoi(argv[4]);
	int P = atoi(argv[5]); //numero de processos para multiplicar as matrizes

	//Declarando as matrizes
    int** matriz_um;
    int** matriz_dois;
    int** matriz_resultado;

    //Alocando dinamicamente as matrizes
    matriz_um = alocarMatriz(LINHAS_MATRIZ_UM, COLUNAS_MATRIZ_UM);
    matriz_dois = alocarMatriz(LINHAS_MATRIZ_DOIS, COLUNAS_MATRIZ_DOIS);
    matriz_resultado = alocarMatriz(LINHAS_MATRIZ_UM, COLUNAS_MATRIZ_DOIS);

    //Inicializando as matrizes com números inteiros aleatorios
  	srand(time(NULL));
    for(int i = 0; i < LINHAS_MATRIZ_UM; i++) {
        for(int j = 0; j < COLUNAS_MATRIZ_UM; j++) {
            matriz_um[i][j] = 1 + rand() % 10;
        }
    }

    for(int i = 0; i < LINHAS_MATRIZ_DOIS; i++) {
        for(int j = 0; j < COLUNAS_MATRIZ_DOIS; j++) {
            matriz_dois[i][j] = 1 + rand() % 10;
        }
    }

    //Inicializando a matriz resultado com zeros
    for(int i = 0; i < LINHAS_MATRIZ_UM; i++) {
        for(int j = 0; j < COLUNAS_MATRIZ_DOIS; j++) {
            matriz_resultado[i][j] = 0;
        }
    }

    //Iniciando a criacao dos filhos e inicio da marcaçao de tempo
    clock_t inicio = clock();
    int pid_pai_inicio = getpid();

    for (int i = 0; i < P; i++){
    	pid = fork();

    	if(pid < 0){
    		printf("Erro na criaçao do filho!\n");
    	} else if(pid == 0){
    		
    		int inicio = i * (LINHAS_MATRIZ_UM / P);
    		int fim = (i + 1) * (LINHAS_MATRIZ_UM / P);

    		multiplicarMatrizes(matriz_um, matriz_dois, matriz_resultado, inicio, fim);
    	}
    }

    //Aguardando todos os processos filhos encerrarem
    for (int i = 0; i < P; i++){
    	wait(NULL);
    }

    if(pid_pai_inicio == getpid()){
    	clock_t fim = clock();
    	double tempo_gasto = (double) (fim - inicio) / CLOCKS_PER_SEC * 1000; //medindo em milissegundos
    	printf("Tempo gasto: %2.f segundos\n", tempo_gasto);
    }

    //Liberando a memoria alocada para cada matriz
    desalocarMatriz(matriz_um, LINHAS_MATRIZ_UM);
    desalocarMatriz(matriz_dois, LINHAS_MATRIZ_DOIS);
    desalocarMatriz(matriz_resultado, LINHAS_MATRIZ_UM);

	return 0;
}