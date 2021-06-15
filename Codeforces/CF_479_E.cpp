#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;
typedef int ll;
const ll mod = 1e9 + 7;

ll dp[limN][limN], sums[limN][limN];

int main() {
    int N, K, A, b;

    scanf("%d%d%d%d", &N, &A, &b, &K);
    if(A < b)
        N = b-1;
    else {
        A = N+1-A;
        N = N-b;
    }

    for(int i=1; i<=N; i++) {
        dp[0][i] = 1;
        sums[0][i] = i;
    }

    for(int k=1; k<=K; k++) {
        for(int n=1; n<=N; n++) {
            int w = max(0, n-(N-n)-1);
            dp[k][n] = ((sums[k-1][n-1] - sums[k-1][w] + mod) % mod
                        + (sums[k-1][N] - sums[k-1][n] + mod) % mod) % mod;
            // printf("%d ", dp[k][n]);
            sums[k][n] = (sums[k][n-1] + dp[k][n]) % mod;
        }
        // printf("\n");
    }

    printf("%d\n", dp[K][A]);
}
