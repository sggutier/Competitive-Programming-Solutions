#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;
const int INF = numeric_limits<int>::max() / 4 ;

vector <int> adj[LIM_N];
bool usd[2][LIM_N];
int dp[2][LIM_N];

int memo(const int cmp, const int pos, const int prev = -1) {
    if(usd[cmp][pos])
        return dp[cmp][pos];
    usd[cmp][pos] = true;
    int &ans = dp[cmp][pos];
    ans = 0 ;
    int maxD1 = -INF, maxD2 = -INF;
    int sm = 0 ;
    for(const int sig : adj[pos]) {
        if(sig == prev) continue;
        sm += memo(0, sig, pos);
        int df = memo(1, sig, pos) - memo(0, sig, pos) + 1;
        if(df > maxD2)
            maxD2 = df;
        if(maxD2 > maxD1)
            swap(maxD1, maxD2);
    }
    if(maxD1 == -INF)
        maxD1 = 0 ;
    ans = sm + maxD1;
    if(cmp == 0) {
        ans = max(ans, sm);
        ans = max(ans, sm + maxD1 + maxD2);
    }
    // printf("%d %d => %d\n", cmp, pos + 1, ans);
    return ans ;
}

int main() {
    int N ;
    long long x, y ;
    int maxD = 0 ;

    scanf("%d%lld%lld", &N, &x, &y);
    for(int i=1, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i < N; i++)
        maxD = max(maxD, (int) adj[i].size());
    if(maxD == N-1 && x > y) {
        printf("%lld\n", (N-2) * y + x);
        return 0 ;
    }

    long long cnt = memo(0, 0);
    x = min(x, y);

    printf("%lld\n", cnt * x + (N-1-cnt) * y);
}
