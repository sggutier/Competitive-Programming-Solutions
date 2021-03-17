#!/usr/bin/env python3

def simul(pos, n, maxN = 1e6):
    if n == 1:
        return pos
    pos = simul(pos, n-1, maxN)
    subp = (pos + n - 1) % n
    return min(pos - pos % n + subp, maxN)


def pm(n, k = None):
    if k is None:
        k = n
    ans = [0 for i in range(n)]
    for i in range(n):
        pos = simul(i, k, n-1)
        ans[pos] = i + 1
    return ans
