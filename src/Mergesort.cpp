#include "Mergesort.h"

void ordena(Ilha ilhas[], int esquerda, int direita);
void merge(Ilha ilhas[], int esquerda, int meio, int direita);
float calcularCustoBeneficio(Ilha ilha);

void ordenar(Ilha ilhas[], int n) {
    //inicia funcao de ordenacao por mergesort
    ordena(ilhas, 0, n-1);
}

void ordena(Ilha ilhas[], int esquerda, int direita) {
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

void merge(Ilha ilhas[], int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita =  direita - meio;

    //cria uma copia para o array da esquerda
    Ilha arrayEsquerda[tamanhoEsquerda], arrayDireita[tamanhoDireita];
    for (i = 0; i < tamanhoEsquerda; i++) {
        arrayEsquerda[i].custo = ilhas[esquerda + i].custo;
        arrayEsquerda[i].pontuacao = ilhas[esquerda + i].pontuacao;
    }

    //cria uma copia para o array da direita
    for (j = 0; j < tamanhoDireita; j++) {
        arrayDireita[j].custo = ilhas[meio + 1+ j].custo;
        arrayDireita[j].pontuacao = ilhas[meio + 1+ j].pontuacao;
    }

    i = 0; // valor inicial do subarray da esquerda
    j = 0; // valor inicial do subarray da direita
    k = esquerda; // valor inicial do subarray mergeado

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        //define qual item possui maior custo beneficio
        if (calcularCustoBeneficio(arrayEsquerda[i]) <= calcularCustoBeneficio(arrayDireita[j])) {
            ilhas[k].custo = arrayEsquerda[i].custo;
            ilhas[k].pontuacao = arrayEsquerda[i].pontuacao;
            i++;
        }
        else {
            ilhas[k].custo = arrayDireita[j].custo;
            ilhas[k].pontuacao = arrayDireita[j].pontuacao;
            j++;
        }
        k++;
    }

    //copia o array da esquerda ordenado para o array mergeado
    while (i < tamanhoEsquerda) {
        ilhas[k].custo = arrayEsquerda[i].custo;
        ilhas[k].pontuacao = arrayEsquerda[i].pontuacao;
        i++;
        k++;
    }

    //copia o array da direita ordenado para o array mergeado
    while (j < tamanhoDireita) {
        ilhas[k].custo = arrayDireita[j].custo;
        ilhas[k].pontuacao = arrayDireita[j].pontuacao;
        j++;
        k++;
    }

}

//calcula o custo beneficio da ilha com base em custo e pontos atribuidos
float calcularCustoBeneficio(Ilha ilha) {
    return ilha.custo/ilha.pontuacao;
}