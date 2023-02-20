#include <stdio.h> 
#include <stdlib.h>
#define X 5
#define Y 5

typedef int Tabela[X][Y];

void distancia_cidades(Tabela tabela, int linha, int coluna, int *distancia);
void impressao(Tabela tabela);
int *inicializacao_atribuicao_vetor(int n);
int calculo_percusso(Tabela tabela, int *vetor, int n);

int main (void) {

    Tabela tabela = {{00, 15, 30, 05, 12}, {15, 00, 10, 17, 28}, {30, 10, 00, 03, 11}, {05, 17, 03, 00, 80}, {12, 28, 11, 80, 00}};

    int linha, coluna, distancia = 0;

    do {
        printf("Informe as cidades cuja distancia quer saber: ");
        scanf("%d %d", &linha, &coluna);

        if(linha == 0 && coluna == 0) {
            break;
        }

        distancia_cidades(tabela, linha, coluna, &distancia);
        printf("Distancia entre as cidades %d e %d = %d\n", linha, coluna, distancia);
        distancia = 0;
    } while(linha != 0 && coluna != 0);
    
    printf("\nTabela de cidades: \n");
    impressao(tabela);
    printf("\n"); 

    int quant_cidade;
    printf("Informe a quantidade de cidades que estarao no percusso: ");
    scanf("%d", &quant_cidade);
    int *vetor = inicializacao_atribuicao_vetor(quant_cidade);

    int tota_percusso = calculo_percusso(tabela, vetor, quant_cidade); 
    printf("Distancia total do percusso entre as cidades escolhidas = %d km", tota_percusso);

    return 0;
}

void distancia_cidades(Tabela tabela, int linha, int coluna, int *distancia) {
    for(int j = 0; j < coluna; j++) {
        (*distancia) += tabela[linha-1][j];
    }
}

void impressao(Tabela tabela) {

    for(int i = 0; i < X; i++) {
        printf("\n");
        for(int j = i; j < Y; j++) {
            printf("%d ", tabela[i][j]);
        }
    }
    printf("\n");
}

int *inicializacao_atribuicao_vetor(int n) {

    int *vet = (int *) malloc(n * sizeof(int));
    if(vet == NULL) { printf("Falta de memoria"); exit(1); }

    for(int i = 0; i < n; i++) {
        printf("Informe a cidade %d do percusso: ", i+1);
        scanf("%d", &vet[i]);
    }

    return vet;
}

int calculo_percusso(Tabela tabela, int *vetor, int n) {

    int distancia = 0;
    for(int i = 1; i < n; i++) {
        distancia += (tabela[vetor[i-1]][vetor[i]]);
    }

    return distancia;
}