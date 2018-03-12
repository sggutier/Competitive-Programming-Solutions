#!/env/bin/python3
import re


limS = 3000
ans = []
usd = []
numCnt = 0
nums = []
isneg = []


def bruta(pos=0, negs=0, sgn=1, sumo=0):
    global limS, ans, usd, numCnt, nums, isneg
    if pos == numCnt:
        ans[sumo+limS] = 1
        return
    if isneg[pos]:
        sgn *= -1
        negs += 1
    sumo += nums[pos]*sgn
    if usd[pos][negs][sumo]:
        return
    usd[pos][negs][sumo] = 1
    bruta(pos+1, negs, sgn, sumo)
    if negs > 0:
        bruta(pos+1, negs-1, -sgn, sumo)


def testCase(linea):
    global ans, usd, numCnt, nums, isneg
    linea = re.sub(" ", "", linea)
    nums = [int(x) for x in re.split(r"[+-]", linea)]
    isneg = [x == '-' for x in re.split(r"\d+", linea)[:-1]]
    numCnt = len(nums)
    ans = [0 for i in range(2*limS+1)]
    usd = [[[False for i in range(2*limS+1)] for j in range(numCnt+1)]
           for k in range(numCnt+1)]
    bruta()
    A = 0
    for i in range(2*limS+1):
        if ans[i]:
            A += 1
    return A


def main():
    while True:
        try:
            lin = input()
        except:
            break
        print(testCase(lin))


if __name__ == "__main__":
    main()
