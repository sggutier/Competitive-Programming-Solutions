#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

vector <int> adj[limN];
int w = 1;
int dfsLow[limN], dfsNum[limN];
int chCnt = 0;
bool esArt[limN];

void articula(int pos, int ant=-1) {
    dfsLow[pos] = dfsNum[pos] = w++;
    for(const int &sig : adj[pos]) {
        if(sig == ant) continue;
        if(!dfsNum[sig]) {
            if(ant==-1)
                chCnt ++;
            articula(sig, pos);
            esArt[pos] |= dfsNum[pos] <= dfsLow[sig];
            dfsLow[pos] = min(dfsLow[pos], dfsLow[sig]);
        }
        else
            dfsLow[pos] = min(dfsLow[pos], dfsNum[sig]);
    }
}

void testCase(int N, int E) {
    w = 1;
    for(int i=1; i<=N; i++) {
        adj[i].clear();
        dfsLow[i] = dfsNum[i] = 0;
        esArt[i] = false;
    }

    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=N; i++) {
        if(dfsNum[i]) continue;
        chCnt = 0;
        articula(i);
        esArt[i] = chCnt > 1;
    }

    int ans = 0;
    for(int i=1; i<=N; i++)
        if(esArt[i])
            ans ++;

    printf("%d\n", ans);
}

int main() {
    int n, e;
    while(scanf("%d%d", &n, &e)!=EOF && (n || e))
        testCase(n, e);
}
