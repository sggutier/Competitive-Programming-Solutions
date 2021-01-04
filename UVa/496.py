#!/usr/bin/env python3


def testCase(a, b):
    a = set(a)
    b = set(b)
    if a == b:
        return 'A equals B'
    if a.isdisjoint(b):
        return 'A and B are disjoint'
    if a.issubset(b):
        return 'A is a proper subset of B'
    if b.issubset(a):
        return 'B is a proper subset of A'
    return "I'm confused!"


def main():
    while True:
        try:
            a = [int(x) for x in input().split()]
            b = [int(x) for x in input().split()]
            print(testCase(a, b))
        except:
            break


main()
