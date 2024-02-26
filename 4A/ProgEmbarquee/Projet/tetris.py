# -*- coding: utf-8 -*-

import os
import platform

class Tetris:

    def __init__(self):
        self.table = [[0] * 96 for _ in range(64)]
        self.table[0] = [1]* 96                         #draw the first line
        self.table[63] = [1]* 96                        #draw the last line
        self.table[61] = [1]* 96                        #draw the last line

        for i in range(64):
            for j in range(96):
                if j == 0 or j == 41 or j == 54 or j == 95:
                    self.table[i][j] = 1

    def start(self):
        os.system('cls')

    def display(self):
        if platform.system() == 'Windows':
            os.system('cls')
        else:
            os.system('clear')

        for line in self.table:
            print(line)
