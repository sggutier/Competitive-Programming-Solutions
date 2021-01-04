#!/usr/bin/env python3
import re


def unar(n):
    return len([x for x in n if x != '1']) == 0


def testCase(a, b, c):
    if unar(a) and unar(b) and unar(c) and len(a) + len(b) == len(c):
        return 1
    for i in range(2, 36):
        try:
            if int(a, i) + int(b, i) == int(c, i):
                return i
        except:
            pass
    return 0


def main():
    n = int(input())
    for i in range(n):
        a, b, c = re.split(r"[+ =]+", input())
        print(testCase(a, b, c))


main()
