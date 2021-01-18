#!/usr/bin/env python3

def printS(s, tgt):
    print((tgt - len(s)) * ' ' + s)


def testCase(sx, sy):
    maxLen = max(len(sx), len(sy))
    x, y = [int(a, 2) for a in [sx, sy]]
    z = x*y
    sz = '{0:b}'.format(z)
    maxLenMt = maxLen
    maxLen = max(maxLen, len(sz))
    printS(sx, maxLen)
    printS(sy, maxLen)
    printS('-' * maxLenMt, maxLen)
    for i in range(len(sy)):
        tgt = maxLen - i
        if sy[-i-1] == '0':
            printS('0' * len(sx), tgt)
        else:
            printS(sx, tgt)
    print('-' * maxLen)
    printS(sz, maxLen)


def main():
    bkn = False
    while True:
        x, y = input().split()
        if x == '0' and y == '0':
            break
        if bkn:
            print()
        bkn = True
        testCase(x, y)


main()
