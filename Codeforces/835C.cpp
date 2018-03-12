#include <bits/stdc++.h>
using namespace std;

int cnt[11][105][105];

int main() {
    int S, Q, M;

    scanf("%d%d%d", &S, &Q, &M);
    M++;
    for(int i=0; i<S; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cnt[c][a][b]++;
    }
    for(int c=0; c<M; c++) {
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=100; j++) {
                cnt[c][i][j] += cnt[c][i-1][j] + cnt[c][i][j-1] - cnt[c][i-1][j-1];
            }
        }
    }

    while(Q--) {
        int t, xl, xr, yl, yr;
        int ans = 0;
        scanf("%d %d %d %d %d", &t, &xl, &yl, &xr, &yr);
        xl--, yl--;
        for(int c=0; c<M; c++) {
            int w = cnt[c][xr][yr] + cnt[c][xl][yl] - cnt[c][xr][yl] - cnt[c][xl][yr];
            ans += w * ((t+c)%M);
        }
        printf("%d\n", ans);
    }
}
