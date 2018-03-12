#include <bits/stdc++.h>
using namespace std;
const int limN = 80;
const int limK = 10;
const int inf = 1<<29;

int N, K;
int maxSum[limN][limN][limK];
int grid[limN][limN];

void testCase() {
    for(int j=2; j<=N; j++) {
        for(int k=0; k<=K; k++) {
            maxSum[0][j][k] = -inf;
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &grid[i][j]);
            for(int k=0; k<=K; k++) {
                maxSum[i][j][k] = -inf;
            }
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            for(int dir=-1; dir<=1; dir+=2) {
                for(int k=0; k<=K; k++) {
                    int neg=k, sum=0;
                    for(int c=j; 0<c && c<=N; c+=dir) {
                        sum += grid[i][c];
                        neg -= grid[i][c]<0? 1 : 0;
                        if(neg<0)
                            break;
                        if(maxSum[i-1][c][neg]!=-inf)
                            maxSum[i][j][k] = max(maxSum[i][j][k], maxSum[i-1][c][neg] + sum);
                    }
                }
            }
        }
    }
    if(maxSum[N][N][K]==-inf)
        printf("impossible\n");
    else
        printf("%d\n", maxSum[N][N][K]);
}

int main() {
    int tc = 0;
    while(scanf("%d%d", &N, &K)!=EOF && (N || K)) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}
