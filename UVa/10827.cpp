#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int limN = 77;

ll mat[limN][limN];

inline ll getRect(int lx, int ly, int rx, int ry) {
    lx--, ly--;
    return mat[rx][ry] + mat[lx][ly] - mat[lx][ry] - mat[rx][ly];
}

void testCase() {
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%lld", &mat[i][j]);
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    ll ans = mat[1][1], tot=mat[N][N];
    for(int lx=1; lx<=N; lx++) {
        for(int ly=1; ly<=N; ly++) {
            for(int rx=lx; rx<=N; rx++) {
                for(int ry=ly; ry<=N; ry++) {
                    ll w = getRect(lx, ly, rx, ry);
                    ans = max(ans, w);
                    if(1 < lx && rx < N && 1 < ly && ry < N)
                        ans = max(ans, tot + w - getRect(1, ly, N, ry) - getRect(lx, 1, rx, N));
                }
            }
        }
    }
    for(int lx=1; lx<=N; lx++) {
        for(int rx=lx; rx<=N; rx++) {
            ll p = getRect(lx, 1, rx, N);
            ll q = getRect(1, lx, N, rx);
            for(int ly=2; ly<N; ly++) {
                for(int ry=ly; ry<N; ry++) {
                    ans = max(ans, p - getRect(lx, ly, rx, ry));
                    ans = max(ans, q - getRect(ly, lx, ry, rx));
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
    
    return 0;
}
