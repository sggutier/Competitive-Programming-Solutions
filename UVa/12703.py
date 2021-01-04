

def factor(n):
    ans = dict()
    for i in range(2, n+1):
        if n % i != 0:
            continue
        cnt = 0
        while n % i == 0:
            n //= i
            cnt += 1
        ans[i] = cnt
    return ans


def acm(da, db):
    dc = dict(da)
    for k, v in db.items():
        if k not in dc:
            dc[k] = 0
        dc[k] += v
    return dc


def fct(a, b, n):
    a = factor(a)
    b = factor(b)
    for i in range(1, n):
        c = acm(a, b)
        a = b
        b = c
    return sorted(c.items())


def main():
    tc = int(input())
    for i in range(tc):
        n, a, b = [int(x) for x in input().split()]
        first = False
        for x, y in fct(a, b, n):
            print(x, y)
        print()


main()
