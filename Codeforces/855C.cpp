#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e5 + 5;
const int limK = 12;

vector <int> adj[limN];
ll dp[3][limK][limN];
bool usd[3][limK][limN];
ll supr, infr;

void psta(int tp, int rem, int pos, int ant = -1) {
    printf("%d %d %d %d => %lld\n", tp, rem, pos+1, ant+1, dp[tp][rem][pos]);
}

ll memo(int tp, int rem, int pos, int ant = -1) {    
    if(usd[tp][rem][pos])
        return dp[tp][rem][pos];
    usd[tp][rem][pos] = true;
    ll &ans = dp[tp][rem][pos];
    if(adj[pos].size() - (ant != -1 ? 1 : 0) == 0) {
        if(rem >= 1 && tp==0)
            ans ++;
        ans = (ans + (tp==2? infr : infr + supr)) % mod;
        psta(tp, rem, pos, ant);
        return ans;
    }
    if(infr) {
        ll s = infr;
        for(const int sig : adj[pos])
            if(sig != ant)
                s = (s * memo(0, rem, sig, pos)) % mod;
        ans = (ans + s) % mod;
    }
    if(tp == 0 && rem) {
        ll s = 1;
        for(const int sig : adj[pos])
            if(sig != ant)
                s = (s * memo(2, rem-1, sig, pos)) % mod;
        ans = (ans + s) % mod;
    }
    if(tp != 2) {
        ll s = supr;
        for(const int sig : adj[pos])
            if(sig != ant)
                s = (s * memo(1, rem, sig, pos)) % mod;
        ans = (ans + s) % mod;
    }
    psta(tp, rem, pos, ant);
    return ans;
}

int main() {
    int N, M, K, X ;
    scanf("%d%d", &N, &M);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d%d", &K, &X);
    supr = M-K;
    infr = K-1;
    cout << supr << " " << infr << endl;
    printf("%lld\n", memo(0, X, 0));
}
