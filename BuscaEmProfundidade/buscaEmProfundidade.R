source("Estruturas\\arvore.R")

#buscaProfundidade recebe, por parâmetro, o estado inicial
buscaProfundidade <- function(arvore) {
    #Cria os valores iniciais para a execução
    resposta <- NULL
    #Define pilhaAbertos como um vetor vazio e depois anexa o estado inicial
    pilhaAbertos <- vector()
    pilhaAbertos <- append(pilhaAbertos, arvore, after = length(pilhaAbertos))
    listaFechados <- vector() #Define a lista de fechados como um vetor vazio
    sucesso <- FALSE

    while((!sucesso) && (length(pilhaAbertos) != 0)) {
        #O nó candidato recebe o elemento do topo da pilha de abertos (último elemento)
        noCandidato <- pilhaAbertos[length(pilhaAbertos)]
        #Remove o elemento do topo da pilha de abertos (último elemento)
        pilhaAbertos <- pilhaAbertos[-length(pilhaAbertos)]
        #Insere na lista de fechados
        listaFechados <- append(listaFechados, noCandidato)

        #Expandindo nó candidato
        filhos <- expandeArvore(noCandidato, pilhaAbertos, listaFechados)

        #Verifica se existe filhos
        if(length(filhos) == 0) next

        #Se existirem filhos, testa se algum deles é a solução e o recebe
        resposta <- testaSolucao(filhos)

        #Se a resposta for nula, ou seja, nenhum deles é a solução, insere eles na pilha de abertos
        if(is.null(resposta)) {
            pilhaAbertos <- append(pilhaAbertos, filhos[1], after = length(pilhaAbertos))

            #Se houver um segundo elemento, coloca ele também na pilha de abertos
            if(length(filhos) == 2) {
                pilhaAbertos <- append(pilhaAbertos, filhos[2], after = length(pilhaAbertos))
            }
        } else {
            #Se um dos filhos for a solução
            sucesso <- TRUE
            resultado <- list(
                "sucesso" = sucesso,
                "resposta" = resposta            
            )
            return(resultado)
        }
    }
}

#Cria o estado inicial, sem filhos e com (x, y) = (0, 0)
arvore <- Arvore()
#Cria uma lista resultado que receberá o retorno da busca em profundidade
resultado <- list(
    "sucesso" = FALSE,
    "resposta" = NULL
)
#Atribui o retorno da busca ao resultado
resultado <- buscaProfundidade(arvore)
#Imprime o resultado
resultado