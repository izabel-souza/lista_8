#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 3
#define Y 3

typedef int Matriz[X][Y];

void atribuicao_matriz(Matriz matriz);
void somatorio(Matriz matriz, int *somatorio_linhas);
int retorno(int *somatorio_linhas);
void impressao(Matriz matriz);

int main (void) {

    Matriz matriz;
    atribuicao_matriz(matriz);
    
    int somatorio_linhas[X];
    somatorio(matriz, somatorio_linhas);

    impressao(matriz);

    int resultado = retorno(somatorio_linhas);
    if(resultado == 0) { printf("O somatorio das linhas da matriz tem mesmo valor"); }
    else { printf("O somatorio das linhas tem valor diferente"); }
  
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

void somatorio(Matriz matriz, int *somatorio_linhas) {

    int soma_valores = 0;

    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            soma_valores += matriz[i][j];
        }
        somatorio_linhas[i] = soma_valores;
        soma_valores = 0;
    }

}

int retorno(int *somatorio_linhas) {
    for(int i = 0; i < (X-1); i++) {
        if(somatorio_linhas[i+1] == somatorio_linhas[i]) {
            return 0;
        }
        else {
            return -1;
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
}