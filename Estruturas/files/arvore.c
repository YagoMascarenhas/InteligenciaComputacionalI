#include <stdio.h>
#include <stdlib.h>
#include "..\headers\arvore.h"

//Cria uma árvore ternária vazia
void criaArvoreTernariaVazia(TipoArvore** arvore) {
    *arvore = NULL;
}

//Testa se a árvore ternária está vazia
int testaArvoreTernariaVazia(TipoArvore** arvore) {
    return (*arvore == NULL);
}

//Cria uma árvore ternária
void criaArvoreTernaria(TipoItem item, TipoArvore** arvore, TipoArvore** esquerda, TipoArvore** meio, TipoArvore** direita) {
    *arvore = (TipoArvore*)malloc(sizeof(TipoArvore));
    (*arvore)->item = item;
    (*arvore)->esquerda = esquerda;
    (*arvore)->meio = meio;
    (*arvore)->direita = direita;
}

//Libera a árvore ternária
TipoArvore* liberaArvoreTernaria(TipoArvore** arvore) {
    if (!testaArvoreTernariaVazia(arvore)) {
        liberaArvoreTernaria((*arvore)->esquerda);
        liberaArvoreTernaria((*arvore)->meio);
        liberaArvoreTernaria((*arvore)->direita);
        free(arvore);
    }
}

//Verifica se um elemento pertence à árvore ternária
int pertenceArvoreTernaria(TipoArvore** arvore, TipoItem item) {
    if (testaArvoreTernariaVazia(arvore)) {
        return 0;
    } else {
        return (*arvore)->item.nome == item.nome ||
            pertenceArvoreTernaria((*arvore)->esquerda, item) || 
            pertenceArvoreTernaria((*arvore)->meio, item) ||
            pertenceArvoreTernaria((*arvore)->direita, item);
    }
}

//Imprime os elementos da árvore ternária
void imprimeArvoreTernaria(TipoArvore** arvore, int l) {
    int i;

    if(!testaArvoreTernariaVazia(arvore)) {
        imprimeArvoreTernaria((*arvore->esquerda), l + 1);

        for (i = 0; i < l, i++) {
            printf("   ");
        }

        printf("%c \n", (*arvore)->item.nome);
        
        imprimeArvoreTernaria((*arvore->meio), l + 1);
        imprimeArvoreTernaria((*arvore->direita), l + 1);
    }
}