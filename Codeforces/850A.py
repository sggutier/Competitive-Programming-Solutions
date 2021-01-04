#!/usr/bin/env python3

def ip(x, y):
    return sum([a*b for a, b in zip(x,y)])


def dif(a, b):
    return [b-a for a, b in zip(a, b)]


def calcAng(a, b, c):
    return ip(dif(a, b), dif(a, c))


def testCase(pts):
    n = len(pts)
    if n > 35:
        return []
    ans = []
    for i in range(n):
        acs = 0
        for j in range(n):
            for k in range(n):
                if i == j or j == k or i == k:
                    continue
                if calcAng(pts[i], pts[j], pts[k]) > 0:
                    acs += 1
        if acs == 0:
            ans.append(i)
    return ans


def main():
    n = int(input())
    pts = []
    for i in range(n):
        pts.append([int(x) for x in input().split()])
    ans = testCase(pts)
    print(len(ans))
    for x in ans:
        print(x+1)


main()
