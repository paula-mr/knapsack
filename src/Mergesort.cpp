#include "Mergesort.h"

void ordena(int ilhas[][2], int esquerda, int direita);
void merge(int ilhas[][2], int esquerda, int meio, int direita);
float calcularCustoBeneficio(int custoBeneficio[2]);

void ordenar(int ilhas[][2], int n) {
    ordena(ilhas, 0, n-1);
}

void ordena(int ilhas[][2], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda+(direita-esquerda)/2;

        ordena(ilhas, esquerda, meio);
        ordena(ilhas, meio+1, direita);

        merge(ilhas, esquerda, meio, direita);
    }
}

void merge(int ilhas[][2], int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita =  direita - meio;

    int arrayEsquerda[tamanhoEsquerda][2], arrayDireita[tamanhoDireita][2];

    for (i = 0; i < tamanhoEsquerda; i++) {
        arrayEsquerda[i][0] = ilhas[esquerda + i][0];
        arrayEsquerda[i][1] = ilhas[esquerda + i][1];
    }

    for (j = 0; j < tamanhoDireita; j++) {
        arrayDireita[j][0] = ilhas[meio + 1+ j][0];
        arrayDireita[j][1] = ilhas[meio + 1+ j][1];
    }

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = esquerda; // Initial index of merged subarray

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (calcularCustoBeneficio(arrayEsquerda[i]) <= calcularCustoBeneficio(arrayDireita[j])) {
            ilhas[k][0] = arrayEsquerda[i][0];
            ilhas[k][1] = arrayEsquerda[i][1];
            i++;
        }
        else {
            ilhas[k][0] = arrayDireita[j][0];
            ilhas[k][1] = arrayDireita[j][1];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        ilhas[k][0] = arrayEsquerda[i][0];
        ilhas[k][1] = arrayEsquerda[i][1];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        ilhas[k][0] = arrayDireita[j][0];
        ilhas[k][1] = arrayDireita[j][1];
        j++;
        k++;
    }

}

float calcularCustoBeneficio(int custoBeneficio[2]) {
    return custoBeneficio[0]/custoBeneficio[1];
}
