import sys
class Grafo(object):
    #Inicializa as estruturas base do grafo
    def __init__(self):
        self.adj = {}

    #Adiciona arestas
    def adicionaAresta(self, v1, v2, peso):
        if v1 not in self.adj:
            self.adj[v1] = {}
        self.adj[v1].update({v2: peso})

    #Imprime o grafo
    def imprimeGrafo(self):
        for u in self.adj:
            print(u, ":")
            for v in self.adj[u]:
                print("\t", v, ": ", self.adj[u][v])

    #Retorna todos os nós adjacentes ao nó desejado
    def retornaLigacoes(self, v):
        if v not in self.adj:
            print("Vértice não existe")
            return None
        else:
            return self.adj[v]

    #Gera um nó filho inédito da aresta
    def geraFilhoInedito(self, v, abertos, fechados):
        filhos = self.retornaLigacoes(v)
        for filho in filhos:
            if filho not in abertos and filho not in fechados:
                return filho
        return None

    #Retorna o elemento de menor custo da lista
    def elementoMenorCusto(self, lista):
        menor = sys.maxsize
        for no in lista:
            if menor > lista[no]:
                node = no
                menor = lista[no]
        return node, menor

    #Gera o valor de h(n)
    def geraValoresHeuristicos(self, tipo):
        '''TODO: mudar função também para leitura de arquivos depois'''
        if tipo == 1:
            self.heuristica = {
                "A": 24,
                "B": 15,
                "C": 22,
                "D": 12,
                "E": 7,
                "F": 7,
                "G": 0
            }
        else:
            if tipo == 2:
                self.heuristica = {
                    "A": 16,
                    "B": 13,
                    "C": 15,
                    "D": 7,
                    "E": 10,
                    "F": 10,
                    "G": 0
                }

    #Função que avalia o nó e retorna o valor avaliado
    def avaliaVertice(self, v, p):
        return self.heuristica[v] + p