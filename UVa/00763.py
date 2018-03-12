nums = []


def precarga():
    global nums
    nums = [0 for i in range(300)]
    nums[0] = 1
    nums[1] = 2
    for i in range(2, 300):
        nums[i] = nums[i-1] + nums[i-2]


def toNum(N):
    ans = 0
    N = N[::-1]
    k = len(N)
    for i in range(k):
        ans += nums[i] if N[i] == '1' else 0
    return ans


def testCase(A, B):
    suma = toNum(A) + toNum(B)
    ans = ""
    for i in range(299, -1, -1):
        if suma >= nums[i]:
            suma -= nums[i]
            ans += "1"
        elif ans != "":
            ans += "0"
    if ans == "":
        ans = "0"
    return ans


def main():
    precarga()
    tc = 0
    while True:
        try:
            if tc:
                A = input()
            A = input()
            B = input()
        except:
            break
        if tc:
            print()
        print(testCase(A, B))
        tc += 1


main()
