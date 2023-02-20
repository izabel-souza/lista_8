#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define X 3
#define Y 3

typedef int Matriz[X][Y];

void atribuicao_matriz(Matriz matriz);
void somatorio(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_somatorio);
void impressao(Matriz matriz);

int main (void) {

    Matriz matriz_um, matriz_dois, matriz_somatorio;
    atribuicao_matriz(matriz_um);
    atribuicao_matriz(matriz_dois);

    somatorio(matriz_um, matriz_dois, matriz_somatorio);

    printf("Matriz um: ");
    impressao(matriz_um);
    printf("Matriz dois: \n");
    impressao(matriz_dois);
    printf("Matriz somatorio: \n");
    impressao(matriz_somatorio);

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

void somatorio(Matriz matriz_um, Matriz matriz_dois, Matriz matriz_somatorio) {

    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            matriz_somatorio[i][j] = matriz_um[i][j] + matriz_dois[i][j];
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