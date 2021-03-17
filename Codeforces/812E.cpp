#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_K = 1e7 + 5;
const int LIM_N = 1e5 + 5;

ll cnts[2], xrs[2];
ll reps[2][LIM_K];
int ps[LIM_N];
vector <int> adj[LIM_N];

ll gauss(const ll n) {
    return (n*(n+1)) >> 1;
}

int dfs(const int pos) {
    int dep = 0 ;
    for(const int nxt : adj[pos]) {
        dep = dfs(nxt) ^ 1;
    }
    reps[dep][ps[pos]]++;
    cnts[dep] ++;
    xrs[dep] ^= ps[pos];
    return dep;
}

int main() {
    int N ;
    ll ans = 0, k ;
    scanf("%d", &N);
    for(int i=1; i <= N; i++) {
        scanf("%d", &ps[i]);
    }
    for(int i=2, a; i <= N; i++) {
        scanf("%d", &a);
        adj[a].push_back(i);
    }
    dfs(1);
    k = xrs[0];
    if(k == 0)
        ans += gauss(cnts[0]-1) + gauss(cnts[1]-1);
    for(ll i=0; i < LIM_K; i++) {
        if(!reps[0][i] || (k ^ i) >= LIM_K) continue;
        ans += reps[0][i] * reps[1][k ^ i];
    }
    printf("%lld\n", ans);
}
