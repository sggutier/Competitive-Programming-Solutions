#!/usr/bin/env python3

def testCase(n):
    ans = []
    for i in range(9, -1, -1):
        if (n - i) % 9 == 0:
            x = (n-i) // 9
            ans.append(10 * x + i)
    return ans


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        print(' '.join([str(x) for x in testCase(n)]))


main()
