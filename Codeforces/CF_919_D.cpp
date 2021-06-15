#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;

char str[limN];
bool usd[limN];
bool actv[limN];
int dp[limN];
vector <int> adj[limN];

bool tieneCicl(int pos) {
    if(usd[pos]) return actv[pos];
    usd[pos] = true;
    actv[pos] = true;
    for(const int &sig:adj[pos])
        if(tieneCicl(sig))
            return true;
    actv[pos] = false;
    return false;
}

int maxCicl(const int pos, const char c) {
    if(usd[pos])
        return dp[pos];
    usd[pos] = true;
    dp[pos] = 0;
    for(const int &sig:adj[pos])
        dp[pos] = max(dp[pos], maxCicl(sig, c));
    if(str[pos]==c)
        dp[pos]++;
    return dp[pos];
}

int main() {
    int N, E;
    scanf("%d%d", &N, &E);
    scanf("%s", str);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
    }
    for(int i=0; i<N; i++)
        if(tieneCicl(i)) {
            printf("-1\n");
            return 0;
        }

    int ans = 0;

    for(char c='a'; c<='z'; c++) {
        memset(usd, 0, sizeof(usd));
        for(int i=0; i<N; i++)
            ans = max(ans, maxCicl(i, c));
    }

    printf("%d\n", ans);
}
