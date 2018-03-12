#!/usr/env python3


def dfs(pos):
    global usd, adj
    if usd[pos]:
        return 0
    usd[pos] = True
    ans = 1
    for sig in adj[pos]:
        ans += dfs(sig)
    return ans


def main():
    global usd, adj
    pot = 0
    a, b = [int(x) for x in input().split()]
    usd = [False for i in range(a)]
    adj = [[] for i in range(a)]
    for i in range(b):
        x, y = [int(x)-1 for x in input().split()]
        adj[x].append(y)
        adj[y].append(x)
    for i in range(a):
        pot += max(0, dfs(i)-1)
    print(2**pot)


main()
