# -*- coding: utf-8 -*-

import os
import platform
from tetris import Tetris

class Application:
    def __init__(self):
        self.table = [[0] * 96 for _ in range(64)]
        self.table[0] = [1]* 96                         #draw the first line
        self.table[63] = [1]* 96                        #draw the last line
        self.table[61] = [1]* 96                        #draw the last line

        for i in range(64):
            for j in range(96):
                if j == 0 or j == 41 or j == 54 or j == 95:
                    self.table[i][j] = 1

        self.player1Table = Tetris(40,60)
        self.player2Table = Tetris(40,60)

    def start(self):
        os.system('cls')

    def displayTerminal(self):
        if platform.system() == 'Windows':
            os.system('cls')
        else:
            os.system('clear')

        for i in range(64): 
            for j in range(96):
                if i>0 and i<61 and j>0 and j<41:
                    print(self.player1Table.getTableXY(i-1,j-1), end='')
                elif i>0 and i<61 and j>54 and j<95:
                    print(self.player2Table.getTableXY(i-1,j-55), end='')
                else:
                    print(self.table[i][j], end='')
            
            print("")

    def update(self):
        self.displayTerminal()