#!/usr/bin/python3


def evalPoly(coefs, x):
    pot = 1
    ans = 0
    for c in coefs:
        ans += pot*c
        pot *= x
    return ans


def testCase(coefs, xs):
    coefs = coefs[-2::-1]
    n = len(coefs)
    for i in range(n):
        coefs[i] = (i+1)*coefs[i]
    return [evalPoly(coefs, x) for x in xs]


def main():
    while True:
        try:
            b = [int(x) for x in input().split()]
            a = [int(x) for x in input().split()]
        except:
            break
        ans = testCase(a, b)
        n = len(ans)
        for i in range(n):
            print(ans[i], end=(' ' if i != n - 1 else '\n'))


main()
