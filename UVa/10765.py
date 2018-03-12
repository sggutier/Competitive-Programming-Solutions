nodeCnt = 0
dfsCnt = 0
adj = []
dfs_low = []
dfs_num = []
dfs_parent = []
child_num = []
comp_num = []
isCritiNode = []


def semiTarjan(pos):
    global nodeCnt, dfsCnt, adj, dfs_low, dfs_num, dfs_parent, child_num
    global isCritiNode, comp_num
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


def testCase(bombCnt):
    global nodeCnt, dfsCnt, adj, dfs_low, dfs_num, dfs_parent, child_num
    global isCritiNode, comp_num
    dfsCnt = 0
    adj = [[] for i in range(nodeCnt)]
    dfs_low = [0 for i in range(nodeCnt)]
    dfs_num = [0 for i in range(nodeCnt)]
    comp_num = [0 for i in range(nodeCnt)]
    dfs_parent = [-1 for i in range(nodeCnt)]
    child_num = [0 for i in range(nodeCnt)]
    isCritiNode = [False for i in range(nodeCnt)]
    while True:
        a, b = [int(x) for x in input().split()]
        if a == -1:
            break
        adj[a].append(b)
        adj[b].append(a)
    comps = 0
    for i in range(nodeCnt):
        if dfs_low[i] == 0:
            comps += 1
            semiTarjan(i)
            isCritiNode[i] = child_num[i] > 1
            child_num[i] -= 1
    ans = [(child_num[i], -i) if isCritiNode[i] else (0, 0)
           for i in range(nodeCnt)]
    ans.sort(reverse=True)
    for i in range(bombCnt):
        print("%d %d" % (-ans[i][1], ans[i][0] + comps))
    print()


def main():
    global nodeCnt
    while True:
        nodeCnt, bombCnt = [int(x) for x in input().split()]
        if nodeCnt == 0 and bombCnt == 0:
            break
        testCase(bombCnt)


if __name__ == "__main__":
    main()
