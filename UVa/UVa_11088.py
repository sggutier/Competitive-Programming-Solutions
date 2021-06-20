#!/usr/bin/env python3


def testCase(n, nums):
    return min(len(list(filter(lambda x: x >= 20, nums))), n//3)


def main():
    for i in range(1, 105):
        n = int(input())
        if n == 0:
            break
        a = [int(x) for x in input().split()]
        print("Case " + str(i) + ": " + str(testCase(n, a)))


if __name__ == "__main__":
    main()
