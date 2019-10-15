#include <stdio.h>
#include <stdlib.h>
#include "..\headers\arvore.h"

//Cria uma árvore vazia
void criaArvoreVazia(TipoArvore** arvore) {
    *arvore = NULL;
}

//Testa se a árvore está vazia
int testaArvoreVazia(TipoArvore** arvore) {
    return (*arvore == NULL);
}

//Cria uma árvore
void criaArvore(TipoItem item, TipoArvore** arvore, TipoArvore* filhos[3]) {
    int i;

    *arvore = (TipoArvore*)malloc(sizeof(TipoArvore));
    (*arvore)->item = item;

    for (i = 0; i < NUMFILHOS; i++){
        (*arvore)->filhos[i] = filhos[i];
    }
}

//Libera a árvore
TipoArvore* liberaArvore(TipoArvore** arvore);
//Verifica se um elemento pertence à árvore
int pertenceArvore(TipoArvore** arvore, TipoItem item);
//Imprime os elementos da árvore
void imprimeArvore(TipoArvore** arvore, int l);