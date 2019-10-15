#include "Mergesort.h"

void ordena(int ilhas[][2], int esquerda, int direita);
void merge(int ilhas[][2], int esquerda, int meio, int direita);
float calcularCustoBeneficio(int custoBeneficio[2]);

void ordenar(int ilhas[][2], int n) {
    //inicia funcao de ordenacao por mergesort
    ordena(ilhas, 0, n-1);
}

void ordena(int ilhas[][2], int esquerda, int direita) {
    //caso os apontadores nao tenham se cruzado ou sejam os mesmos
    if (esquerda < direita) {
        int meio = esquerda+(direita-esquerda)/2;

        //ordena metade da esquerda
        ordena(ilhas, esquerda, meio);
        //ordena metade da direita
        ordena(ilhas, meio+1, direita);

        //junta os arrays ordenados
        merge(ilhas, esquerda, meio, direita);
    }
}

void merge(int ilhas[][2], int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita =  direita - meio;

    //cria uma copia para o array da esquerda
    int arrayEsquerda[tamanhoEsquerda][2], arrayDireita[tamanhoDireita][2];
    for (i = 0; i < tamanhoEsquerda; i++) {
        arrayEsquerda[i][0] = ilhas[esquerda + i][0];
        arrayEsquerda[i][1] = ilhas[esquerda + i][1];
    }

    //cria uma copia para o array da direita
    for (j = 0; j < tamanhoDireita; j++) {
        arrayDireita[j][0] = ilhas[meio + 1+ j][0];
        arrayDireita[j][1] = ilhas[meio + 1+ j][1];
    }

    i = 0; // valor inicial do subarray da esquerda
    j = 0; // valor inicial do subarray da direita
    k = esquerda; // valor inicial do subarray mergeado

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        //define qual item possui maior custo beneficio
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

    //copia o array da esquerda ordenado para o array mergeado
    while (i < tamanhoEsquerda) {
        ilhas[k][0] = arrayEsquerda[i][0];
        ilhas[k][1] = arrayEsquerda[i][1];
        i++;
        k++;
    }

    //copia o array da direita ordenado para o array mergeado
    while (j < tamanhoDireita) {
        ilhas[k][0] = arrayDireita[j][0];
        ilhas[k][1] = arrayDireita[j][1];
        j++;
        k++;
    }

}

//calcula o custo beneficio da ilha com base em custo e pontos atribuidos
float calcularCustoBeneficio(int custoBeneficio[2]) {
    return custoBeneficio[0]/custoBeneficio[1];
}