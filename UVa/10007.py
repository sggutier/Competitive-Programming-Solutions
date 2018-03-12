import math


def prec(n):
    n += 1
    ans = [0 for i in range(n)]
    ans[0] = 1
    for i in range(1, n):
        for j in range(0, i):
            ans[i] += ans[j]*ans[i-1-j]
    for i in range(1, n):
        ans[i] *= math.factorial(i)
    return ans


def main():
    ans = prec(300)
    while True:
        n = int(input())
        if n == 0:
            break
        print(ans[n])


if __name__ == "__main__":
    main()
