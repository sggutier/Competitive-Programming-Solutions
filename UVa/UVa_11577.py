#!/usr/env/python3


def testCase(line):
    dict = {}
    maxRep = 0
    for c in line:
        if c == ' ':
            continue
        if dict.get(c) is None:
            dict[c] = 0
        dict[c] += 1
        maxRep = max(maxRep, dict[c])
    ans = []
    for k, v in dict.items():
        if v == maxRep:
            ans.append(k)
    ans.sort()
    print(''.join(ans))


def main():
    n = int(input())
    for i in range(n):
        testCase(input().lower())


if __name__ == "__main__":
    main()
