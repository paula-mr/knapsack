#include <iostream>

#include "Mergesort.h"

int semRepeticao(int ilhas[][2], int orcamento, int tamanho, int* dias, int* pontuacao) {
    return 0;
}

int comRepeticao(int ilhas[][2], int orcamento, int tamanho, int* dias, int* pontuacao) {
    int custo = 0, i = 0;

    //ordena por custo beneficio
    ordenar(ilhas, tamanho);
    
    //executa enquanto houver orcamento ou o array acabar
    while (orcamento - custo >= 0 && i < tamanho) {
        if (ilhas[i][0] <= (orcamento-custo)) {
            //caso o custo da ilha seja menor ou igual ao orcamento disponivel, adiciona-a
            custo += ilhas[i][0];
            *dias = *dias+1;
            *pontuacao += ilhas[i][1];
        } else {
            //passa para o proximo elemento da lista ordenada por custo beneficio
            i++;
        }
    }

    return custo;
}
