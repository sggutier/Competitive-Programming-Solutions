#!/usr/bin/env python3
import re

def sylCnt(lin):
    return len([x for x in re.split('[^aeiouy]', lin) if len(x) > 0])


def testCase(lin):
    lin = lin.split('/')
    expt = [5, 7, 5]
    for i in range(3):
        if sylCnt(lin[i]) != expt[i]:
            return i + 1
    return 'Y'


def main():
    while True:
        try:
            lin = input()
        except:
            break
        if lin == 'e/o/i':
            break
        print(testCase(lin))


main()
