#!/usr/bin/env python3
from math import sqrt

movs = {'N': (1, 0), 'S': (-1, 0), 'E': (0, 1), 'W': (0, -1)}

def testCase(lin):
    lin = lin[:-1].split(',')
    r, c = 0, 0
    for inst in lin:
        dr, dc = 0, 0
        for i in range(1, 10000000):
            if inst[-i] not in movs:
                w = int(inst[:-i+1])
                break
            x, y = movs[inst[-i]]
            dr += x
            dc += y
        l = sqrt(dr * dr + dc * dc)
        r += dr * w / l
        c += dc * w / l
    return (c, r, sqrt(r*r + c*c))


def main():
    tc = 0
    while True:
        lin = input()
        if lin[0] == 'E':
            break
        tc += 1
        x, y, z = testCase(lin)
        print(f'Map #{tc}')
        print('The treasure is located at (%.3f,%.3f).' % (x, y))
        print('The distance to the treasure is %.3f.' % z)
        print()


main()
