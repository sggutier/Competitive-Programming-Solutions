#!/usr/bin/env python3

base = '''*****
*....
*****
....*
*****
.....
.***.
*...*
*****
*...*
*...*
.....
*...*
*...*
*...*
.*.*.
..*..
.....
*****
*....
***..
*....
*****
.....
*...*
*...*
*****
*...*
*...*
.....
*****
*...*
*****
*.*..
*..**
.....
*****
..*..
..*..
..*..
*****
.....
***..
*..*.
*...*
*..*.
***..
.....
*****
*...*
*...*
*...*
*****
.....
*...*
.*.*.
..*..
..*..
..*..
.....
'''.split()
base = [[base[j + i] for j in range(5)] for i in range(0, len(base), 6)]
A, B = 4, 10
L = 5


def printHor(s):
    for row in range(L):
        for vz in range(s):
            for numLet in range(B):
                if numLet == A:
                    print('.'*2*s, end='')
                if numLet > 0:
                    print('.'*s, end='')
                for cr in base[numLet][row]:
                    print(cr * s, end='')
            print()


def printVer(s):
    for numLet in range(B):
        if numLet == A:
            for hz in range(s):
                print('.....'*s)
                print('.....'*s)
        if numLet > 0:
            for hz in range(s):
                print('.....'*s)
        for row in range(L):
            for vz in range(s):
                for cr in base[numLet][row]:
                    print(cr * s, end='')
                print()


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        if n < 0:
            printVer(-n)
        else:
            printHor(n)
        print()
        print()


main()
