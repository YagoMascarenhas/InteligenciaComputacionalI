#include <stdio.h>
#include <stdlib.h>
#include "Estruturas\headers\grafo.h"

int main() {
    TipoGrafo* grafo;
    TipoValorVertice v1 = 1, v2 = 1;
    TipoPeso peso = 1;

    printf("%d - %d -  %d", v1, v2, peso);
    
    grafo = criaGrafoVazio(grafo);

    imprimeGrafo(grafo);
    insereAresta(&v1, &v2, &peso, grafo);
    printf("%d", grafo->mat[v1][v2]);
    v1 = 3; v2 = 5;
    insereAresta(&v1, &v2, &peso, grafo);
    printf("%d", grafo->mat[v1][v2]);
    v1 = 8; v2 = 2;
    insereAresta(&v1, &v2, &peso, grafo);
    printf("%d", grafo->mat[v1][v2]);

    imprimeGrafo(grafo);
    return 0;
}