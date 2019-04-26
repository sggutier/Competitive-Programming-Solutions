#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef long long ll;

int N ;
ll tot = 0;
ll nms[limN];
ll acum[2][limN];
ll dp[limN];

ll getSm(int ini, int k) {
    int p = ini%2;
    int fin = ini-1+k;
    ini --;
    return acum[p][fin]  - acum[p][ini] - (acum[1-p][fin] - acum[1-p][ini]);
}

void pans(ll w) {
    // cout << w << endl;
    ll b = (tot - w) / 2;
    ll a = b + w;
    printf("%lld %lld\n", a, b);
    exit(0);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N;i++) {
        scanf("%lld", &nms[i]);
        tot += nms[i];
        acum[0][i] = acum[0][i-1];
        acum[1][i] = acum[1][i-1];
        acum[i%2][i] += nms[i];
    }
    if(N%2) {
        pans(getSm(1, N));
    }
    for(int i=N/2, sz=2; i>0; i--, sz+=2) {
        dp[i] = max(nms[i + sz -1] - getSm(i, sz-1), nms[i] - getSm(i+1, sz-1));
        dp[i] = max(dp[i], nms[i+sz-1] + nms[i] - dp[i+1]);
        // printf("%d %d => %lld\n", i, sz, dp[i]);
    }
    pans(dp[1]);
}
