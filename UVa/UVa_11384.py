#!/usr/bin/env python3


def testCase(n):
    if n <= 1:
        return n
    return testCase(n // 2) + 1


def main():
    while True:
        try:
            print(testCase(int(input())))
        except:
            break


main()
