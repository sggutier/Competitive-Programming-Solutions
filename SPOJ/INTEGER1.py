#!/usr/bin/env python3

def calcPws(n):
    ans = [0]
    for i in range(1, 64):
        x = int(n ** (1 / i))
        x = max(x-100, 0)
        while x ** i <= n:
            x += 1
        x -= 1
        ans.append(x-1)
    tot = 0
    for i in range(64 - 1, 0, -1):
        for j in range(2*i, 64, i):
            ans[i] -= ans[j]
        tot += i * ans[i]
    return tot


def testCase(a, b):
    if b < a:
        a, b = b, a
    return calcPws(b) - calcPws(a-1)


def main():
    while True:
        a, b = [int(x) for x in input().split()]
        if a == 0:
            break
        print(testCase(a, b))


main()
