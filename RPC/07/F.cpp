#include <bits/stdc++.h>
using namespace std;
const int limI = 1000;
const int limN = 100;
const int INF = (1<<30);

int gcdPr[limI + 5][limI + 5];
int dp[limI + 5][limI + 5];

void precarga(int n = limI) {
    for(int i=1; i<=n; i++)
        gcdPr[0][i] = gcdPr[i][0] = i;
    for(int a=1; a<=n; a++) {
        for(int b=a; b<=n; b++) {
            gcdPr[a][b] = gcdPr[b][a] = gcdPr[b%a][a] ;
        }
    }
}

void testCase(int N) {
    int arr[limN];

    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    // for(int i=0; i<N; i++)
    //     dp[i][(i+1)%N] = gcdPr[arr[i]][arr[(i+1)%N]];

    for(int d=2; d<N; d++) {
        for(int a=0; a<N; a++) {
            int b = (a+d)%N;
            int ans = INF, x = arr[a], y = arr[b];
            for(int c=(a+1)%N; c!=b; c=(c+1)%N) {
                ans = min(ans, dp[a][c] + dp[c][b]);// - gcdPr[x][arr[c]] - gcdPr[arr[c]][y]);
            }
            dp[a][b] = ans + gcdPr[x][y];
            //printf("%d %d (%d %d) => %d\n", a, b, x, y, dp[a][b]);
        }
    }

    int ans = INF;
    // for(int i=0; i<N; i++)
    //     ans = min(ans, dp[i][(i+N-1)%N] + gcdPr[arr[i]][arr[(i+N-1)%N]]);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            ans = min(ans, dp[i][j] + dp[j][i] + gcdPr[arr[i]][arr[j]]);
        }
    }

    printf("%d\n", ans);
}

int main() {
    precarga();
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
