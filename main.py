import Estruturas.grafo as g
import BuscasCegas.buscaProfundidade as bp
import BuscasCegas.backtracking as bt
import BuscasCegas.buscaLargura as bl
import BuscasCegas.buscaOrdenada as bo
import BuscasInformadas.buscaGulosa as bg
import BuscasInformadas.buscaAEstrela as ba

grafo = g.Grafo()

#Labirinto é o grafo para testar largura, profundidade e backtracking
f = "Grafos/labirinto.txt"
#para testar as outras buscas, use grafo1.txt

#Lendo o grafo do arquivo
arquivo = open(f)
for linha in arquivo:
    v1, v2, p = linha.split()
    grafo.adicionaAresta(v1, v2, int(p))

#Caso queira imprimir o grafo
#grafo.imprimeGrafo()

#Executa a busca em profundidade
bp.buscaProfundidade(grafo, "A", "S")
#Executa backtracking
#bt.backtracking(grafo, "A", "S")
#Executa a busca em largura
#bl.buscaLargura(grafo, "A", "S")
#Executa a busca ordenada
#bo.buscaOrdenada(grafo, "A", "G")

#Comentários adicionados para separar as execuções. Remova para executar

#grafo.geraValoresHeuristicos(1)
#Executa busca gulosa
#bg.buscaGulosa(grafo, "A", G")
#Executa busca A*
#ba.buscaAEstrela(grafo, "A", "G")