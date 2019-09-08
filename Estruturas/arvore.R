#Define a estrutura de arvore para recursividade
Arvore <- setClass(
    "Arvore",
    contains = "list"
)

#Testa a validade do elemento
setValidity(
    "Arvore", 
    function(object){
        ok <- sapply(object, is, "Arvore")
        if(!all(ok)) {
            print("Elemento inválido")
        } else {
            TRUE
        }
    }
)

#Cria a classe Arvore
Arvore <- setClass(
    #Define o nome da classe
    "Arvore",

    #Define os valores iniciais e os possíveis filhos
    slots = c(
        x = "numeric",
        y = "numeric",
        #Os dois valores a seguir definem os filhos: o da direita e o da esquerda 
        #Abordagem de uma árvore binária aqui
        esquerda = "Arvore",
        direita = "Arvore"
    ),

    #Define os valores iniciais para os slots
    prototype = list(
        x = 0,
        y = 0,
        esquerda = NULL,
        direita = NULL
    )
)

#Cria uma árvore
setGeneric(
    name = "criaArvore",
    def = function(arvore, x, y, esquerda, direita) {
        standardGeneric("criaArvore")
    }
)

setMethod(
    f = "criaArvore",
    signature = "Arvore",
    definition = function(arvore, x, y, esquerda, direita) {
        arvore@x <- x
        arvore@y <- y
        
        #Testa se existe algum valor para a árvore da esquerda e atribui, se houver
        if(!is.null(esquerda)) {
            arvore@esquerda <- esquerda
        }

        #Testa se existe algum valor para a árvore da direita e atribui, se houver
        if(!is.null(direita)) {
            arvore@direita <- direita
        }

        return(arvore)
    }
)

#Expande os filhos da árvore recebida
setGeneric(
    name = "expandeArvore",
    def = function(arvore, listaAbertos, listaFechados) {
        standardGeneric("expandeArvore")
    }
)

setMethod(
    f = "expandeArvore",
    signature = "Arvore",
    definition = function(arvore, listaAbertos, listaFechados) {
        #A função elementoInedito testa se o elemento é inédito (ou seja, não está nem na lista de abertos, nem de fechados)
        #Retorna a listaRetorno com o elemento anexado se ele for inédito
        #Retorna a listaRetorno do jeito que está se ele não for inédito
        elementoInedito <- function(no, listaRetorno, listaAbertos, listaFechados){
            if(!(no %in% listaAbertos || no %in% listaFechados)){
                return(append(listaRetorno, no))
            } else {
                return(listaRetorno)
            }
        }
        #A listaRetorno armazena os possíveis filhos do nó candidato e os retorna ao fim da execução 
        listaRetorno <- vector()
        #Cria um objeto Arvore vazio para ser usado como temporário para armazenar os resultados
        no <- Arvore()

        #A partir daqui ele testa as regras e cria nós temporários para testar se a situação foi ou não visitada
        #Regra 1: se x < 3, então (3, y)
        if(arvore@x < 3) {
            no <- criaArvore(no, 3, arvore@y, NULL, NULL)
            #Testa se o elemento já apareceu em alguma lista
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 2: se y < 4, então (x, 4)
        if(arvore@y < 4) {
            no <- criaArvore(no, arvore@x, 4, NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 3: se x > 0, então (0, y)
        if(arvore@x > 0 ) {
            no <- criaArvore(no, 0, arvore@y, NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 4: se y > 0, então (x, 0)
        if(arvore@y > 0){
            no <- criaArvore(no, arvore@x, 0, NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 5: se y > 0 e x + y <= 3, então (x+y, 0)
        if((arvore@y > 0) && (arvore@x + arvore@y <= 3)) {
            no <- criaArvore(no, arvore@x + arvore@y, 0, NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 6: se y > 0 e x + y > 3, então (3, y - (3 - x))
        if((arvore@y > 0) && (arvore@x + arvore@y > 3)) {
            no <- criaArvore(no, 3, arvore@y - (3 - arvore@x), NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 7: se x > 0 e x + y <= 4, então (0, x + y)
        if((arvore@x > 0) && (arvore@x + arvore@y <= 4)){
            no <- criaArvore(no, 0, arvore@x + arvore@y, NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }
        #Regra 8: se x > 0 e x + y > 4, então (x - (4 - y), 4)
        if((arvore@x > 0) && (arvore@x + arvore@y > 4)){
            no <- criaArvore(no, arvore@x - (4 - arvore@y),4 , NULL, NULL)
            listaRetorno <- elementoInedito(arvore, listaRetorno, listaAbertos, listaFechados)
        }

        #Retorna o vetor com o(s) elemento(s) inédito(s) que será (ou serão) os filhos do nó testado
        return(listaRetorno)
    }
)