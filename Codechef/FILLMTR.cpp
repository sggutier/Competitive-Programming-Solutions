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

vector <pii> adj[LIM_N];
int cols[LIM_N];

bool dfs(int pos, const int c) {
    if(cols[pos] != 2)
        return (cols[pos] & 1) == c ;
    cols[pos] = c;
    for(const auto &e : adj[pos])
        if(!dfs(e.second, c ^ e.first))
            return false;
    return true;
}

void testCase() {
    int N, E ;
    bool ans = true;
    scanf("%d%d", &N, &E);
    for(int i=0, a, b, c; i < E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for(int i=0; i < N; i++) {
        if(cols[i] != 2) continue;
        if(!dfs(i, 0)) {
            ans = false;
            break;
        }
    }
    printf("%s\n", ans? "yes" : "no");
    for(int i=0; i < N; i++) {
        cols[i] = 2;
        adj[i].clear();
    }
}

int main() {
    for(int i=0; i < LIM_N; i++)
        cols[i] = 2;
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
