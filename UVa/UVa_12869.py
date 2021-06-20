#!/usr/bin/env python3

def fZero(a, b):
    return b // 5 - a // 5 + 1


def main():
    while True:
        a, b = [int(x) for x in input().split()]
        if a == 0 and b == 0:
            break
        print(fZero(a, b))


main()
