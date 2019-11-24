import BuscaEmProfundidade.buscaProfundidade as bp
class Grafo(object):
    #Inicializa as estruturas base do grafo
    def __init__(self):
        self.adj = {}

    #Adiciona arestas
    def adicionaAresta(self, v1, v2, peso):
        if v1 not in self.adj:
            self.adj[v1] = {}
        self.adj[v1].update({v2: peso})
        bp.func()
        bp.func2()

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
        else:
            return self.adj[v]