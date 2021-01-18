#!/usr/bin/env python3

def testCase():
    n, b = [int(x) for x in input().split()]
    ans = 0
    for i in range(b):
        x = [int(x) for x in input().split()][1:]
        p = 1
        for k in x:
            p = (p * k) % n
        ans = (ans + p) % n
    print(ans)


def main():
    tc = int(input())
    for i in range(tc):
        testCase()


main()
