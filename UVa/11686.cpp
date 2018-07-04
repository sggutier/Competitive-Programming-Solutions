#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

vector <int> adj[limN];
bool usd[limN], actv[limN];
int padrCnt[limN];
queue <int> Q;

int W = 0;
int dfsNum[limN], minVal[limN];
stack <int> S;

void tarjan(int pos) {
    if(usd[pos]) return;
    actv[pos] = usd[pos] = true;
    minVal[pos] = dfsNum[pos] = W++;
    S.push(pos);
    for(const int &sig : adj[pos]) {
        tarjan(sig);
        if(actv[sig])
            minVal[pos] = min(minVal[pos], minVal[sig]);
    }
    if(minVal[pos] != dfsNum[pos])
        return;
    int q ;
    do {
        q = S.top(); S.pop();
        actv[q] = false;
    } while(q != pos);
}

void testCase(int N, int E) {
    memset(padrCnt, 0, sizeof(padrCnt));
    memset(usd, 0, sizeof(usd));
    memset(actv, 0, sizeof(actv));
    for(int i=0; i<limN; i++)
        adj[i].clear();
    W = 0;
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        padrCnt[b]++;
    }
    for(int i=1; i<=N; i++) {
        tarjan(i);
        if(minVal[i] != dfsNum[i]) {
            printf("IMPOSSIBLE\n");
            return ;
        }
    }
    for(int i=1; i<=N; i++)
        if(!padrCnt[i])
            Q.push(i);
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        printf("%d\n", pos);
        for(const int &sig : adj[pos]) {
            if(!(--padrCnt[sig]))
                Q.push(sig);
        }
    }
}

int main() {
    int N, E;
    while(scanf("%d%d", &N, &E) != EOF && (N || E))
        testCase(N, E);
}
