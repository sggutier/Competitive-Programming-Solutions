#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool isLuk[limN];
int minC[limN];
bool usd[limN];
int cnt[limN];
vector <int> adj[limN];

void marcaLuks(int n) {
    if(n >= limN)
        return;
    isLuk[n] = true;
    marcaLuks(n*10 + 4);
    marcaLuks(n*10 + 7);
}

int dfs(int pos) {
    if(usd[pos])
        return 0;
    usd[pos] = true;
    int ans = 1;
    for(const int &sig:adj[pos])
        ans += dfs(sig);
    return ans;
}

int main() {
    minC[0] = 0;
    marcaLuks(0);
    isLuk[0] = false;
    int N, E;
    scanf("%d%d", &N, &E);
    for(int i=1; i<=N; i++)
        minC[i] = 1e9;
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<N; i++) {
        cnt[dfs(i)]++;
    }
    for(int c=1; c<=N; c++) {
        for(int p=1; p<=cnt[c]; p<<=1) {
            int d = p*c;
            for(int i=N; i>=d; i--) {
                minC[i] = min(minC[i], minC[i-d]+p);
            }
        }
    }
    printf("\n");
    int ans = N + 1;
    for(int i=0; i<=N; i++) {
        if(isLuk[i])
            ans = min(ans, minC[i]);
    }
    printf("%d\n", ans%(N+1) -1);
}
