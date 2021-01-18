#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 3e5 + 5;

set <int> ans ;
int pr[LIM_N];
vector <pii> adj[LIM_N];
bool usd[LIM_N];

void dfs(const int pos=0, const int pv = -1, const int pe = -1) {
    usd[pos] = true;
    for(const auto nxt : adj[pos]) {
        if(!usd[nxt.second])
            dfs(nxt.second, pos, nxt.first);
    }
    if(pr[pos]) {
        pr[pv] ^= 1;
        ans.insert(pe);
    }
}

int main() {
    int N, E;
    int lastNeg = -1;
    int p = 0 ;

    scanf("%d%d", &N, &E);
    for(int i=0; i < N; i++) {
        scanf("%d", &pr[i]);
        if(pr[i] == -1)
            lastNeg = i;
        else
            p ^= pr[i];
    }
    for(int i=0, a, b; i < E; i++ ) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].emplace_back(i, b);
        adj[b].emplace_back(i, a);
    }
    if(p && lastNeg == -1) {
        printf("-1\n");
        return 0 ;
    }
    if(p) pr[lastNeg] = 1;
    for(int i=0; i < N; i++)
        if(pr[i] == -1)
            pr[i] = 0;
    dfs();

    printf("%d\n", (int) ans.size());
    for(const int a : ans)
        printf("%d\n", a+1);
}
