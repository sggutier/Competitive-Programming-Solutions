#!/usr/bin/env python3

def max9s(n):
    for i in range(10, 0, -1):
        if n + (n-1) >= 10 ** i - 1:
            return i
    return 0


def calcNums(tgt, n):
    # print(tgt)
    iniP = max(1, tgt - n)
    ini, fin = iniP, min(tgt, n) - 1
    while ini < fin:
        piv = (ini + fin) // 2 + 1
        if tgt - piv >= piv + 1:
            ini = piv
        else:
            fin = piv - 1
    if fin < ini or 2 * ini + 1 > tgt:
        return 0
    # print(iniP, ini, fin)
    return ini - iniP + 1


def testCase(n):
    ncs = max9s(n)
    ans = 0
    for i in range(10):
        ans += calcNums((i+1) * 10 ** ncs - 1, n)
    return ans


print(testCase(int(input())))
