#include <bits/stdc++.h>
using namespace std;

void testCase(int ACnt) {
    int BCnt;
    char A[ACnt+5];
    scanf("%s", A+1);
    scanf("%d", &BCnt);
    char B[BCnt+5];
    int dp[ACnt+1][BCnt+1];
    scanf("%s", B+1);

    dp[0][0] = 0;
    for(int i=1; i<=ACnt; i++)
        dp[i][0] = i;
    for(int i=1; i<=BCnt; i++)
        dp[0][i] = i;
    for(int i=1; i<=ACnt; i++) {
        for(int j=1; j<=BCnt; j++) {
            dp[i][j] = min(dp[i-1][j-1] + (A[i]==B[j]? 0 : 1),
                           min(dp[i-1][j], dp[i][j-1]) + 1);
        }
    }
    printf("%d\n", dp[ACnt][BCnt]);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
