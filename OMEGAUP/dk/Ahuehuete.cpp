#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1005;
const int limK = 405;
const ll inf = 1e17;

vector <int> adj[limN];
ll hoj[limN];
ll acum[limN];
ll dp[limK][limN];
bool usd[limK][limN];
int W = 0;
int fapr[limN], sigApr[limN];
int aprs[limN];

ll recalca(int pos=1, int ant=-1) {
    fapr[pos] = W;
    aprs[W++] = pos;
    acum[pos] = hoj[pos];
    for(const int &sig : adj[pos])
        if(sig != ant) {
            acum[pos] += recalca(sig, pos);
        }
    sigApr[pos] = W;
    // printf("%d => %d %d %lld\n", pos, fapr[pos], sigApr[pos], acum[pos]);
    return acum[pos];
}

void quer1(int pos, ll nov) {
    hoj[pos] = nov;
    W = 0;
    recalca();
}

ll memo(int K, int pos=0) {
    if(K==0)
        return 0;
    if(pos == W)
        return -inf;
    if(usd[K][pos])
        return dp[K][pos];
    usd[K][pos] = true;
    dp[K][pos] = memo(K, pos+1);
    ll tmp;
    tmp = memo(K-1, sigApr[aprs[pos]]);
    if(tmp != -inf)
        dp[K][pos] = max(dp[K][pos], tmp + acum[aprs[pos]]);
    // printf("%d %d (%d) === %lld vs ", K, pos, aprs[pos], memo(K, pos+1));
    // if(tmp != inf)
    //     printf("%lld [[%d]]", tmp + acum[aprs[pos]], sigApr[aprs[pos]]);
    // printf(" => %lld\n", dp[K][pos]);
    return dp[K][pos];
}

ll quer2(int K) {
    memset(usd, 0, sizeof(usd));
    return max(0LL, memo(K));
}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        scanf("%lld", &hoj[i]);
    recalca();
    for(int i=0, t, a, b; i<Q; i++) {
        scanf("%d%d", &t, &a);
        if(t==1) {
            scanf("%d", &b);
            quer1(a, b);
        }
        else
            printf("%lld\n", quer2(a));
    }
}
