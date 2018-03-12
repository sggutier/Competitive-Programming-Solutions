#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n ;
    scanf("%d", &n);
    char S[n+10];
    int dp[n+10];
    // int ans = 0;
    scanf("%s", S+3);
    S[0] = S[1] = S[2] = '#';
    dp[0] = dp[1] = dp[2] = 0;
    n += 3;
    S[n++] = '#';
    S[n++] = '#';
    S[n++] = '#';
    for(int i=3; i<n; i++) {
        dp[i] = dp[i-1] + (S[i]=='.');
        dp[i] = min(dp[i], dp[i-2] + (S[i]=='.' || S[i-1]=='.'));
        dp[i] = min(dp[i], dp[i-3] + (S[i]=='.' || S[i-1]=='.' || S[i-2]=='.'));        
    }
    printf("%d\n", dp[n-1]);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
