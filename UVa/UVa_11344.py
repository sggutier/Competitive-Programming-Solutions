#!/usr/bin/env python3


def testCase(M, nums):
    for n in nums:
        if M % n != 0:
            return False
    return True


def main():
    tc = int(input())
    for i in range(tc):
        M = int(input())
        nums = [int(x) for x in input().split()[1:]]
        print(str(M) + " - " +
              ("Wonderful." if testCase(M, nums) else "Simple."))


if __name__ == "__main__":
    main()
