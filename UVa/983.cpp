#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
#define ll long long

int N, M;
ll mat[limN][limN];

ll rng(int ri, int ci, int rf, int cf) {
    ri--, ci--;
    return mat[rf][cf] - mat[rf][ci] - mat[ri][cf] + mat[ri][ci];
}

void testCase() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%lld", &mat[i][j]);
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }

    ll ans = 0LL;
    for(int i=M; i<=N; i++) {
        for(int j=M; j<=N; j++) {
            printf("%lld\n", rng(i-M+1, j-M+1, i, j));
            ans += rng(i-M+1, j-M+1, i, j);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc = 0;
    
    while(scanf("%d%d", &N, &M)!=EOF) {
        if(tc++)
            printf("\n");
        testCase();
    }
    
    return 0;
}
