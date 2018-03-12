import math


def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    stro = "abcdefghijklmnopqrstuvwxyz"
    for a in arr:
        print(stro[a], end='')
        stro = stro[a] + stro[:a] + stro[a+1:]
        #print(stro)
    print()


main()
import math


def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    stro = "abcdefghijklmnopqrstuvwxyz"
    for a in arr:
        print(stro[a], end='')
        stro = stro[a] + stro[:a] + stro[a+1:]
        #print(stro)
    print()


main()
