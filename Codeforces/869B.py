#!/usr/env/python3


def main():
    a, b = [int(x) for x in input().split()]
    ans = 1
    for i in range(1, 11):
        if i+a > b:
            break
        ans = (ans * (i + a)) % 10
    print(ans)


main()
