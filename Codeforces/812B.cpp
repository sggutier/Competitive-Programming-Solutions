#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

char mat[limN][limN];
int minL[limN], maxR[limN];
int dp[limN][2];

int main() {
    int R, C ;
    scanf("%d%d", &R, &C); C += 2;
    for(int i=R-1; i>=0; i--) {
        scanf("%s", mat[i]);
        minL[i] = C-1;
        for(int j=0; j<C; j++) {
            if(mat[i][j]=='1') {
                maxR[i] = j;
                minL[i] = min(minL[i], j);
            }
        }
    }
    for(; R>1 && maxR[R-1]==0; R--);
    dp[0][1] = limN*limN*limN;
    for(int i=1; i<R; i++) {
        dp[i][0] = 1 + min(dp[i-1][0] + 2*maxR[i-1],
                       dp[i-1][1] + C-1);
        dp[i][1] = 1 + min(dp[i-1][1] + 2*(C-1-minL[i-1]),
                       dp[i-1][0] + C-1);
        //printf("%d => %d %d\n", i, dp[i][0], dp[i][1]);
    }
    printf("%d\n", min(dp[R-1][0] + maxR[R-1],
                       dp[R-1][1] + (C-1-minL[R-1])));
}
