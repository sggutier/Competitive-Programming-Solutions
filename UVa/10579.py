#!/usr/env/python3


def precarga(n):
    global fibMem
    fibMem = [0 for i in range(n)]
    fibMem[0], fibMem[1], fibMem[2] = (1, 1, 1)
    for i in range(3, n):
        fibMem[i] = fibMem[i-1] + fibMem[i-2]


def main():
    global fibMem
    precarga(10000)
    while True:
        try:
            n = int(input())
            print(fibMem[n])
        except:
            break


main()
