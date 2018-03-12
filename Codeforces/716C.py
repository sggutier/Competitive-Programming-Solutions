import math


def solve_eq(a, lvl):
    lvl2 = (lvl+1)**2
    q = max(int(math.sqrt(a % lvl2)), 1)
    while(q*q*lvl2 < a):
        q += 1
    while((q*q*lvl2 - a) % lvl != 0):
        q += 1
    return (lvl+1)*q, int((q*q*lvl2 - a)/lvl)


def find_nums(n):
    a = 2
    for i in range(1, n+1):
        a, tmp = solve_eq(a, i)
        print(tmp)


find_nums(int(input()))
