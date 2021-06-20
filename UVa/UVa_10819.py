def testCase(pMon, clothes):
    dp = [-1 for i in range(pMon+201)]
    n = pMon+200
    dp[0] = 0
    for c in clothes:
        for i in range(n, c[0]-1, -1):
            if(dp[i-c[0]] >= 0):
                dp[i] = max(dp[i], dp[i-c[0]] + c[1])
    return max(max(dp[:pMon+1]), max(dp[2001:]) if n >= 2001 else 0)


def main():
    while True:
        try:
            pMon, n = [int(x) for x in input().split()]
            clothes = [[int(x) for x in input().split()] for j in range(n)]
            print(testCase(pMon, clothes))
        except EOFError:
            break


if __name__ == "__main__":
    main()
