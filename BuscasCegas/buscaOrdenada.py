def buscaOrdenada(grafo, comeco, alvo):
    resposta = None
    listaAbertos = {comeco: 0}
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
                if filho in listaFechados:
                    continue
                listaAbertos[filho] = filhos[filho] + custo
    return sucesso, resposta