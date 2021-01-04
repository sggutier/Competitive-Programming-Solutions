#!/usr/bin/env python3

MAX_N = 2**64 -1


def getPows(p):
    i = 2
    ans = set()
    while i ** p <= MAX_N:
        ans.add(i ** p)
        i += 1
    return ans


def main():
    ans = {1}
    for i in range(4, 64):
        comp = False
        for j in range(2, i):
            if i % j == 0:
                comp = True
                break
        if comp:
            ans = ans.union(getPows(i))
    ans = [x for x in ans]
    ans.sort()
    for x in ans:
        print(x)


main()
