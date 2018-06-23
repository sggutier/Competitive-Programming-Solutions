#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limT = 1e5 + 5;
const int limN = 5005;
const int limK = 11;

int K ;
ll dp[limN][limN];
ll hap[limK];
int numCrds[limT];
int numPlay[limT];

int main() {
    int N;
    scanf("%d%d", &N, &K);
    for(int i=N*K, a; i; i--) {
        scanf("%d", &a);
        numCrds[a]++;
    }
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        numPlay[a]++;
    }
    for(int i=1; i<=K; i++)
        scanf("%lld", &hap[i]);

    for(int p=1; p<=N; p++) {
        for(int c=N*K; c; c--) {
            for(int r=min(K, c); r; r--)
                dp[p][c] = max(dp[p][c], dp[p-1][c-r] + hap[r]);
        }
    }

    ll ans = 0;
    for(int t=0; t<limT; t++)
        ans += dp[numPlay[t]][numCrds[t]];

    printf("%lld\n", ans);
}
