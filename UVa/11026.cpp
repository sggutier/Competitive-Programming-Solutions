#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;

long long dp[limN][limN];

void testCase(int numCnt, long long mod) {
    for(int i=1; i<=numCnt; i++) {
        int n ;
        scanf("%d", &n);
        dp[i][1] = (dp[i-1][1] + n)%mod;
        for(int j=2; j<=i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*n)%mod;
        }
    }
    long long ans = 0LL;
    for(int i=1; i<=numCnt; i++)
        ans = max(ans, dp[numCnt][i]);
    printf("%lld\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
