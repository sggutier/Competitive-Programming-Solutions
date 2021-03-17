#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 100000 + 5 ;

int T = 1 ;
vector <int> adj[LIM_N];
int usd[LIM_N];
long long prs ;

pair<int, int> dfs(const int pos, const int col) {
    if(usd[pos] == T)
        return {0, 0} ;
    int x = 0, y = 0 ;
    if(col)
        x ++ ;
    else
        y ++ ;
    // printf("%d => %d\n", pos, col);
    usd[pos] = T ;
    for(const int nxt : adj[pos]) {
        auto r = dfs(nxt, 1 ^ col);
        x += r.first;
        y += r.second;
        if(col)
            prs ++ ;
    }
    return {x, y} ;
}

long long gauss(long long n) {
    return (n * (n+1)) / 2 ;
}

void testCase() {
    T ++ ;
    int N, E ;
    long long x = 0, y = 0;
    prs = 0 ;
    long long ans = 0 ;

    scanf("%d%d", &N, &E);
    for(int i=0, a, b; i < E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i <= N; i++) {
        // prs = 0 ;
        // auto r = dfs(i, adj[i].size() % 2 || adj[i].empty());
        // adj[i].clear();
        // ans += r.first * r.second - prs;
        // x += r.first;
        // y += r.second ;
    }

    x = N ;
    prs = E ;
    ans = (x*x) / 4 - prs;

    printf("%lld\n", ans);
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
