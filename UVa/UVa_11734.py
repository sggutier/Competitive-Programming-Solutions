#!/usr/bin/env python3


def testCase(cont, judge):
    if cont == judge:
        return "Yes"
    elif ''.join(cont.split()) == judge:
        return "Output Format Error"
    else:
        return "Wrong Answer"


def main():
    tc = int(input())
    for i in range(1, tc+1):
        a, b = (input(), input())
        print("Case " + str(i) + ": " + testCase(a, b))


if __name__ == "__main__":
    main()
