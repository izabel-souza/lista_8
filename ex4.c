#include <stdio.h> <stdlib.h>

int main (void) {

    int aux = 0;
    char nomes[aux];

    while(1) {
        printf("Nome: ");
        scanf(" %79[^\n]%c", nomes[aux]);
        if(nomes[aux] == "fim") {
            break;
        }
        aux++;
    }

    for(int i = 0; i < aux; i++) {
        printf("%s\n", nomes[aux]);
    }

    return 0;
}