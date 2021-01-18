#!/usr/bin/env python3
from math import log
from math import exp


def calcProbA(nms):
    n = len(nms)
    ans = [i*i for i in range(n+1)]
    print(ans)
    print(ans[0], sum(ans[1:]))
    for i in range(1, n+1):
        p = nms[i-1]
        nxt = [0 for i in range(n+1-i)]
        for j in range(n+1-i):
            nxt[j] = (ans[0] + j*j) * (1-p) + ans[j+1] * p
        ans = nxt
        print(ans)
        print(ans[0], sum(ans[1:]))
        print(sum(ans))
    return ans[0]


def calcProbB(nms):
    n = len(nms)
    nms = [0] + nms
    logs = [0 for i in range(n+1)]
    for i in range(1, n+1):
        logs[i] = log(nms[i]) + logs[i-1]
    ans = [0]
    for i in range(1, n+1):
        nxt = [0 for i in range(i+1)]
        for j in range(0, i):
            nxt[0] += exp(logs[i-1] - logs[i-j-1]) * (1 - nms[i-j-1]) * ans[j]
        for j in range(1, i+1):
            nxt[j] = ans[j-1] + (2*j - 1)
        ans = nxt
        print([ans[j] - j*j for j in range(i+1)])
        print(ans[0], sum(ans[1:]))
    tt = 0
    for i in range(0, n+1):
        tt += exp(logs[n] - logs[n-i]) * (1 - nms[n-i]) * ans[i]
    return tt


def calcProbC(nms):
    n = len(nms)
    nms = [0] + nms
    logs = [0 for i in range(n+1)]
    for i in range(1, n+1):
        logs[i] = log(nms[i]) + logs[i-1]
    ans = [0]
    for i in range(1, n+1):
        nxt = 0
        w = []
        for j in range(0, i):
            nxt += exp(logs[i-1] - logs[i-j-1]) * (1 - nms[i-j-1]) * (ans[j] + j*j)
            w.append(exp(logs[i-1] - logs[i-j-1]) * (1 - nms[i-j-1]) * (ans[j] + j*j))
        print(w)
        print(1 - nms[i])
        print()
        ans = [nxt] + ans
        print(ans)
    tt = 0
    w = []
    for i in range(0, n+1):
        tt += exp(logs[n] - logs[n-i]) * (1 - nms[n-i]) * (ans[i] + i*i)
        w.append(exp(logs[n] - logs[n-i]) * (1 - nms[n-i]) * (ans[i] + i*i))
    print(w)
    return tt


def calcProbD(nms):
    n = len(nms)
    nms = [0] + nms
    ans = 0
    x = 0
    z = 0
    r = 0
    for i in range(1, n+1):
        p = nms[i]
        x = (1-r) + (x + z) * r
        z = 2*(1-r) + z*r
        ans += p * x
        print(ans, x, z)
        r = p
    return ans
