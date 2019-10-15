//Bastante orgulhoso de mim, porque eu entendi o que ifndef, ifdef e endif fazem
#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#define MAXNUMVERTICES 20
#define MAXNUMARESTAS 500
#define TRUE 1
#define FALSE 0
#define ERRO 25

//Define alguns tipos a serem usados no grafo
//Define um tipo inteiro de valor para o vértice
typedef int TipoValorVertice;
//Define o tipo peso
typedef int TipoPeso;
//Define o tipo apontador (para percorrer a matriz)
typedef int TipoApontador;

//Define o TipoGrafo a ser usado na criação do grafo
typedef struct _TipoGrafo {
    TipoPeso mat[MAXNUMVERTICES][MAXNUMVERTICES];
    int numVertices;
    int numArestas;
} TipoGrafo;

//Função para criar grafo vazio
TipoGrafo* criaGrafoVazio(TipoGrafo* grafo);
//Função para inserir aresta no grafo
void insereAresta(TipoValorVertice* v1, TipoValorVertice* v2, TipoPeso* peso, TipoGrafo* grafo);
//Verifica se existe uma aresta
int existeAresta(TipoValorVertice* v1, TipoValorVertice* v2, TipoGrafo* grafo);

//Operadores para obter a lista de adjacentes
//Verifica se a lista de adjacentes está vazia
int listaAdjacentesVazia(TipoValorVertice* v, TipoGrafo* grafo);
//Retorna a lista de adjacentes
void retornaListaAdjacentes(TipoValorVertice* v, TipoGrafo* grafo, TipoValorVertice* lista);
//Pega o primeiro elemento da lista de adjacentes
TipoApontador primeiroListaAdjacentes(TipoValorVertice* v, TipoGrafo* grafo);
//Pega o próximo elemento da lista de adjacentes
int proximoAdjacente(TipoValorVertice* v, TipoGrafo* grafo, TipoValorVertice* adj, TipoPeso* peso, TipoApontador* prox);

//Retira uma aresta
void retiraAresta(TipoValorVertice* v1, TipoValorVertice* v2,  TipoPeso* peso, TipoGrafo* grafo);
//Imprime o grafo
void imprimeGrafo(TipoGrafo* grafo);
#endif // GRAFO_H_INCLUDED