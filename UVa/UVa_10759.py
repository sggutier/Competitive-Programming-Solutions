import math


class Frac:
    def __init__(self, num=0, den=1):
        self.num, self.den = Frac.simplify(num, den)

    def simplify(num, den):
        gcd = math.gcd(num, den)
        return (num//gcd, den//gcd)

    def __add__(self, otr):
        return Frac(*Frac.simplify(self.num * otr.den + otr.num * self.den,
                                   self.den * otr.den))

    def __mul__(self, otr):
        return Frac(*Frac.simplify(self.num * otr.num,
                                   self.den * otr.den))

    def __str__(self):
        if self.den != 1:
            return "%d/%d" % (self.num, self.den)
        return "%d" % self.num

    def __repr__(self):
        return str(self)

    def __radd__(self, otr):
        return self if otr == 0 else otr + self

    def __sub__(self, otr):
        return self + Frac(-otr.num, otr.den)


def precarga(n=24, x=150):
    global dp
    x -= 1
    dp = [[Frac() for j in range(x+1)] for i in range(n+1)]
    dp[0][0] = Frac(1, 1)
    for k in range(1, n+1):
        for s in range(x+1):
            for d in range(1, 7):
                if d+s > x:
                    break
                dp[k][s+d] += dp[k-1][s]*Frac(1, 6)


def testCase(n, x):
    global dp
    if n == 0:
        raise ValueError("acaba la entrada")
    if x == 0:
        return Frac(1, 1)
    return Frac(1, 1) - sum(dp[n][:x])


def main():
    precarga()
    while True:
        try:
            print(testCase(*[int(x) for x in input().split()]))
        except:
            break


main()
