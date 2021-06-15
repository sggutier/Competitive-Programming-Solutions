#include <bits/stdc++.h>
using namespace std;
const int limS = 2005;
const int limP= 505;
const int inf = 1e9;

int N, M, K;
char S[limS], P[limP];
int dp[limS][limP];
int anto[limS][limP];
int minD[limS];
int ans[limS];

int main() {
    scanf("%s%s", S, P);

    N = strlen(S);
    M = strlen(P);
    K = N/M;

    
    for(int j=0; j<M; j++)
        dp[N][j] = inf;

    for(int r=1; r<=K; r++) {
        for(int i=N-1; i>=0; i--) {
            for(int j=0; j+1<M; j++) {
                dp[i][j] = min(dp[i+1][0], 1 + dp[i+1][j]);
                if(S[i]==P[j])
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            }
            dp[i][M-1] = min(dp[i+1][0], 1 + dp[i+1][M-1]);
            if(S[i] == P[M-1])
                dp[i][M-1] = min(dp[i][M-1], anto[i+1][0]);
        }
        minD[r] = dp[0][0];
        for(int i=0; i<=N; i++)
            for(int j=0; j<=M; j++)
                anto[i][j] = dp[i][j];
    }

    for(int r=1; r<=K; r++) {
        int ini = minD[r], fin = N-r*M;
        for(int i=ini; i<=fin; i++)
            ans[i] = r;
    }

    for(int i=0; i<=N; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
