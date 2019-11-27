def backtracking(grafo, comeco, alvo):
    resposta = None
    pilhaAbertos = []
    pilhaAbertos.append(comeco)
    listaFechados = []
    sucesso = False

    print(comeco)
    while not sucesso and pilhaAbertos:
        tam = len(pilhaAbertos)
        candidato = pilhaAbertos[tam - 1]
        filho = grafo.geraFilhoInedito(candidato, pilhaAbertos, listaFechados)
        if filho is None:
            candidato = pilhaAbertos.pop()
            listaFechados.append(candidato)
        else:
            print(filho)
            if filho == alvo:
                sucesso = True
                resposta = filho
            else:
                pilhaAbertos.append(filho)

    return sucesso, resposta