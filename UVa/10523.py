#!/usr/bin/env python3


def testCase(n, a):
    return sum([i*(a**i) for i in range(1, n+1)])


def main():
    while True:
        try:
            n, a = [int(x) for x in input().split()]
            print(testCase(n, a))
        except EOFError:
            break


if __name__ == "__main__":
    main()
