#!/usr/bin/env python3
from math import sqrt


maxN = 92700


def calcD(n):
    if n == 0:
        return (2, 2)
    if n % 4 == 2:
        return None
    if n % 2 == 1:
        k = (n-1) // 2
        return (k+1, k)
    k = n // 4
    return (k+1, k-1)


def calcRng(x, y):
    if y < x:
        x, y = y, x
    # print(x, y)
    ans = 0
    while y % 4 != 3 and y >= x:
        if y % 4 == 2:
            ans += 1
        y -= 1
    while x % 4 != 0 and x <= y:
        if x % 4 == 2:
            ans += 1
        x += 1
    if x < y:
        ans += (y+1-x) // 4
    return ans


def testCase(nms):
    # print(nms)
    if len(nms) == 1:
        n = nms[0]
        rd = calcD(abs(n))
        if rd is None:
            print('Spinster' if n % 2 == 1 else 'Bachelor', 'Number.')
        else:
            x, y = rd
            if n < 0:
                x, y = y, x
            print(x, y)
    else:
        print(calcRng(nms[0], nms[1]))


def main():
    while True:
        try:
            nms = [int(x) for x in input().split()]
        except:
            break
        testCase(nms)


main()
