#!/usr/bin/env python3

def cnts(n):
    a, b = 0, 0
    while n > 0:
        if n & 1:
            a += 1
        else:
            b += 1
        n >>= 1
    return a, b


def getDifs(n):
    v = cnts(n)
    sm = v[0] + v[1] + 1
    reps = [None for i in range(sm)]
    for i in range(0, n+1):
        x = cnts(i)
        if x != v:
            continue
        y = cnts(n-i)
        reps[y[0]] = i
    for i in range(sm):
        if reps[i]:
            print(bin(n), bin(reps[i]), bin(n-reps[i]), i)
