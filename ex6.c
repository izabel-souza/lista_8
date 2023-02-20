#include <stdio.h>
#include <stdlib.h>
#define X 8
#define Y 8

void somatorio_pecas_especificas(int tabuleiro[X][Y], int *bp, int *au);
void somatorio_pecas(int tabuleiro[X][Y], int *a, int *p, int *c, int *t, int *b, int *k, int *q);

int main (void) {

    int tabuleiro[X][Y] = {{1,3,0,5,4,0,2,1}, {1,0,1,0,0,1,0,0}, {0,0,0,0,1,0,6,0}, {1,0,0,1,1,0,0,1}, {0,1,0,4,0,0,1,0}, {0,0,3,1,0,0,1,1}, {1,0,6,6,0,0,1,0}, {1,0,5,0,1,1,0,6}};

    int ausencia = 0, peoes = 0, cavalos = 0, torres = 0, bispos = 0, reis = 0, rainhas = 0, bp = 0, au = 0;

    somatorio_pecas_especificas(tabuleiro, &bp, &au);
    printf("Somatorio de bispos e peoes pelo tabuleiro: %d\nSomatorio da ausencia de pecas = %d\n", bp, au);

    somatorio_pecas(tabuleiro, &ausencia, &peoes, &cavalos, &torres, &bispos, &reis, &rainhas);
    printf("Somatorio das pecas do tabuleiro:\nAusencia = %d\nPeoes = %d\nCavalos = %d\nTorres = %d\nBispos = %d\nReis = %d\nRainhas = %d", ausencia, peoes, cavalos, torres, bispos, reis, rainhas);

    return 0;
}

void somatorio_pecas_especificas(int tabuleiro[X][Y], int *bp, int *au) {

    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            switch(tabuleiro[i][j]) {
                case 0: (*au)++; break;
                case 1: (*bp)++; break;
                case 4: (*bp)++; break;
            }
        }
    }

}

void somatorio_pecas(int tabuleiro[X][Y], int *a, int *p, int *c, int *t, int *b, int *k, int *q) {
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            switch(tabuleiro[i][j]) {
                case 0: (*a)++; break;
                case 1: (*p)++; break;
                case 2: (*c)++; break;
                case 3: (*t)++; break;
                case 4: (*b)++; break;
                case 5: (*k)++; break;
                case 6: (*q)++; break;
            }
        }
    }
}