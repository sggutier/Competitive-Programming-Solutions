#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2000;

int mat[limN][limN];
ll diagL[limN*2+1], diagR[limN*2+1];

int main() {
    int N ;
    tuple<ll, int, int> ans[] = { {-1, 0, 0}, {-1, 0, 0} };

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
            diagL[i+j] += mat[i][j];
            diagR[i-j+N] += mat[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int p = (i+j)%2;
            ans[p] = max(ans[p], {diagL[i+j] + diagR[i-j+N] - mat[i][j], i, j});
        }
    }

    ll a, b ;
    int x, y, p, q;
    tie(a, x, y) = ans[0];
    tie(b, p, q) = ans[1];
    printf("%lld\n", a+b);
    printf("%d %d %d %d\n", x+1, y+1, p+1, q+1);
}
