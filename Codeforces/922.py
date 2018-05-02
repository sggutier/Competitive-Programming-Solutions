import math


def testCase(n, k):
    k = min(k, 100)
    for i in range(2, k+1):
        r = n % i
        for j in range(1, i):
            if n % j == r:
                return False
    return True


def main():
    n, k = [int(x) for x in input().split()]
    print("Yes" if testCase(n, k) else "No")


main()
