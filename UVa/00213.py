#!/usr/bin/env python3

def testCase(base):
    n = len(base)
    pos = 0
    buf = ''
    curL = -1
    while curL != 0:
        k = 3 if curL == -1 else curL
        while pos + k > len(buf):
            buf += input()
        if curL == -1:
            curL = int(buf[pos : pos+k], 2)
        else:
            x = int(buf[pos : pos+k], 2)
            if x == (1 << curL) - 1:
                curL = -1
            else:
                print(base[(1 << curL) - (curL + 1) + x], end='')
        pos += k
    print()


def main():
    while True:
        try:
            lin = input()
        except:
            break
        testCase(lin)


main()
