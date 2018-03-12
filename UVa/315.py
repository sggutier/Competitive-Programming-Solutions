nodeCnt = 0
dfsCnt = 0
adj = []
dfs_low = []
dfs_num = []
dfs_parent = []
child_num = []
isCritiNode = []


def semiTarjan(pos):
    global nodeCnt, dfsCnt, adj, dfs_low, dfs_num, dfs_parent, child_num
    global isCritiNode
    dfsCnt += 1
    dfs_low[pos] = dfsCnt
    dfs_num[pos] = dfsCnt
    for sig in adj[pos]:
        if dfs_num[sig] == 0:
            dfs_parent[sig] = pos
            child_num[pos] += 1
            semiTarjan(sig)
            if dfs_low[sig] >= dfs_num[pos]:
                isCritiNode[pos] = True
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig])
        elif dfs_parent[pos] != sig:
            dfs_low[pos] = min(dfs_low[pos], dfs_num[sig])


def testCase():
    global nodeCnt, dfsCnt, adj, dfs_low, dfs_num, dfs_parent, child_num
    global isCritiNode
    dfsCnt = 0
    adj = [[] for i in range(nodeCnt)]
    dfs_low = [0 for i in range(nodeCnt)]
    dfs_num = [0 for i in range(nodeCnt)]
    dfs_parent = [-1 for i in range(nodeCnt)]
    child_num = [0 for i in range(nodeCnt)]
    isCritiNode = [False for i in range(nodeCnt)]
    while True:
        nums = [int(x)-1 for x in input().split()]
        if nums[0] == -1:
            break
        pos = nums[0]
        nums = nums[1:]
        for sig in nums:
            adj[pos].append(sig)
            adj[sig].append(pos)
    for i in range(nodeCnt):
        if dfs_low[i] == 0:
            semiTarjan(i)
            isCritiNode[i] = child_num[i] > 1
    ans = 0
    for t in isCritiNode:
        if t:
            ans += 1
    print(ans)


def main():
    global nodeCnt
    while True:
        nodeCnt = int(input())
        if nodeCnt == 0:
            break
        testCase()


if __name__ == "__main__":
    main()
