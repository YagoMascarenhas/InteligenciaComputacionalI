def buscaAEstrela(grafo, comeco, alvo):
    h = grafo.heuristica
    resposta = None
    listaAbertos = {comeco: h[comeco]}
    listaFechados = []
    sucesso = False
    while not sucesso and listaAbertos:
        candidato, custo = grafo.elementoMenorCusto(listaAbertos)
        del(listaAbertos[candidato])
        listaFechados.append(candidato)
        print(candidato, " -> ", custo)
        if candidato == alvo:
            sucesso = True
            resposta = candidato
        else:
            filhos = grafo.retornaLigacoes(candidato)
            for filho in filhos:
                avaliacao = grafo.avaliaVertice(filho, custo)
                if filho not in listaAbertos:
                    listaAbertos[filho] = avaliacao
                else:
                    if avaliacao < listaAbertos[filho]:
                        listaAbertos[filho] = avaliacao
    return sucesso, resposta