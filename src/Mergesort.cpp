#include "Mergesort.h"

void ordena(Ilha ilha[], int esquerda, int direita);
void merge(Ilha ilha[], int esquerda, int meio, int direita);

void ordenar(Ilha ilha[], int n) {
    //inicia funcao de ordenacao por mergesort
    ordena(ilha, 0, n-1);
}

void ordena(Ilha ilha[], int esquerda, int direita) {
    //caso os apontadores nao tenham se cruzado ou sejam os mesmos
    if (esquerda < direita) {
        int meio = esquerda+(direita-esquerda)/2;

        //ordena metade da esquerda
        ordena(ilha, esquerda, meio);
        //ordena metade da direita
        ordena(ilha, meio+1, direita);

        //junta os arrays ordenados
        merge(ilha, esquerda, meio, direita);
    }
}

void merge(Ilha ilha[], int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita =  direita - meio;

    //cria uma copia para o array da esquerda
    Ilha arrayEsquerda[tamanhoEsquerda], arrayDireita[tamanhoDireita];
    for (i = 0; i < tamanhoEsquerda; i++) {
        arrayEsquerda[i].custo = ilha[esquerda + i].custo;
        arrayEsquerda[i].pontuacao = ilha[esquerda + i].pontuacao;
    }

    //cria uma copia para o array da direita
    for (j = 0; j < tamanhoDireita; j++) {
        arrayDireita[j].custo = ilha[meio + 1+ j].custo;
        arrayDireita[j].pontuacao = ilha[meio + 1+ j].pontuacao;
    }

    i = 0; // valor inicial do subarray da esquerda
    j = 0; // valor inicial do subarray da direita
    k = esquerda; // valor inicial do subarray mergeado

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        //define qual item possui maior custo beneficio
        if (arrayEsquerda[i].calcularCustoBeneficio() < arrayDireita[j].calcularCustoBeneficio()) {
            ilha[k].custo = arrayEsquerda[i].custo;
            ilha[k].pontuacao = arrayEsquerda[i].pontuacao;
            i++;
        }
        //se itens possui mesmo custo beneficio, ordena pela maior pontuacao
        else if (arrayEsquerda[i].calcularCustoBeneficio() == arrayDireita[j].calcularCustoBeneficio() &&
            arrayEsquerda[i].pontuacao > arrayDireita[j].pontuacao) {

            ilha[k].custo = arrayEsquerda[i].custo;
            ilha[k].pontuacao = arrayEsquerda[i].pontuacao;
            i++;
        } else {
            ilha[k].custo = arrayDireita[j].custo;
            ilha[k].pontuacao = arrayDireita[j].pontuacao;
            j++;
        }
        k++;
    }

    //copia o array da esquerda ordenado para o array mergeado
    while (i < tamanhoEsquerda) {
        ilha[k].custo = arrayEsquerda[i].custo;
        ilha[k].pontuacao = arrayEsquerda[i].pontuacao;
        i++;
        k++;
    }

    //copia o array da direita ordenado para o array mergeado
    while (j < tamanhoDireita) {
        ilha[k].custo = arrayDireita[j].custo;
        ilha[k].pontuacao = arrayDireita[j].pontuacao;
        j++;
        k++;
    }

}