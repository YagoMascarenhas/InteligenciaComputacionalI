#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

//Define o TipoItem, que é o tipo dos elementos a serem manipulados pela árvore
typedef struct _TipoItem {
    char nome;
    int vertice, peso;
} TipoItem;

//Define o TipoArvore, que é o tipo de cada nó da árvore
typedef struct _TipoArvore {
    TipoItem item;
    struct _TipoArvore* esquerda;
    struct _TipoArvore* meio;
    struct _TipoArvore* direita;
} TipoArvore;

//Cria uma árvore ternária vazia
void criaArvoreTernariaVazia(TipoArvore** arvore);
//Testa se a árvore ternária está vazia
int testaArvoreTernariaVazia(TipoArvore** arvore);
//Cria uma árvore ternária
void criaArvoreTernaria(TipoItem item, TipoArvore** arvore, TipoArvore** esquerda, TipoArvore** meio, TipoArvore** direita);
//Libera a árvore ternária
TipoArvore* liberaArvoreTernaria(TipoArvore** arvore);
//Verifica se um elemento pertence à árvore ternária
int pertenceArvoreTernaria(TipoArvore** arvore, TipoItem item);
//Imprime os elementos da árvore ternária
void imprimeArvoreTernaria(TipoArvore** arvore, int l);

#endif //ARVORE_H_INCLUDED