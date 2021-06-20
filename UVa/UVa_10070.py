#!/usr/env/python3


def testCase(n):
    leap = n % 400 == 0 or (n % 100 != 0 and n % 4 == 0)
    hulu = n % 15 == 0
    bulu = leap and n % 55 == 0
    if leap:
        print("This is leap year.")
    if hulu:
        print("This is huluculu festival year.")
    if bulu:
        print("This is bulukulu festival year.")
    if not leap and not hulu and not bulu:
        print("This is an ordinary year.")


def main():
    frst = True
    while True:
        try:
            n = int(input())
        except:
            break
        if not frst:
            print()
        frst = False
        testCase(n)


main()
