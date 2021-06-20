#!/usr/bin/env python3


def gauss(n):
    return (n * (n+1)) // 2


def testCase(n, m):
    return gauss(m-1) - gauss(m-n-1)


def main():
    n = int(input())
    for i in range(n):
        a, b = [int(x) for x in input().split()]
        print(testCase(a, b))


main()
