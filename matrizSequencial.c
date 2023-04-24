#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarMatrizes(int** matriz_um, int** matriz_dois, int** matriz_resultado, int linhas_matriz_um, int colunas_matriz_dois, int colunas_matriz_um) {
    // Multiplica as matrizes
    for(int i = 0; i < linhas_matriz_um; i++) {
        for(int j = 0; j < colunas_matriz_dois; j++) {
            for(int k = 0; k < colunas_matriz_um; k++) {
                matriz_resultado[i][j] += matriz_um[i][k] * matriz_dois[k][j];
            }
        }
    }
}

int main(int argc, char const *argv[]) {
	//Recebendo o tamanho das matrizes pela linha de comando
	int linhas_matriz_um = atoi(argv[1]);
	int colunas_matriz_um = atoi(argv[2]);
	int linhas_matriz_dois = atoi(argv[3]);
	int colunas_matriz_dois = atoi(argv[4]);

	//Declarando as matrizes
    int** matriz_um;
    int** matriz_dois;
    int** matriz_resultado;

    //Alocando dinamicamente as matrizes
    matriz_um = (int**) malloc(linhas_matriz_um * sizeof(int*));
    for (int i = 0; i < linhas_matriz_um; i++) {
        matriz_um[i] = (int*) malloc(colunas_matriz_um * sizeof(int));
    }

    matriz_dois = (int**) malloc(linhas_matriz_dois * sizeof(int*));
    for (int i = 0; i < linhas_matriz_dois; i++) {
        matriz_dois[i] = (int*) malloc(colunas_matriz_dois * sizeof(int));
    }

    matriz_resultado = (int**) malloc(linhas_matriz_um * sizeof(int*));
    for (int i = 0; i < linhas_matriz_um; i++) {
        matriz_resultado[i] = (int*) malloc(colunas_matriz_dois * sizeof(int));
    }

    //Inicializando as matrizes com números inteiros aleatorios
  	srand(time(NULL));
    for(int i = 0; i < linhas_matriz_um; i++) {
        for(int j = 0; j < colunas_matriz_um; j++) {
            matriz_um[i][j] = 1 + rand() % 10;
        }
    }

    for(int i = 0; i < linhas_matriz_dois; i++) {
        for(int j = 0; j < colunas_matriz_dois; j++) {
            matriz_dois[i][j] = 1 + rand() % 10;
        }
    }

    //Inicializando a matriz resultado com zeros
    for(int i = 0; i < linhas_matriz_um; i++) {
        for(int j = 0; j < colunas_matriz_dois; j++) {
            matriz_resultado[i][j] = 0;
        }
    }

    //Multiplicando as matrizes e calculando o tempo gasto
    clock_t inicio = clock();

    multiplicarMatrizes(matriz_um, matriz_dois, matriz_resultado, linhas_matriz_um, colunas_matriz_dois, colunas_matriz_um);
    
    clock_t fim = clock();
    double tempo_gasto = (double) (fim - inicio) / CLOCKS_PER_SEC * 1000; //medindo em milissegundos

    printf("tempo gasto: %2.f ms\n", tempo_gasto);

    //Liberando a memoria alocada para cada matriz
    for (int i = 0; i < linhas_matriz_um; i++){
    	free(matriz_um[i]);
    }
    free(matriz_um);

    for (int i = 0; i < linhas_matriz_dois; i++){
    	free(matriz_dois[i]);
    }
    free(matriz_dois);

    for (int i = 0; i < linhas_matriz_um; i++){
    	free(matriz_resultado[i]);
    }
    free(matriz_resultado);

    return 0;
}
	
