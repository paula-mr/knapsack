#include <iostream>

#include "Mergesort.h"

int maximo(int a, int b);

//implementacao com programacao dinamica
void semRepeticao(Ilha ilha[], int orcamento, int tamanho, int* dias, int* pontuacao) {
    int possibilidades[tamanho+1][orcamento+1]; 

    for (int i = 0; i <= tamanho; i++) { 
       for (int w = 0; w <= orcamento; w++) { 
            //valida posicoes iniciais para evitar array out of bounds
            if (i==0 || w==0) {
                possibilidades[i][w] = 0; 
            }
            else if (ilha[i-1].custo <= w) {
                //se ha espaco no orcamento, adiciona o maior possivel
                possibilidades[i][w] = maximo(ilha[i-1].pontuacao + possibilidades[i-1][w-ilha[i-1].custo],  possibilidades[i-1][w]); 
            }
            else {
                //a pontuacao sera a mesma: nao eh possivel adicionar mais um item
                possibilidades[i][w] = possibilidades[i-1][w]; 
            }
       } 
    } 

    *pontuacao = possibilidades[tamanho][orcamento];

    //salva resultado de pontuacao e o orcamento em variavel auxiliar
    int resultado = possibilidades[tamanho][orcamento];
    int gasto = orcamento; 

    //navega na matriz para ver quantos dias a viagem durara
    for (int i = tamanho; i > 0 && resultado > 0; i--) { 
        if (resultado == possibilidades[i - 1][gasto])  {
            //nao foi adicionada nova ilha    
        } else { 
            *dias += 1;

            resultado -= ilha[i-1].pontuacao; 
            gasto -= ilha[i-1].custo; 
        } 
    } 
}

//funcao que retorna o maximo entre dois numeros
int maximo(int a, int b) { 
    return (a > b) ? a : b; 
} 

//implementacao sem programacao dinamica
void comRepeticao(Ilha ilha[], int orcamento, int tamanho, int* dias, int* pontuacao) {
    int custo = 0;

    //ordena por custo beneficio
    ordenar(ilha, tamanho);
    
    //executa enquanto houver orcamento ou o array acabar
    for (int i=0; i < tamanho; i++) {
        if (ilha[i].custo <= (orcamento-custo)) {
            //caso o custo da ilha seja menor ou igual ao orcamento disponivel
            //adiciona a quantidade de vezes disponiveis
            int qtdDias = (orcamento-custo)/ilha[i].custo;
            custo += ilha[i].custo*qtdDias;
            *dias += qtdDias;
            *pontuacao += ilha[i].pontuacao*qtdDias;
        }
    }
}
