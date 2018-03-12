#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
const int mod = 1e9 + 7;
typedef pair<int, int> par;
#define f first
#define s second

int dep[limN];
vector <par> adj[limN];

par cicSiz(int pos=1, int ae=-1, int d=1) {
    if(dep[pos])
        return {0, d-dep[pos]};
    dep[pos] = d;
    int ans = 0, tot = 1;
    for(const par &sig:adj[pos])
        if(sig.s != ae) {
            int a, b ;
            tie(a, b) = cicSiz(sig.f, sig.s, d+1);
            ans = max(ans, b);
            tot += a;
        }
    return {tot, ans};
}

int pot2(int c) {
    int ans = 1;
    for(; c; c--)
        ans = (ans*2)%mod;
    return ans;
}

int main() {
    int N ;
    long long ans = 1;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        int a; scanf("%d", &a);
        adj[i].push_back({a, i});
        adj[a].push_back({i, i});
    }
    for(int i=1; i<=N; i++) {
        if(dep[i])
            continue;
        int n, c ;
        long long w ;
        tie(n, c) = cicSiz(i);
        // printf("%d %d\n", n, c);
        w = (pot2(c) + mod - 2) % mod;
        ans = (ans*w) % mod;
        ans = (ans*pot2(n-c)) % mod;
    }
    // ans = ( (ans + 0LL) * pot2(N-c) ) % mod;
    printf("%lld\n", ans);
}
