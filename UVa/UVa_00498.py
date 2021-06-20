#!/usr/bin/python3


def evalPoly(coefs, x):
    pot = 1
    ans = 0
    for c in coefs:
        ans += pot*c
        pot *= x
    return ans


def testCase(coefs, xs):
    coefs = coefs[::-1]
    return [evalPoly(coefs, x) for x in xs]


def main():
    while True:
        try:
            a = [int(x) for x in input().split()]
            b = [int(x) for x in input().split()]
        except:
            break
        ans = testCase(a, b)
        n = len(ans)
        for i in range(n):
            print(ans[i], end=(' ' if i != n - 1 else '\n'))


main()
