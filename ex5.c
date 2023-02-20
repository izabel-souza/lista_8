#include <stdio.h> 
#include <stdlib.h>
#define X 3
#define Y 3

typedef int Matriz[X][Y];

void atribuicao_matriz(Matriz matriz);
void soma_matrizes(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_soma);
void soma_diagonais(Matriz matriz, int *soma);
void multiplicacao_matrizes(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_multiplicacao);
void impressao(Matriz matriz);

int main (void) {

    Matriz matriz_um, matriz_dois, matriz_soma, matriz_multiplicacao;

    int somatorio_diagonais_um = 0, somatorio_diagonais_dois = 0;

    int *p = &somatorio_diagonais_um;
    int *q = &somatorio_diagonais_dois;

    atribuicao_matriz(matriz_um);
    atribuicao_matriz(matriz_dois);
    soma_matrizes(matriz_um, matriz_dois, matriz_soma);
    soma_diagonais(matriz_um, p);
    soma_diagonais(matriz_dois, q);
    multiplicacao_matrizes(matriz_um, matriz_dois, matriz_multiplicacao);

    printf("Matriz um: \n");
    impressao(matriz_um);
    printf("Matriz dois: \n");
    impressao(matriz_dois);
    printf("Matriz somatorio: \n");
    impressao(matriz_soma);
    printf("Matriz multiplicacao: \n");
    impressao(matriz_multiplicacao);

    printf("Soma das diagonais da matriz um: %d\n", somatorio_diagonais_um);
    printf("Soma das diagonais da matriz dois: %d\n", somatorio_diagonais_dois);

    return 0;
}

void atribuicao_matriz(Matriz matriz) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            printf("Informe o valor [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void soma_matrizes(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_soma) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            matriz_soma[i][j] = (matriz_um[i][j] + matriz_dois[i][j]);
        }
    }
}

void soma_diagonais(Matriz matriz, int *soma) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            if(i == j) {
                *soma += matriz[i][j];
            }
        }
    }
}

void multiplicacao_matrizes(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_multiplicacao) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            matriz_multiplicacao[i][j] = (matriz_um[i][j] * matriz_dois[i][j]);
        }
    }
}

void impressao(Matriz matriz) {
    for(int i = 0; i < X; i++) {
        printf("\n");
        for(int j = 0; j < Y; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}