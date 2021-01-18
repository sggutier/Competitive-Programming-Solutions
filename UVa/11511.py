#!/usr/bin/env python3

def printPatrn(fils, c):
    n = len(fils)
    ans = [[0 for i in range(c)] for j in range(n)]
    for i in range(n):
        ans[i][0] = fils[i]
    for j in range(1, c):
        ans[0][j] = ans[n-1][j] = 1
        for i in range(1, n-1):
            pd = ans[i-1][j] * ans[i+1][j-1] + 1
            if pd % ans[i][j-1] > 0:
                print('Nope in', i, j)
                for k in range(0, n):
                    print(' '*k + ' '.join([str(x) for x in ans[k]]))
                return
            ans[i][j] = pd // ans[i][j-1]
    for i in range(0, n):
        print('  '*0 + '  '.join([('%2d' % x) for x in ans[i]]))
    return ans
