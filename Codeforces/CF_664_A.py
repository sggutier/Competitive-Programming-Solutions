import math


def main():
    a, b = [int(x) for x in input().split()]
    g = a
    while a <= b and g > 1:
        g = math.gcd(a, g)
        a += 1
    print(g)


main()
