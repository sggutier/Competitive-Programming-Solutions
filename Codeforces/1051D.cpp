#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll mod = 998244353;
const int limN = 2005;

int cntRm(int a, int b, int x, int y) {
    if(x==y) {
        return (a==x || b==y)? 0 : 1;
    }
    else {
        return (a!=x? 1 : 0) + (b!=y? 1 : 0);
    }
}

int matam[15][15];
bool usd[limN][limN][4];
ll dp[limN][limN][4];

ll memo(int pos, int k, int u) {
    if(pos == 0)
        return k==0? 1 : 0 ;
    if(k<0)
        return 0;
    if(usd[pos][k][u])
        return dp[pos][k][u];
    usd[pos][k][u] = true;
    ll &ans = dp[pos][k][u];
    for(int i=0; i<4; i++)
        ans = (ans + memo(pos-1, k - matam[u][i], i)) % mod;
    return ans;    
}

int main() {
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int a=0; a<2; a++)
                for(int b=0; b<2; b++)
                    matam[i*2 + j][a*2 + b] = cntRm(i, j, a, b);
    int N, K ;

    scanf("%d%d", &N, &K);
    ll ans = 0;

    ans = (ans + memo(N-1, K-1, 0)) % mod;
    ans = (ans + memo(N-1, K-1, 3)) % mod;
    ans = (ans + memo(N-1, K-2, 1)) % mod;
    ans = (ans + memo(N-1, K-2, 2)) % mod;

    printf("%lld\n", ans);
}
