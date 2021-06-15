def get_input():
    n = int(input())
    mat = [[int(x) for x in input().split()] for i in range(3)]
    return (n, mat)


def tc(n, mat):
    inf = -2**64
    ans = [[inf for i in range(n)] for i in range(3)]
    ans[0][0] = mat[0][0]
    ans[1][0] = mat[1][0] + ans[0][0]
    ans[2][0] = mat[2][0] + ans[1][0]
    for j in range(1, n):
        tmp = [inf, inf, inf]
        for i in range(3):
            tmp[i] = ans[i][j-1] + mat[i][j]
        for i in range(3):
            ans[i][j] = tmp[i]
            suma = mat[i][j]
            for r in range(i-1, -1, -1):
                ans[i][j] = max(ans[i][j], suma + tmp[r])
                suma += mat[r][j]
            suma = mat[i][j]
            for r in range(i+1, 3):
                ans[i][j] = max(ans[i][j], suma + tmp[r])
                suma += mat[r][j]
            if i != 1:
                ans[i][j] = max(ans[i][j], (0 if j == 1 else max(ans[0][j-2],
                                                                 ans[2][j-2]))
                                + mat[0][j-1] + mat[1][j-1] + mat[2][j-1]
                                + mat[0][j] + mat[1][j] + mat[2][j])
    return ans[2][n-1]


def main():
    n, mat = get_input()
    print(tc(n, mat))


main()
