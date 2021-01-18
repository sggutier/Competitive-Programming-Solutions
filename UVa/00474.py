#!/usr/bin/env python3
from math import log10
from math import ceil


def testCase(n):
    p = log10(2) * n
    d = ceil(p) - p
    return '2^%d = %.3fe-%d' % (-n,10 ** d, int(ceil(p)))


def main():
    while True:
        try:
            n = int(input())
        except:
            break
        print(testCase(n))


# main()
