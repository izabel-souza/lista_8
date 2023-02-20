#include <stdio.h>
#include <stdlib.h>
#define X 3
#define Y 3

typedef int Matriz[X][Y];

void atribuicao_matriz(Matriz matriz);
void atribuicao_matriz_transposta(Matriz matriz_transposta, Matriz matriz);
int avaliacao_simetria(Matriz matriz_transposta, Matriz matriz);


int main (void) {

    Matriz matriz, matriz_transposta;
    atribuicao_matriz(matriz);
    atribuicao_matriz_transposta(matriz_transposta, matriz);

    int resultado = avaliacao_simetria(matriz_transposta, matriz);

    if(resultado == 0) { printf("A matriz original e sua transposta sao simetricas"); }
    else { printf("A matriz original e sua transposta nao sao simetricas"); }

    return 0;
}

void atribuicao_matriz(Matriz matriz) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            printf("Informe o valor [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

void atribuicao_matriz_transposta(Matriz matriz_transposta, Matriz matriz) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            matriz_transposta[i][j] = matriz[j][i];
        }
    }
}

int avaliacao_simetria(Matriz matriz_transposta, Matriz matriz) {
     for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            if(matriz[i][j] != matriz_transposta[j][i]) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}
