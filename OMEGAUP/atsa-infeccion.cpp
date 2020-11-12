#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

vector <int> adj[LIM_N];
bool usd[LIM_N];

int dfs(const int pos) {
    int ans = 1;
    usd[pos] = true;
    for(const int sig : adj[pos]) {
        if(!usd[sig])
            ans += dfs(sig);
    }
    return ans;
}

int main() {
    int N, E, H;
    scanf("%d%d", &N, &E);
    for(int i=0, a,b; i < E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &H);

    int ini = 0, fin = N-1, piv;
    while(ini < fin) {
        piv = (ini + fin) / 2;
        for(int i = 1; i < N; i++) {
            usd[i] = i <= piv;
        }
        if(dfs(0) <= H) {
            fin = piv;
        }
        else {
            ini = piv + 1;
        }
    }

    printf("%d\n", ini);
}
