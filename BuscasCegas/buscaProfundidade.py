def buscaProfundidade(grafo, comeco, alvo):
    resposta = None
    pilhaAbertos = []
    pilhaAbertos.append(comeco)
    listaFechados = []
    sucesso = False

    print(comeco)
    while not sucesso and pilhaAbertos:
        candidato = pilhaAbertos.pop()
        listaFechados.append(candidato)
        filhos = grafo.retornaLigacoes(candidato)
        tam = len(pilhaAbertos)
        for filho in filhos:
            if filho in pilhaAbertos or filho in listaFechados:
                continue
            print(filho)
            if filho == alvo:
                sucesso = True
                resposta = filho
                break
            else:
                pilhaAbertos.insert(tam, filho)

    return sucesso, resposta