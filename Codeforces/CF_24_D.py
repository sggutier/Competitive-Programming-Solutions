#!/usr/bin/env python3

def calcProbs(r, c, s=0, p=1.0):
    global matr
    if s > 35:
        return
    matr[r][c] += s*p
    if r == 0:
        return
    if c == 0:
        calcProbs(r, c+1, s+1, p*0.5)
        calcProbs(r-1, c, s+1, p*0.5)
    elif c + 1 == len(matr[0]):
        calcProbs(r, c-1, s+1, p*0.5)
        calcProbs(r-1, c, s+1, p*0.5)
    else:
        calcProbs(r, c-1, s+1, p/3)
        calcProbs(r, c+1, s+1, p/3)
        calcProbs(r-1, c, s+1, p/3)
