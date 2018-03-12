#!/usr/env/python3


def main():
    fibo = [1 for i in range(1002)]
    for i in range(2, 1002):
        fibo[i] = fibo[i-2] + fibo[i-1]
    while True:
        try:
            n = int(input())
            print(fibo[n+1])
        except:
            break


main()
