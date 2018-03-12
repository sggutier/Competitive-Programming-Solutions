#!/usr/env/python3


def testCase(nums):
    tot = sum(nums)
    if(tot % 2 != 0):
        return False
    tot //= 2
    posb = [False for i in range(tot+1)]
    posb[0] = True
    for n in nums:
        for i in range(tot, n-1, -1):
            posb[i] |= posb[i-n]
    return posb[tot]


def main():
    tc = int(input())
    for i in range(tc):
        print("YES" if testCase([int(x) for x in input().split()]) else "NO")


if __name__ == "__main__":
    main()
