#!/usr/bin/env python3
from math import gcd

def testCase(F, N, S):
    if S < N:
        return (0, F**N)
    if S > F*N:
        return (0, F**N)
    maxS = F*N + 1
    ans = [0 for i in range(maxS)]
    ans[0] = 1
    for i in range(1, N+1):
        for j in range(F*i, -1, -1):
            ans[j] = 0
            if j < i:
                continue
            for k in range(1, min(F, j)+1):
                ans[j] += ans[j-k]
    x = ans[S]
    y = F**N
    # g = gcd(x, y)
    # x, y = x // g, y // g
    return (x, y)


def main():
    while True:
        try:
            F, N, S = [int(x) for x in input().split()]
        except:
            break
        x, y = testCase(F, N, S)
        print(f'{x}/{y}')


main()
