#!/usr/bin/env python3
from math import log10

def calcElo(RA, RB):
    return 1 / (1 + 10 ** ((RB - RA) / 400))
