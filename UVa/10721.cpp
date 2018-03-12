#include <bits/stdc++.h>
using namespace std;
const int limN = 51;

bool usd[limN][limN][limN];
long long bcCntMemo[limN][limN][limN];

long long bcCnt(int n, int k, int m) {
    if(usd[n][k][m])
        return bcCntMemo[n][k][m];
    usd[n][k][m] = true;
    if(k==0) {
        return bcCntMemo[n][k][m]=(n==0);
    }
    long long ans = 0LL;
    for(int i=min(m, n); i>=1; i--) {
        ans += bcCnt(n-i, k-1, m);
    }
    // cout << n << " " << k << " " << m << " => " << ans << endl;
    return bcCntMemo[n][k][m] = ans;
}

int main() {
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF) {
        printf("%lld\n", bcCnt(a, b, c));
    }
    
    return 0;
}
