#!/usr/bin/env python3

mod = int(1e9 + 7)

def pot2(n):
    if n == 0:
        return 1
    mit = pot2(n >> 1)
    if n & 1 == 1:
        return (mit * mit * 2) % mod
    return (mit * mit) % mod


def main():
    a, b, c = [int(x) for x in input().split()]
    if c == -1 and (b % 2 != a % 2):
        print(0)
        return
    print(pot2((a-1) * (b-1)))


main()
