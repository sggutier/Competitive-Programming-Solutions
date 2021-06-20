#!/usr/env/python3
n = 2


class Mat:
    def __init__(self, s=0, p=0, mat=None):
        if mat:
            self.nums = mat
        elif s == 0:
            self.nums = [[1, 0],
                         [0, 1]]
        else:
            self.nums = [[0, 1],
                         [-p, s]]

    def __add__(self, otr):
        return Mat(mat=[[a+b for a, b in zip(p, q)]
                        for p, q in zip(self.nums, otr.nums)])

    def __mul__(self, otr):
        if type(otr) is Mat:
            ans = [[0 for i in range(n)] for j in range(n)]
            for i in range(n):
                for j in range(n):
                    for k in range(n):
                        ans[i][j] += self.nums[i][k] * otr.nums[k][j]
            return Mat(mat=ans)
        else:
            return [sum(map(lambda x, y: x*y, lin, otr)) for lin in self.nums]

    def __pow__(self, k):
        if k == 0:
            return Mat()
        elif k == 1:
            return self
        mit = self**(k//2)
        return mit*mit if k % 2 == 0 else mit*mit*self


def testCase(s, p, k):
    if s == 0:
        sgn = 1 if (k//2) % 2 == 0 else -1
        return 0 if k % 2 == 1 else sgn*2*p**k
    ans = Mat(s, p)**k * [2, s, 0, s]
    return ans[0]


def main():
    while True:
        nums = [int(x) for x in input().split()]
        if len(nums) < 3:
            break
        print(testCase(*nums))


main()
