import math


def prec(n):
    n += 1
    ans = [0 for i in range(n)]
    ans[0] = 1
    for i in range(1, n):
        for j in range(0, i):
            ans[i] += ans[j]*ans[i-1-j]
    return ans


def main():
    ans = prec(1001)
    while True:
        try:
            n = int(input())
        except:
            break
        print(ans[n])


if __name__ == "__main__":
    main()
