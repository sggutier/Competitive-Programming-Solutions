#!/usr/bin/env python3
from math import log

def testCase(a, b):
    tgt = b / log(a)
    eps = 1e-9
    ini, fin = 2, 10 ** 18
    while ini < fin:
        x = (ini + fin) // 2
        if x / log(x) + eps < tgt:
            ini = x + 1
        else:
            fin = x
    x = ini
    for i in range(max(2, x-30), min(x+30, 10 ** 18)+1):
        if abs(i / log(i) - tgt) < eps:
            return i
    return 0


def main():
    a, b = [int(x) for x in input().split()]
    print(testCase(a, b))


main()
