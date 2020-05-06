# InteligenciaComputacionalI
Algoritmos implementados para a disciplina de Inteligência Computacional I na UEZO.

Algoritmos a serem implementados:
1. Busca em Profundidade (ok)
2. Backtracking (ok)
3. Busca em Largura (ok)
4. Busca Ordenada (ok)
5. Busca Gulosa (ok)
6. Busca A* (ok)
7. Sistema Especialista (ok)

### Como usar:
* Na pasta **Grafos** estão os arquivos de texto usados para gerar os grafos.
    * Caso queira testar com algum arquivo que não esteja na pasta, mude o caminho e, caso o grafo seja não ponderado, use um valor fixo para TODOS os pesos (eu prefiro usar 0 ou 1, mas é de livre escolha)
* Sobre as buscas:
    * Todas elas recebem três parâmetros:
        1. O primeiro é o _**grafo**_
        2. O segundo é o _**comeco**_, que é o nome do nó de onde deseja se começar a busca
        3. O terceiro é o _**alvo**_, que é o nome do nó que se deseja buscar no grafo (por padrão, é o **S** em largura, profundidade e backtracking; e **G** em ordenada, gulosa e A*)
