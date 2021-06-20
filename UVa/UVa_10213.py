#!/usr/env/python3
import math


def count(n, k):
    if k > n:
        return 0
    if n < 10:
        return math.factorial(n) // (math.factorial(k) * math.factorial(n-k))
    ans = 1
    for i in range(k):
        ans = (ans*(n-i))//(i+1)
    return ans


def calcArs(n):
    return count(n, 4) + count(n, 2) + 1


def main():
    tc = int(input())
    for i in range(tc):
        print(calcArs(int(input())))


main()
