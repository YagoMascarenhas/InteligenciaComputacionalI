#include <stdio.h>
#include "..\headers\TAD.h"

//Cria uma fila vazia
TipoFila* criaFilaVazia() {
    TipoFila* fila;

    fila = (TipoFila*)malloc(sizeof(TipoFila));

    if (fila == NULL) {
        printf("Problema de alicação da fila");
        exit(1);
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

//Testa se a fila está vazia
int testaFilaVazia(TipoFila* fila) {
    return (fila->frente == NULL);
}

//Insere um elemento na fila
void insereFila(TipoFila* fila, TipoCelula item) {
    //Verifica se a fila está vazia e adiciona o elemento como primeiro e último
    if (testaFilaVazia(fila)) {
        fila->inicio = (TipoCelula*)malloc(sizeof(TipoCelula));
        fila->inicio->item = &item;
        fila->fim = fila->inicio;
        return;
    }
    
    fila->fim->proximo = (TipoCelula*)malloc(sizeof(TipoCelula));
    fila->fim = fila->tras->proximo;
    fila->fim->item = &item;
    fila->fim->proximo;
}

//Remove um elemento da fila
TipoCelula* removeFila(TipoFila* fila) {
    TipoCelula *aux;

    if (testaFilaVazia(fila)) {
        printf("A fila está vazia!\n");
        return NULL;
    }
    
    aux = fila->primeiro;
    fila->primeiro = aux->prox;

    return aux;
}