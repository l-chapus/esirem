# -*- coding: utf-8 -*-

import os
import platform

class Tetris:

    def __init__(self, lenghX, lenghY):
        self.table = [[6] * lenghX for _ in range(lenghY)]

    def getTableXY(self, coordX,coordY):
        return self.table[coordX][coordY]
