import math


def main():
    a, b = [int(x) for x in input().split()]
    print(math.factorial(min(a, b)))

   
main()
