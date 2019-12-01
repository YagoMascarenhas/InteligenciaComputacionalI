from experta import *

class Fatos(Fact):
    """Classificação de frutas"""
    pass

class Fruta(KnowledgeEngine):
    @Rule(Fatos(forma="longa"), Fatos(cor="amarela"))
    def regra1(self):
        print("A fruta é banana!")

    @Rule(Fatos(diametro="grande"), Fatos(forma="redonda"))
    def regra2(self):
        self.declare(Fatos(origem="parreira"))

    @Rule(Fatos(diametro="pequeno"), Fatos(forma="redonda"))
    def regra3(self):
        self.declare(Fatos(origem="arvore"))

    @Rule(Fatos(origem="parreira"), Fatos(cor="verde"))
    def regra4(self):
        print("A fruta é melancia!")

    @Rule(Fatos(origem="parreira"), Fatos(cor="amarela"))
    def regra5(self):
        print("A fruta é maracujá!")

    @Rule(Fatos(cor="laranja"), Fatos(forma="redonda"))
    def regra6(self):
        print("A fruta é laranja!")

    @Rule(Fatos(origem="arvore"), Fatos(cor="vermelha"))
    def regra7(self):
        print("A fruta é cereja!")

engine = Fruta()
engine.reset()
engine.declare(Fatos(forma="redonda"), Fatos(diametro="grande"), Fatos(cor="verde"))
engine.run()