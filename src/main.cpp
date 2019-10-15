#include <stdio.h>
#include <iostream>

#include "Mochila.h"

FILE* abrirArquivo(int argc, char *argv[]);
int recuperarNumero(FILE* arquivo);

int main(int argc, char *argv[]) {

    FILE* arquivo = abrirArquivo(argc, argv);
    if (arquivo == NULL)
        return 1;

    int gastoMax, qtdIlhas;

    gastoMax = recuperarNumero(arquivo);
    qtdIlhas = recuperarNumero(arquivo);

    int ilhas[qtdIlhas][2];

    for (int i=0; i<qtdIlhas;i++) {
        ilhas[i][0] = recuperarNumero(arquivo);
        ilhas[i][1] = recuperarNumero(arquivo);
    }

	fclose(arquivo);

	//executa algoritmo nao dinamico com repeticao
	int diasComRepeticao = 0, pontuacaoComRepeticao = 0;
	comRepeticao(ilhas, gastoMax, qtdIlhas, &diasComRepeticao, &pontuacaoComRepeticao);

    std::cout << pontuacaoComRepeticao << " " << diasComRepeticao << "\n";

    //executa algoritmo dinamico sem repeticao
    int diasSemRepeticao = 0, pontuacaoSemRepeticao = 0;
    semRepeticao(ilhas, gastoMax, qtdIlhas, &diasSemRepeticao, &pontuacaoSemRepeticao);

	std::cout << pontuacaoSemRepeticao << " " << diasSemRepeticao << "\n";

    return 0;
}

FILE* abrirArquivo(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Parâmetro inválido.";
        return NULL;
    }

    char* nomeArquivo = argv[1];

    FILE* arquivo = fopen(nomeArquivo, "r");

    return arquivo;
}

int recuperarNumero(FILE* arquivo) {
    int numero = 0, auxiliar;

    //enquanto char lido nao for espaco branco ou nova linha
    while ((auxiliar = fgetc(arquivo)) != ' ' && auxiliar != '\n') {
        numero*=10;
        //transforma char em valor numerico
        numero+=auxiliar-48;
    }

    return numero;
}
