#!/usr/bin/env python3

def testCase(a, b, c, d, e):
    return a*b*c*d*d*e*e


def main():
    while True:
        nums = [int(x) for x in input().split()]
        if nums[0] == 0:
            break
        print(testCase(*nums))


main()
