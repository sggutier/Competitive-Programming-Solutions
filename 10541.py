#!/usr/env/python

usd = []
waysMem = []
numCnt = 0
nums = []


def ways(rem, pos):
    global usd, waysMem, numCnt, nums
    if usd[rem][pos]:
        return waysMem[rem][pos]
    usd[rem][pos] = True
    if pos == 0:
        waysMem[rem][pos] = 1
        return 1
    ans = 0
    for i in range(rem-nums[pos-1]-1, -1, -1):
        ans += ways(i, pos-1)
    if pos == 1 and nums[0] <= rem:
        ans += 1
    waysMem[rem][pos] = ans
    return ans


def testCase(rem):
    global usd, waysMem, numCnt, nums
    usd = [[False for x in range(numCnt+1)] for i in range(rem+1)]
    waysMem = [[0 for x in range(numCnt+1)] for i in range(rem+1)]
    # ways(rem, numCnt)
    # print(waysMem)
    # print(usd)
    return ways(rem, numCnt)


def main():
    global numCnt, nums
    tc = int(input())
    for i in range(tc):
        lin = [int(x) for x in input().split()]
        numCnt = lin[1]
        # nums = list(reversed(lin[2:]))
        nums = lin[2:]
        print(testCase(lin[0]))


if __name__ == "__main__":
    main()
