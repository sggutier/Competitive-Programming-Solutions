#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 505;

int N ;
ll mat[LIM_N][LIM_N];

void testCase() {
    ll ans = -1e18;
    for(int i=1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            ll x ;
            scanf("%lld", &x);
            ans = max(x, ans);
            mat[i][j] = x + mat[i][j-1];
        }
    }
    for(int l = 1; l <= N; l++ ) {
        for(int r = l; r <= N; r++) {
            ll acm = 0;
            for(int i=1; i <= N; i++) {
                acm += mat[i][r] - mat[i][l-1];
                ans = max(ans, acm);
                acm = max(acm, 0LL);
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    while(scanf("%d", &N) != EOF) {
        testCase();
    }
}
