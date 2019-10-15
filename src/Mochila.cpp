#include <iostream>

int semRepeticao(int ilhas[][2], int orcamento, int n, int* dias, int* pontuacao) {
    return 0;
}

int comRepeticao(int ilhas[][2], int orcamento, int n, int* dias, int* pontuacao) {
    int custo = 0, i = 0;
    
    while (orcamento - custo >= 0 && i < n) {
        if (ilhas[i][0] <= (orcamento-custo)) {
            custo += ilhas[i][0];
            *dias = *dias+1;
            *pontuacao += ilhas[i][1];
        } else {
            i++;
        }
    }

    return custo;
}
