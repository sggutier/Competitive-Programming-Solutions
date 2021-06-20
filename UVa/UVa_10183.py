import math


def fib(n):
    global fibs
    if fibs[n]:
        return fibs[n]
    fibs[n] = fib(n-1) + fib(n-2)
    return fibs[n]


def buscaN(n):
    ini = 0
    fin = len(fibs)
    while ini < fin:
        piv = (ini + fin) // 2 + 1
        if fib(piv) > n:
            fin = piv-1
        else:
            ini = piv
    return ini


def main():
    global fibs
    fibs = [0 for i in range(1024)]
    fibs[0] = fibs[1] = 1
    while True:
        a, b = [int(x) for x in input().split()]
        if a == 0 and b == 0:
            break
        print(buscaN(b) - buscaN(a-1))


main()
