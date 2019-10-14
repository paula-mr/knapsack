#include "Quicksort.h"

void ordena(int ilhas[][2], int esquerda, int direita);
void particao(int ilhas[][2], int esquerda, int direita, int *i, int *j);

void ordenar(int ilhas[][2], int n) {
    ordena(ilhas, 0, n-1);
}

void ordena(int ilhas[][2], int esquerda, int direita) {
    int i, j;

    particao(ilhas, esquerda, direita, &i, &j);

    if (esquerda < j)
        ordena(ilhas, esquerda, j);

    if (i < direita)
        ordena(ilhas, i, direita);
}

void particao(int ilhas[][2], int esquerda, int direita, int *i, int *j) {
    int pivo;
    *i = esquerda;
    *j = direita;

    //seleciona pivo
    pivo = ilhas[(*i + *j)/2][1];

    do {

        /*percorre o vetor do inicio ate encontrar um elemento
          maior que o pivo */
        while (pivo > ilhas[*i][1]) {
            (*i)++;
        }

        /*percorre o vetor do fim ate encontrar um elemento
          menor que o pivo */
        while (pivo < ilhas[*j][1]) {
            (*j)--;
        }

        //caso i seja menor ou igual a j, troca-se os elementos
        if (*i <= *j) {
            int auxiliar[2];
            auxiliar[0] = ilhas[*i][0];
            auxiliar[1] = ilhas[*i][1];

            ilhas[*i][0] = ilhas[*j][0];
            ilhas[*i][1] = ilhas[*j][1];

            ilhas[*j][0] = auxiliar[0];
            ilhas[*j][1] = auxiliar[1];

            (*i)++;
            (*j)--;
        }


    } while (*i <= *j);

}
