#include <bits/stdc++.h>
using namespace std;
const int limD = 20;
const int limM = 10;

long long dp[limM+1][limD+1][limD+1];

void testCase(int numCnt, int querCnt) {
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=limD; i++)
        dp[0][i][0] = 1;
    while(numCnt--) {
        int a ;
        scanf("%d", &a);
        for(int i=limM; i>0; i--) {
            for(int mod=1; mod<=limD; mod++) {
                int b = ((a%mod) + mod)%mod;
                for(int j=0; j<mod; j++) {
                    dp[i][mod][(j+b)%mod] += dp[i-1][mod][j];
                }
            }
        }
    }
    for(int i=1; i<=querCnt; i++) {
        int d, m;
        scanf("%d%d", &d, &m);
        printf("QUERY %d: %lld\n", i, dp[m][d][0]);
    }
}

int main() {
    int a, b;
    for(int i=1; scanf("%d%d", &a, &b)!=EOF && (a || b); i++) {
        printf("SET %d:\n", i);
        testCase(a,b);
    }
    
    return 0;
}
