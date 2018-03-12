#!/usr/env/python3

mod = 10**16 + 7


def binExp(n, k):
    if k == 0:
        return 1
    mit = binExp(n, k//2)
    if k % 2 == 0:
        return (mit*mit) % mod
    else:
        return (mit*mit*n) % mod


def testCase(n, m):
    tot = n*m
    n, m = (tot//2, tot-tot//2)
    return (binExp(n, m-1)*binExp(m, n-1)) % mod


def main():
    tc = int(input())
    for i in range(tc):
        print(testCase(*[int(x) for x in input().split()]))


main()
