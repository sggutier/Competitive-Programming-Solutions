#!/usr/bin/env python3


def neinSum(n):
    return sum([int(x) for x in str(n)])


def testCase(n):
    if n % 9 != 0:
        return "{} is not a multiple of 9.".format(n)
    deg = 0
    norg = n
    if n == 9:
        deg = 1
    while n > 9:
        n = neinSum(n)
        deg += 1
    return "{} is a multiple of 9 and has 9-degree {}.".format(norg, deg)


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        print(testCase(n))


if __name__ == "__main__":
    main()
