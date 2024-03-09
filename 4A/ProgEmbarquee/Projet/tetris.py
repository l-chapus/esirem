# -*- coding: utf-8 -*-

class Tetris:

    def __init__(self, lenghX, lenghY):
        self.table = [[0] * lenghX for _ in range(lenghY)]
        self.activePiece = [0,0]        #coordonné du coin inférieur gauche de la pièce active
        self.typePiece = 2

    def getTableXY(self, coordX,coordY):
        return self.table[coordX][coordY]
    
    def start(self):    #place un caré tout en haut et au centre de la zone de jeu
        for i in range(4):
            for j in range(4):
                self.table[i][18+j] = 2
        
        self.activePiece = [3,18]
        self.typePiece = 2
    
    def update(self):
        if self.activePiece[0] >= 59 or self.activePiece[1] >= 39 or self.table[self.activePiece[0] + 1][self.activePiece[1]] != 0 or self.table[self.activePiece[0] + 1][self.activePiece[1] + 2] != 0:
            #génère une nouvelle pièce
            self.newPiece()

        else:
            if self.typePiece == 2:
                for i in range(2):
                    for j in range(4):
                        self.table[self.activePiece[0] + i - 3][self.activePiece[1] + j] = 0
                        self.table[self.activePiece[0] + i + 1][self.activePiece[1] + j] = 2
                
                self.activePiece[0] = self.activePiece[0] + 2
           
    def newPiece(self):
        self.activePiece = [3,18]
        self.typePiece = 2

        for i in range(4):
            for j in range(4):
                self.table[i][self.activePiece[1] + j] = 2