#!/usr/bin/env python3

def digs(nms):
    reps = [0 for i in range(10)]
    for x in nms:
        reps[x] += 1
    n = len(nms)
    fact = [1 for i in range(n+1)]
    tt = 0
    ans = 0
    for i in range(1, n+1):
        fact[i] = fact[i-1] * i
        tt += 10 ** (i-1)
    w = 1
    for i in range(10):
        w *= fact[reps[i]]
    for k in range(10):
        if reps[k] == 0:
            continue
        otr = fact[n - 1] // (w // fact[reps[k]] * fact[reps[k]-1])
        # print(otr)
        ans += otr * tt * k
    return ans


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        nums = [int(x) for x in input().split()]
        print(digs(nums))


main()
