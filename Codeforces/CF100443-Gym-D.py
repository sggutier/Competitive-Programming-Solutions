

def maxBt(n):
    ans = 0
    while n > 0:
        ans += 1
        n //= 2
    return ans


def simetr(l, r, p, n):
    global cad
    if l >= r:
        return True
    k = 1
    while p + k <= r and l <= p-k:
        if cad[p-k] == cad[p+k]:
            return False
        k += 1
    # print(f">> ran = {cad[l:r+1]}, l = {l}, r = {r}, p = {p}, n  t= {n}")
    if p-l > r-p:
        return fca(l, p-1, p - 2**n, n-1, 'L')
    else:
        return fca(p+1, r, p + 2**n, n-1, 'R')


def fca(l, r, p, n, rq):
    global cad
    if r < l:
        return True
    # print(f"ran = {cad[l:r+1]}, l = {l}, r = {r}, p = {p}, n  t= {n}, rq = {rq}")
    if p < l:
        return fca(l, r, p + 2**n, n-1, 'R')
    if r < p:
        return fca(l, r, p - 2**n, n-1, 'L')
    if cad[p] != rq:
        return False
    return simetr(l, r, p, n)


def pba(s, d):
    global cad
    cad = s
    n = len(s)
    for i in range(n):
        ml = maxBt(max(i, n-i-1))
        # print(f"i = {i}, ml = {ml}")
        if ml + 1 >= d and cad[i] != 'L':
            continue
        cont = 0
        for j in range(ml, d+1):
            if (cad[i] != 'R' or j+2 <= d) and simetr(0, n-1, i, j-1):
                return True
            cont += 1
            if cont >= 3:
                break
    return False


def main():
    tc = int(input())
    for i in range(tc):
        a, b = input().split()
        print(f"Case {i+1}: {'Yes' if pba(b, int(a)) else 'No'}")


main()
