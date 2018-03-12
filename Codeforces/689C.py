#!yolo
def ways(n):
    ans = 0
    k = 2
    while k*k*k<=n:
        ans += n//(k*k*k)
        k += 1
    return ans


def main():
    m = int(input())
    ini, fin = 0, 2**60
    while ini < fin:
        piv = (ini+fin)//2
        if ways(piv) < m:
            ini = piv+1
        else:
            fin = piv
    print(-1 if ways(ini)!=m else ini)


main()
