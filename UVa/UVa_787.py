def testCase(nums):
    ans = max(nums)
    n = len(nums)
    for i in range(n):
        p = 1
        for j in range(i, n):
            p *= nums[j]
            ans = max(ans, p)
    return ans


def main():
    while True:
        try:
            n = [int(x) for x in input().split()][:-1]
            print(testCase(n))
        except EOFError:
            break


if __name__ == "__main__":
    main()
