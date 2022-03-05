import random
class UnoCards:
    def __init__(self,color,num):
      self.c = color
      self.n = num

    def __str__(self):
        return self.c + " " + str(self.n)
    def __repr__(self):
        return str(self)
class  CollectionofUnoCards:

    def __init__(self):
        self.l=[]

    def addCard (self,card):
            self.l.append(card)

    def __str__(self):

        col_str= ""

        for i in range(0,len(self.l)):
            col_str = col_str + " " +str (self.l[i])
                        
        return col_str

    def __repr__(self):
        return str(self)
    def shuffle(self):
        for i in range(350):
            a = random.randint(0,71)
            b = random.randint(0,71)
            self.l[a],self.l[b]=self.l[b],self.l[a]
    def makeDeck(self):

        for num in  range (1,10):
            for color in["Yellow","Red","Blue","Green"]:
                newcard = UnoCards(color,num)
                deck.addCard(newcard)
                deck.addCard(newcard)

    def getNumCards(self):
        return len(self.l)
    def getTopCard(self):
        return self.l[-1]
    def canPlay(self, c):
        if(self.c == c.c) or (self.n == c.n):
            return True
    def getCard(self, index):
        return self.l.pop()
class Player():

    def __init__(self):
        self.hand1 = [deck.getCard(i) for i in range(7)]
        self.hand2 = [deck.getCard(i) for i in range(7)]
        self.midCard = [] 
    def draw(self,deck):
        self.hand.append(deck.drawCard())

    def showHand(self):
        for card in self.hand:
            card.show()
    #def playGame():
        
    
        

deck = CollectionofUnoCards()
deck.makeDeck()
deck.shuffle()
hand = Player()
print(hand.hand1)
print(hand.hand2)
      
        
