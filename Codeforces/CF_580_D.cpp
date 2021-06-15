#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 19;
const int limB = 1<<limN ;

bool usd[limB][limN];
ll memo[limB][limN];

int N ;
ll adj[limN][limN];
ll sf[limN];

ll dp(int rem, int lst = limN-1, int msk = 0) {
    if(rem == 0) {
        return 0 ;
    }
    if(usd[msk][lst])
        return memo[msk][lst];
    usd[msk][lst] = true;
    ll &ans = memo[msk][lst];
    for(int i=0; i<N; i++) {
        if((1<<i) & msk) {
        }
        else
            ans = max(ans, sf[i] + adj[lst][i] + dp(rem-1, i, msk | (1<<i)));
    }
    return ans;                      
}

int main() {
    int M, K;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        scanf("%lld", &sf[i]);
    for(int i=0, a, b, c; i<K; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a][b] = c;
    }
    printf("%lld\n", dp(M));
}
