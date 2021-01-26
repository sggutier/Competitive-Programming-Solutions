#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 85;

int dp[LIM_N][LIM_N][LIM_N][LIM_N];
bool usd[LIM_N][LIM_N][LIM_N][LIM_N];

vector <pii> adj[LIM_N];

int memo(int minV, int maxV, int pos, int rem) {
    if(rem == 0) {
        // printf("%d %d %d (%d) => %d\n", minV, maxV, pos, rem, 0);
        return 0;
    }
    if(usd[minV][maxV][pos][rem]) {
        return dp[minV][maxV][pos][rem];
    }
    usd[minV][maxV][pos][rem] = true;
    int &ans = dp[minV][maxV][pos][rem];
    ans = 1e9;
    for(auto it = lower_bound(adj[pos].begin(), adj[pos].end(), pii(minV+1, 0));
        it != adj[pos].end() && it->first < maxV;
        it++) {
        if(it->first < pos)
            ans = min(ans, it->second + memo(minV, pos, it->first, rem-1));
        else
            ans = min(ans, it->second + memo(pos, maxV, it->first, rem-1));
    }
    // printf("%d %d %d (%d) => %d\n\t", minV, maxV, pos, rem, ans);
    // for(auto it = lower_bound(adj[pos].begin(), adj[pos].end(), pii(min(maxV, minV)+1, 0));
    //     it != adj[pos].end() && it->first < maxV;
    //     it++) {
    //     printf("(%d, %d),  ", it->first, it->second);
    // }
    // printf("\n");
    return ans ;
}

int main() {
    int N, K, E ;
    scanf("%d%d%d", &N, &K, &E);
    for(int i=0, a, b, c; i < E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].emplace_back(b, c);
        // adj[b].emplace_back(a, c);
    }
    for(int i=1; i <=N ; i++) {
        adj[0].emplace_back(i, 0);
        sort(adj[i].begin(), adj[i].end());
    }
    int ans = memo(0, N+1, 0, K);
    printf("%d\n", ans==1e9? -1 : ans);
}
