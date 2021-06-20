#include <bits/stdc++.h>
using namespace std;
const int limN = 2e3 + 5;

void testCase(int N, int req) {
    int dp[limN];
    dp[0] = 0;
    for(int i=1; i<=N; i++) {
        dp[i] = dp[i-1];
        if(i>=req) {
            dp[i] = dp[i%req + i/req] + i/req;
        }
    }
    printf("%d\n", dp[N]);
}

int main() {
    int tc;
    int a, b, c;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d%d%d", &a, &b, &c);
        testCase(a+b, c);
    }
    
    return 0;
}
