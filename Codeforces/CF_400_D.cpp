#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int inf = 1e9 ;
const int limK = 505;

vector <int> adj[limN];
int colCnt[limN];
int cols[limN];
int ans[limK][limK];
int W = 0;
int dfsId[limN];


void dfs(const int pos) {
    if(dfsId[pos]) return;
    dfsId[pos] = W;
    for(const int sig : adj[pos])
        dfs(sig);
}

int main() {
    int N, E, K;

    scanf("%d%d%d", &N, &E, &K);
    for(int i=1, s=1; i<=K; i++) {
        scanf("%d", &colCnt[i]);
        for(int j=0; j<colCnt[i]; j++, s++) {
            cols[s] = i;
        }
    }
    for(int i=1; i<=K; i++) {
        for(int j=1; j<=K; j++)
            ans[i][j] = inf;
        ans[i][i] = 0;
    }
    for(int i=0, a, b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if(c == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(cols[a] != cols[b]) {
            a = cols[a];
            b = cols[b];
            ans[b][a] = ans[a][b] = min(ans[a][b], c);
        }
    }

    for(int i=1; i<=N; i++) {
        if(dfsId[i]) continue;
        W ++;
        dfs(i);
    }

    for(int i=1; i<=N; i++) {
        if(dfsId[i] != dfsId[i-1] && cols[i] == cols[i-1]) {
            printf("No\n");
            return 0;
        }
    }

    for(int k=1; k<=K; k++) {
        for(int i=1 ;i<=K; i++) {
            for(int j=1; j<=K; j++) {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }

    printf("Yes\n");
    for(int i=1; i<=K; i++) {
        for(int j=1; j<=K; j++)
            printf("%d ", ans[i][j]==inf? -1 : ans[i][j]);
        printf("\n");
    }
}
