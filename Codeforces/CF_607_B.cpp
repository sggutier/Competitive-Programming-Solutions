#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

int main() {
    int N ;
    bool isPal[limN][limN];
    int nums[limN];
    int dp[limN][limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        isPal[i][i] = true;
        dp[i][i] = 1;
    }

    for(int d=2; d<=N; d++) {
        for(int i=0, j=d-1; j<N; i++, j++) {
            isPal[i][j] = (nums[i]==nums[j] && (d==2 || isPal[i+1][j-1]));
            //printf("%d %d %s\n", i, j, isPal[i][j]? "si" : "no");
        }
    }

    for(int d=2; d<=N; d++) {
        for(int i=0, j=d-1; j<N; i++, j++) {
            if(isPal[i][j]) {
                dp[i][j] = 1;
                //printf("%d %d >> %d\n", i, j, dp[i][j]);
                continue;
            }
            dp[i][j] = N;
            for(int k=i; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            if(nums[i]==nums[j])
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            // for(int k=0; nums[i+k]==nums[j-k]; k++)
            //     dp[i][j] = min(dp[i][j], 1 + dp[i+k+1][j-k-1]);
            //printf("%d %d => %d\n", i, j, dp[i][j]);
        }
    }

    printf("%d\n", dp[0][N-1]);
}
