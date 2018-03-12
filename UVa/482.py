#!/usr/bin/env python3


def testCase():
    # input()
    nums = [int(x) for x in input().split()]
    revs = input().split()
    ans = revs.copy()
    for a, b in zip(nums, revs):
        ans[a-1] = b
    for a in ans:
        print(a)


def main():
    tc = int(input())
    for i in range(tc):
        if i > 0:
            print()
        input()
        testCase()


main()
