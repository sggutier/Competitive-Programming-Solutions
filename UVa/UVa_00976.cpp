#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
const int INF = 1e9;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int MAX_D = 4;

int dp[MAX_N][MAX_N];
int R, C;
char mapa[MAX_N][MAX_N];
int minH[MAX_N], maxH[MAX_N];

inline bool isInside(const int &r, const int &c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

void dfs(int r, int c, int *ans, const function <int(int, int)> &f) {
    ans[c] = f(ans[c], r);
    mapa[r][c] = '.';
    for(int d=0; d<MAX_D; d++) {
        int r2 = r+dr[d], c2 = c+dc[d];
        if(isInside(r2, c2) && mapa[r2][c2] == '#')
            dfs(r2, c2, ans, f);
    }
}

void calcDP(int B, int S) {
    for(int i=0; i<=B; i++)
        dp[0][i] = INF;
    dp[0][0] = 0;
    for(int c=0; c<C; c++) {
        dp[c+1][0] = 0;
        int d = minH[c] - maxH[c]-1;
        dp[c+1][1] = min(dp[c][1], d);
        for(int i=2; i<=B; i++)
            dp[c+1][i] = min(dp[c][i], c+1-S>0? dp[c+1-S][i-1] + d : INF);
    }
}

void testCase() {
    int B, S;
    
    scanf("%d%d", &B, &S);
    for(int i=0; i<R; i++)
        scanf("%s", mapa[i]);

    for(int i=0; i<C; i++) {
        minH[i] = INF;
        maxH[i] = 0;
    }
    
    dfs(R-1, 0, minH, [](const int &a, const int &b) -> int {return min(a, b);});
    dfs(0, 0, maxH, [](const int &a, const int &b) -> int {return max(a, b);});

    calcDP(B, S+1);

    printf("%d\n", dp[C][B]);
}

int main() {
    while(scanf("%d%d", &R, &C)!=EOF)
        testCase();
}
