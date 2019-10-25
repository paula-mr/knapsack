#include <stdio.h>
#include <iostream>

#include "Mochila.h"
#include "Ilha.h"

FILE* abrirArquivo(int argc, char *argv[]);
int recuperarNumero(FILE* arquivo);

int main(int argc, char *argv[]) {

    FILE* arquivo = abrirArquivo(argc, argv);
    if (arquivo == NULL)
        return 1;

    int gastoMax, qtdIlhas;

    gastoMax = recuperarNumero(arquivo);
    qtdIlhas = recuperarNumero(arquivo);

    Ilha ilha[qtdIlhas];

    for (int i=0; i<qtdIlhas;i++) {
        ilha[i].custo = recuperarNumero(arquivo);
        ilha[i].pontuacao = recuperarNumero(arquivo);
    }

	fclose(arquivo);

    //executa algoritmo dinamico sem repeticao
    int diasSemRepeticao = 0, pontuacaoSemRepeticao = 0;
    semRepeticao(ilha, gastoMax, qtdIlhas, &diasSemRepeticao, &pontuacaoSemRepeticao);

	//executa algoritmo nao dinamico com repeticao
	int diasComRepeticao = 0, pontuacaoComRepeticao = 0;
	comRepeticao(ilha, gastoMax, qtdIlhas, &diasComRepeticao, &pontuacaoComRepeticao);

    std::cout << pontuacaoComRepeticao << " " << diasComRepeticao << "\n";
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
    while ((auxiliar = fgetc(arquivo)) != ' ' && auxiliar != '\n' && auxiliar != EOF) {
        numero*=10;
        //transforma char em valor numerico
        numero+=auxiliar-48;
    }

    return numero;
}
