import math

TC = 1500


class Frac:
    def __init__(self, n=1, d=1):
        k = math.gcd(abs(n), abs(d))
        self.num = n // k
        self.den = d // k

    def __add__(self, otr):
        return Frac(self.num*otr.den + self.den*otr.num,
                    self.den*otr.den)

    def __sub__(self, otr):
        return Frac(self.num*otr.den - self.den*otr.num,
                    self.den*otr.den)

    def __mul__(self, otr):
        return Frac(self.num*otr.num,
                    self.den*otr.den)

    def __abs__(self):
        return Frac(-self.num, self.den)

    def __truediv__(self, otr):
        return Frac(self.num*otr.den,
                    self.den*otr.num)

    def __repr__(self):
        if self.den != 1:
            return "%d / %d" % (self.num, self.den)
        else:
            return str(self.num)


def poly(x, a):
    ans = 0
    pot = 1
    for i in range(7):
        ans += a[i]*pot
        pot *= x
    return ans


def testCase():
    mat = [[0 for j in range(8)] for i in range(7)]
    nums = [0 for i in range(TC+1)]
    x = [0 for i in range(7)]
    for i in range(1, TC+1):
        nums[i] = int(input())
    try:
        input()
    except:
        meh = "shrug"
    for i in range(7):
        pot = 1
        for j in range(7):
            mat[i][j] = Frac(pot)
            pot *= (i+1)
        mat[i][7] = Frac(nums[i+1])
    # print(mat)
    for j in range(7):
        # print("Reducing " + str(mat[j][j]))
        for i in range(j+1, 7):
            t = mat[i][j] / mat[j][j]
            # print(t)
            for k in range(j, 8):
                # print(mat[j][k], end=",, ")
                # print(t * mat[j][k], end="== ")
                mat[i][k] -= (t*mat[j][k])
            # print()
        # print(mat)
    for j in range(6, -1, -1):
        t = Frac(0)
        for k in range(j+1, 7):
            t += mat[j][k]*Frac(x[k])
        w = (mat[j][7] - t) / mat[j][j]
        if w.den != 1 or w.num < 0 or w.num > 1000:
            return "This is a smart sequence!"
        x[j] = w.num
    for i in range(1, TC+1):
        if nums[i] != poly(i, x):
            return "This is a smart sequence!"
    return " ".join([str(w) for w in x])


def main():
    n = int(input())
    for i in range(n):
        print(testCase())


main()
