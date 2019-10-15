#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#define NUMFILHOS 3
//Define o TipoItem, que é o tipo dos elementos a serem manipulados pela árvore
typedef struct _TipoItem {
    int vertice;
    char nome;
} TipoItem;

//Define o TipoArvore, que é o tipo de cada nó da árvore
typedef struct _TipoArvore {
    TipoItem item;
    struct _TipoArvore* filhos[NUMFILHOS];
} TipoArvore;

//Cria uma árvore vazia
void criaArvoreVazia(TipoArvore** arvore);
//Testa se a árvore está vazia
int testaArvoreVazia(TipoArvore** arvore);
//Cria uma árvore
void criaArvore(TipoItem item, TipoArvore** arvore, TipoArvore* filhos[NUMFILHOS]);
//Libera a árvore
TipoArvore* liberaArvore(TipoArvore** arvore);
//Verifica se um elemento pertence à árvore
int pertenceArvore(TipoArvore** arvore, TipoItem item);
//Imprime os elementos da árvore
void imprimeArvore(TipoArvore** arvore, int l);

#endif //ARVORE_H_INCLUDED