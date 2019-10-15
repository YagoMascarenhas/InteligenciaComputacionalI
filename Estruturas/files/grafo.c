#include <stdio.h> //Tá na hora de parar de acusar erro, né, VScode?
#include <stdlib.h> //Já resolvi essas importações com o vcpkg
#include "..\headers\grafo.h"

//Função para criar grafo vazio
TipoGrafo* criaGrafoVazio(TipoGrafo* grafo) {
    int i, j;

    grafo = (TipoGrafo*)malloc(sizeof(TipoGrafo));

    grafo->numVertices = MAXNUMVERTICES;
    grafo->numArestas = 0;

    //Percorre a matriz de adjacentes e adiciona peso 0 para todos
    for (i = 0; i < grafo->numVertices; i++){
        for (j = 0; j < grafo->numVertices; j++){
            grafo->mat[i][j] = 0;
        }
    }

    return (grafo);
}

//Função para inserir aresta no grafo
void insereAresta(TipoValorVertice* v1, TipoValorVertice* v2, TipoPeso* peso, TipoGrafo* grafo) {
    //Adiciona o peso determinado ao par de nós do grafo
    grafo->mat[*v1][*v2] = *peso;
    //Incrementa o número de arestas em 1
    grafo->numArestas++;
}

//Verifica se existe uma aresta
int existeAresta(TipoValorVertice* v1, TipoValorVertice* v2, TipoGrafo* grafo) {
    //Retorna 1 (TRUE) se a aresta existir e retorna 0 (FALSE) caso ela não exista
    return (grafo->mat[*v1][*v2] > 0); //Não existem pesos negativos
}

//Operadores para obter a lista de adjacentes
//Verifica se a lista de adjacentes está vazia
int listaAdjacentesVazia(TipoValorVertice* v, TipoGrafo* grafo) {
    TipoApontador aux = 0;
    int listaVazia = TRUE;

    while (aux < grafo->numVertices && listaVazia) {
        //Se houver algum nó com peso, a lista não está vazia
        if (grafo->mat[*v][aux] > 0) {
            listaVazia = FALSE;
        } else {
            aux++;
        }
    }

    return (listaVazia);
}

//Retorna a lista de adjacentes
void retornaListaAdjacentes(TipoValorVertice* v, TipoGrafo* grafo, TipoValorVertice* lista) {
    TipoApontador aux = 0;
    int cont = 0;

    //Testa se a lista de adjacentes está vazia
    if (listaAdjacentesVazia(v, grafo) == TRUE){
        printf("Erro: Lista de adjacentes vazia!");
    }

    //Se a lista não estiver vazia, testa e armazena os elementos dela em um vetor
    while (aux < grafo->numVertices){
        if (grafo->mat[*v][aux] > 0) {
            lista[cont] = aux;
            cont++;
            aux++;
        } else {
            aux++;
        }
    }
}

//Pega o primeiro elemento da lista de adjacentes
TipoApontador primeiroListaAdjacentes(TipoValorVertice* v, TipoGrafo* grafo) {
    TipoApontador aux = 0;

    //Testa se o vértice tem algum elemento na sua lista de adjacentes
    if (listaAdjacentesVazia(v, grafo) == TRUE){
        printf("Erro: Lista de adjacentes vazia!");
        return ERRO;
    }

    //Retorna o primeiro elemento encontrado na lista de adjacentes 
    while (aux < grafo->numVertices) {
        if (grafo->mat[*v][aux] > 0) {
            return(aux);
        } else {
            aux++;
        }
    }
}

//Pega o próximo elemento da lista de adjacentes
int proximoAdjacente(TipoValorVertice* v, TipoGrafo* grafo, TipoValorVertice* adj, TipoPeso* peso, TipoApontador* prox) {
    //Retorna adjacente apontado por prox
    TipoApontador aux = *adj;
    *prox = (*adj) + 1;

    while (*prox < grafo->numVertices && grafo->mat[*v][*prox] == 0) {
        (*prox)++;
    }

    //Verifica se todo o grafo foi percorrido e não encontrou um próximo
    if (*prox == grafo->numVertices) {
        return (TRUE);
    }
}

//Retira uma aresta
void retiraAresta(TipoValorVertice* v1, TipoValorVertice* v2,  TipoPeso* peso, TipoGrafo* grafo) {
    //Imprime erro se a aresta não existir
    if (grafo->mat[*v1][*v2] == 0) {
        printf("Aresta não existe!");
    } else {
        *peso = grafo->mat[*v1][*v2];
        grafo->mat[*v1][*v2] = 0;
    }
}

//Imprime o grafo
void imprimeGrafo(TipoGrafo* grafo) {
    int i, j;
    printf("    |");

    for(i = 0; i <= grafo->numVertices - 1; i++){
        printf("|%3d|", i);
    }

    printf("\n");

    for(i = 0; i <=  grafo->numVertices - 1; i++){
        printf("|%3d|", i);
        for(j = 0; j <= grafo->numVertices - 1; j++){
            printf("|%3d|", grafo->mat[i][j]);
        }
        printf("\n");
    }
}