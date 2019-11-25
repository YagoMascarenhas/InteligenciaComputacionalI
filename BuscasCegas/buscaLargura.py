def buscaLargura(grafo, comeco, alvo):
    resposta = None
    filaAbertos = []
    filaAbertos.append(comeco)
    listaFechados = []
    sucesso = False

    print(comeco)
    while not sucesso and filaAbertos:
        candidato = filaAbertos.pop(0)
        listaFechados.append(candidato)
        filhos = grafo.retornaLigacoes(candidato)
        for filho in filhos:
            if filho in filaAbertos or filho in listaFechados:
                continue
            print(filho)
            if filho == alvo:
                sucesso = True
                resposta = filho
                break
            else:
                filaAbertos.append(filho)

    return sucesso, resposta