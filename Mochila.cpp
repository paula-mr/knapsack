#include <iostream>

int semRepeticao(int ilhas[][2], int orcamento, int n, int* dias, int* pontuacao) {
    return 0;
}

int comRepeticao(int ilhas[][2], int orcamento, int n, int* dias, int* pontuacao) {

    if (n == 0 || orcamento == 0)
        return 0;

    if (ilhas[n-1][0] > orcamento) {
        return comRepeticao(ilhas, orcamento, n-1, dias, pontuacao);
    }


    int itemIncluido, itemNaoIncluido;

    int pontuacaoIncluida = *pontuacao + ilhas[n-1][1];
    int pontuacaoNaoIncluida = *pontuacao;

    int diasIncluido = *dias + 1;
    int diasNaoIncluido = *dias;

    itemIncluido = ilhas[n-1][0] + comRepeticao(ilhas, orcamento-ilhas[n-1][0], n-1, &diasIncluido, &pontuacaoIncluida);
    itemNaoIncluido = comRepeticao(ilhas, orcamento, n-1, &diasNaoIncluido, &pontuacaoNaoIncluida);

    if (itemIncluido < itemNaoIncluido) {
        *pontuacao = pontuacaoNaoIncluida;
        *dias = diasNaoIncluido;
        return itemNaoIncluido;
    }

    *dias = diasIncluido;
    *pontuacao = pontuacaoIncluida;

    return itemIncluido;
}
