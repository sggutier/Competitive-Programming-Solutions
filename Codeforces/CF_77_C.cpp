#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 1e5 + 5 ;

int N ;
ll cnt[LIM_N];
vector <int> adj[LIM_N];

ll dfs(const int pos, const int pv = -1) {
    priority_queue <ll> Q ;
    for(const int nxt : adj[pos]) {
        if(nxt != pv)
            Q.push(dfs(nxt, pos));
    }
    ll ans = 1 ;
    for(int i=min(cnt[pos]-1, (ll) Q.size()); i > 0; i--) {
        ans += 1 + Q.top();
        Q.pop();
        cnt[pos] -- ;
    }
    cnt[pos] -- ;
    for(const int nxt : adj[pos])
        if(nxt != pv) {
            int x = min(cnt[pos], cnt[nxt]);
            ans += x * 2;
            cnt[pos] -= x;
        }
    return ans;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i <= N; i++)
        scanf("%lld", &cnt[i]);
    for(int i=1, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ini ;
    scanf("%d", &ini);
    cnt[ini] ++ ;

    printf("%lld\n", dfs(ini) - 1);
}
