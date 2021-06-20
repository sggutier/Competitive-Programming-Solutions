#!/usr/env/python3
import math


maxN = 25 #int(1e5)
facts = [0 for i in range(maxN)]
sums = [0 for i in range(maxN)]


def precarga():
    global facts, sums
    facts = [1 for i in range(maxN)]
    sums = [0 for i in range(maxN)]
    for i in range(1, maxN):
        facts[i] = i*facts[i-1]
        sums[i] = i*sums[i-1] + facts[i-1]*((i*(i-1))//2)


def testCase(n):
    d = math.gcd(facts[n], sums[n])
    x, y = (sums[n], facts[n])
    if (y//d) % 2 == 1:
        x *= 2
        y *= 2
    return (x//d, y//d)
