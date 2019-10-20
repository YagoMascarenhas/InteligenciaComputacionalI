#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#define TRUE 1
#define FALSE 0

//Define o TipoCelula de cada elemento a ser manipulado pelas listas, pilhas e filas
typedef struct _TipoCelula {
    char nome;
    int vertice, peso;
    struct _TipoCelula* proximo;
} TipoCelula;

//Define o TipoLista, que é o tipo do TAD lista
typedef struct _TipoLista {
    TipoCelula* primeiro;
    TipoCelula* ultimo;
} TipoLista;

//Define o TipoPilha, que é o tipo do TAD pilha 
typedef struct _TipoPilha {
    TipoCelula* topo;
    TipoCelula* fundo;
} TipoPilha;

//Define o TipoFila, que é o tipo do TAD fila  
typedef struct _TipoFila {
    TipoCelula* inicio;
    TipoCelula* fim;
} TipoFila;


//Implementações do TAD lista

//Cria uma lista vazia
TipoLista* criaListaVazia();
//Testa se a lista está vazia
int testaListaVazia(TipoLista* lista);
//Insere um elemento na lista
void insereLista(TipoLista* lista, TipoCelula item);
//Remove um elemento da lista
TipoCelula* removeLista(TipoFila* fila, TipoCelula item);
//Imprime os elementos da lista
void imprimeLista(TipoLista* lista)


//Implementações do TAD pilha

//Cria uma pilha vazia
TipoPilha* criaPilhaVazia();
//Testa se a pilha está vazia
int testaPilhaVazia(TipoPilha* pilha);
//Insere um elemento na pilha
void inserePilha(TipoPilha* pilha, TipoCelula item);
//Remove um elemento da pilha
TipoCelula* removePilha(TipoPilha* pilha);


//Implementações do TAD fila

//Cria uma fila vazia
TipoFila* criaFilaVazia();
//Testa se a fila está vazia
int testaFilaVazia(TipoFila* fila);
//Insere um elemento na fila
void insereFila(TipoFila* fila, TipoCelula item);
//Remove um elemento da fila
TipoCelula* removeFila(TipoFila* fila);

#endif // TAD_H_INCLUDED