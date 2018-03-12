#!/usr/env/python3


def precarga():
    global ways
    ways = [0 for i in range(2001)]
    ways[0] = 1
    for i in range(1, 2001):
        for j in range(1, i+1):
            ways[i] += ways[i-j]*j


def main():
    global ways
    precarga()
    while True:
        n = int(input())
        if n == 0:
            break
        print(ways[n])


main()
