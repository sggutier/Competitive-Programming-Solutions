#!/usr/bin/env python3

def getDig(n):
    n -= 1
    digs = 1
    while n >= digs*9*10**(digs-1):
        n -= digs*9*10**(digs-1)
        digs += 1
    pos = n // digs + 10**(digs-1)
    return str(pos)[n % digs]


def main():
    while True:
        try:
            n = int(input())
        except:
            break
        print(getDig(n))


main()
