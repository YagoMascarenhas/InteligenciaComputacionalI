#include <stdio.h>
#include "..\headers\TAD.h"

//Cria uma lista vazia
TipoLista* criaListaVazia() {
    TipoLista* lista;

    lista = (TipoLista*)malloc(sizeof(TipoPilha);

    //Verifica se foi corretamente alocado
    if(lista == NULL){
        printf("Erro de alocação da lista!\n");
        exit(1);
    }

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

//Testa se a lista está vazia
int testaListaVazia(TipoLista* lista) {
    return (lista->primeiro == NULL);
}

//Insere um elemento na lista
void insereLista(TipoLista* lista, TipoCelula item) {
    item.proximo = NULL;
    //Verifica se a lista é vazia e insere o item como primeiro e último elemento
    if(testaListaVazia(lista)) {
        lista->primeiro = &item;
        lista->ultimo = lista->primeiro;
    } else {
        //Adiciona o elemento ao fim da lista
        lista->ultimo->proximo = &item;
        lista->ultimo = lista->ultimo->proximo;
    }
}

//Remove um elemento da lista
TipoCelula* removeLista(TipoFila* fila, TipoCelula item) {
    //Verifica se a lista está vazia
    if(testaListaVazia(lista)) {
        printf("A lista está vazia!\n");
        return NULL;
    }

    TipoCelula* aux = fila->primeiro;

    //Verifica se o primeiro elemento é o resultado
    if(fila->primeiro->item->nome == item.nome) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
        return aux;
    }
    
    TipoCelula* q;

    while(aux != NULL) {
        if(aux->proximo->item->nome == item.nome) {
            q = aux->proximo;
            aux->proximo = q->proximo;
            return q;
        }
    }

    return NULL;
}

//Imprime os elementos da lista
void imprimeLista(TipoLista* lista) {
    TipoCelula* aux = lista->primeiro;
    while(aux != NULL) {
        printf("%i", aux->nome);
        aux = aux->proximo;
    }
}