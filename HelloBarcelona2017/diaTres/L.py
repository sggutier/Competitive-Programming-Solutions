import math

class Frac:
    def __init__(self, a=0, b=1):
        c = math.gcd(a, b)
        self.num = a//c
        self.den = b//c
    def __add__(self, otr):
        return Frac(self.num*otr.den + otr.num*self.den, self.den*otr.den)
    def __sub__(self, otr):
        return Frac(self.num*otr.den - otr.num*self.den, self.den*otr.den)
    def __mul__(self, otr):
        return Frac(self.num*otr.num, self.den*otr.den)


def jogo(n, m):
    global dpMemo, usd
    if(usd[n][m]):
        return dpMemo[n][m]
    usd[n][m] = True
    if m==0:
        dpMemo[n][m] = Frac(0, 1);
    else:
        dpMemo[n][m] = Frac(m,n+m)*(Frac(1,1) - jogo(n, m-1))
    return dpMemo[n][m]


def main():
    global usd, dpMemo
    usd = [[False for x in range(65)] for y in range(65)]
    dpMemo = [[Frac() for x in range(65)] for y in range(65)]
    tc = int(input())
    for i in range(tc):
        nums = [int(x) for x in input().split()]
        ans = Frac(1, 1) - jogo(nums[0], nums[1])
        print("%d/%d" % (ans.num, ans.den))


main()
