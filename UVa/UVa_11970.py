#!/usr/bin/env python3


def testCase(n):
    ans = []
    y = 1
    while y*y < n:
        x = n-y*y
        if x % y == 0:
            ans.append(x)
        y += 1
    return ans


def main():
    n = int(input())
    for i in range(1, n+1):
        ans = testCase(int(input()))
        ans.reverse()
        print(f'Case {i}: ' + ' '.join([str(x) for x in ans]))


main()
