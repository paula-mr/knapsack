#include <iostream>

#include "Mergesort.h"

int semRepeticao(int ilhas[][2], int orcamento, int tamanho, int* dias, int* pontuacao) {
    return 0;
}

int comRepeticao(int ilhas[][2], int orcamento, int tamanho, int* dias, int* pontuacao) {
    int custo = 0;

    //ordena por custo beneficio
    ordenar(ilhas, tamanho);
    
    //executa enquanto houver orcamento ou o array acabar
    for (int i=0; i < tamanho; i++) {
        if (ilhas[i][0] <= (orcamento-custo)) {
            //caso o custo da ilha seja menor ou igual ao orcamento disponivel
            //adiciona a quantidade de vezes disponiveis
            int qtdDias = (orcamento-custo)/ilhas[i][0];
            custo += ilhas[i][0]*qtdDias;
            *dias = *dias+qtdDias;
            *pontuacao += ilhas[i][1]*qtdDias;
        }
    }

    return custo;
}
