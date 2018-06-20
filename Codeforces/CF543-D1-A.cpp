#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

int dp[limN][limN];

int main() {
    int N, M, B, mod;

    scanf("%d%d%d%d", &N, &M, &B, &mod);
    dp[0][0] = 1%mod;
    for(int g; N; N--) {
        scanf("%d", &g);
        for(int i=1; i<=M; i++) {
            for(int j=B; j>=g; j--) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-g]) % mod;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=B; i++)
        ans = (ans + dp[M][i]) % mod;

    printf("%d\n", ans);
}
