#!/usr/bin/env python3

def zeroCntS(n):
    ans = 0 if n != 0 else 1
    while n > 0:
        ans += 1 if n % 10 == 0 else 0
        n //= 10
    return ans


def cuenta0s(a, b):
    ans = 0
    for i in range(a, b+1):
        ans += zeroCntS(i)
    return ans


def calcDigs(n):
    pv = 1
    for i in range(n):
        pv += 9*(i+1)*10**i
    return pv


def calc0s(d):
    if d == -1:
        return 0
    d = str(d)
    rem = len(d) -1
    ans = calcDigs(rem-1) + (int(d[0])-1) * rem * 10 ** (rem-1)
    zs = 0
    while rem > 0:
        rem -= 1
        d = d[1:]
        if d[0] == '0':
            zs += 1
        else:
            x = int(d[0])
            ans += 10 ** rem
            ans += zs * x * 10 ** rem
            ans += x * rem * 10 ** (rem-1)
    ans += zs
    return int(ans)


def testCase(a, b):
    return calc0s(b) - calc0s(a-1)


def main():
    while True:
        a, b = [int(x) for x in input().split()]
        if a == -1:
            break
        print(testCase(a, b))


main()
