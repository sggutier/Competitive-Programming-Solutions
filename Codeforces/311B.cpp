#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const int limP = 105;

int d[limN], h[limN];
ll t[limN];
ll dp[limN][limP];
int fk[limN][limP];

int main() {
    int H, N, F ;
    scanf("%d%d%d", &H, &N, &F);
    for(int i=2; i<=H; i++) {
        scanf("%d", &d[i]);
        d[i] += d[i-1];
    }
    for(int i=1; i<=N; i++) {
        scanf("%d%lld", &h[i], &t[i]);
        t[i] -= d[h[i]];
    }

    sort(t+1, t+N+1);

    for(int c=1; c<=N; c++)
        dp[c][0] = (1LL<<60);

    for(int f=1; f<=F; f++) {
        // ll sumo = 0, tots = 0;
        // sumo = t[1];
        dp[1][f] = 0;
        for(int c=1; c<=N; c++) {
            dp[c][f] = (1LL<<60);
            ll sumo = 0;
            for(int k=c; k>=1; k--) {
                sumo += t[c]-t[k];
                dp[c][f] = min(dp[c][f], sumo + dp[k-1][f-1]);
                // printf("[%lld %lld] ", sumo, dp[c-1][k-1]);
            }
            // printf("%lld ", dp[c][f]);
        }
        // printf("\n");
    }

    printf("%lld\n", dp[N][F]);
}
