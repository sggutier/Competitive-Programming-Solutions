#!/usr/bin/env python3
from math import exp
from math import log


def hum(t, d):
    e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(d+ 273.16))))
    f = (0.5555)* (e - 10.0)
    h = t + f
    return h


def tem(h, d):
    e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(d+ 273.16))))
    f = (0.5555)* (e - 10.0)
    t = h - f
    return t


def dew(t, h):
    f = h - t
    e = 10 + f / (0.5555)
    k = log(e / 6.11)
    r = (1/273.16) - k / 5417.7530
    d = 1 / r - 273.16
    return d


def main():
    while True:
        try:
            lin = input().split()
            t, d, h = None, None, None
            for i in range(0, 3, 2):
                if lin[i] == 'T':
                    t = float(lin[i+1])
                if lin[i] == 'D':
                    d = float(lin[i+1])
                if lin[i] == 'H':
                    h = float(lin[i+1])
            if h is None:
                h = hum(t, d)
            if t is None:
                t = tem(h, d)
            if d is None:
                d = dew(t, h)
            print('T %.1f D %.1f H %.1f' % (t, d, h))
        except:
            break


main()
