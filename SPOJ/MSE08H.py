import math


def calcDet(pos):
    global nums, divs, N
    if pos == N:
        return 1
    ans = 0
    sgn = 1
    for i in range(N):
        if usd[i]:
            continue
        usd[i] = True
        ans += sgn*math.gcd(divs[i], divs[pos])*calcDet(pos+1)
        usd[i] = False
        sgn *= -1
    return ans


def testCase(n):
    global usd, divs, N
    divs = []
    usd = []
    for i in range(1, n+1):
        if i*i >= n:
            if n % i == 0:
                divs.append(i)
                usd.append(False)
            break
        if n % i == 0:
            divs.append(i)
            divs.append(n // i)
            usd.append(False)
            usd.append(False)
    divs.sort()
    N = len(divs)
    if(N > 30):
        return -1
    return calcDet(0)


def main():
    n = int(input())
    for i in range(1, n+1):
        print("%3d => %d" % (i, testCase(i)))


