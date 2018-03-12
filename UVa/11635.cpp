#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<int, par> tri;
#define f first
#define s second
const int limN = 1e5 + 5;
const int inf = 1e9;
const int limHrs = 600;

void dijkstra(vector <par> *adj, int ini, vector <int> &minP) {
    priority_queue <par> Q;
    minP[ini] = 0;
    Q.push(par(0, ini));

    while(!Q.empty()) {
        int pos = Q.top().s, dst = -Q.top().f;
        Q.pop();
        if(dst!=minP[pos])
            continue;
        for(const par &sig:adj[pos]) {
            int dst2 = sig.f + dst;
            if(dst2 >= minP[sig.s])
                continue;
            minP[sig.s] = dst2;
            Q.push(par(-dst2, sig.s));
        }
    }
}

void bfs(vector <int> *adj, int ini, vector <int> &minP) {
    queue <int> Q;
    minP[ini] = 0;
    Q.push(ini);
    while(!Q.empty()) {
        int pos = Q.front();
        int dst = minP[pos]+1;
        Q.pop();        
        for(const int &sig:adj[pos]) {
            if(minP[sig]!=inf)
                continue;
            minP[sig] = dst;
            Q.push(sig);
        }
    }
}

void testCase(int nodCnt) {    
    int edgCnt, hotCnt;
    vector <int> hots;
    vector <par> adj[nodCnt];
    vector <int> res[nodCnt];

    scanf("%d", &hotCnt);
    hots.resize(hotCnt+2);
    for(int i=0; i<hotCnt; i++) {
        scanf("%d", &hots[i]);
        hots[i]--;
    }
    hots[hotCnt] = 0;
    hots[hotCnt+1] = nodCnt-1;
    scanf("%d", &edgCnt);
    for(int i=0; i<edgCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }

    for(int i=0; i<=hotCnt; i++) {
        int p = hots[i];
        vector <int> minP(nodCnt, inf);
        dijkstra(adj, p, minP);
        // printf("Dijkstra at %d =>", p+1);
        // for(int i=0; i<nodCnt; i++) {
        //     printf(" (%d %d)", i+1, minP[i]);
        // }
        // printf("\n");
        // printf("Contains");
        for(int j=0; j<=hotCnt+1; j++) {
            if(hots[j]!=p && minP[hots[j]]<=limHrs) {
                res[p].push_back(hots[j]);
                //printf(" %d", hots[j]+1);
            }
        }
        //printf("\n");
    }

    vector <int> minP(nodCnt, inf);
    bfs(res, 0, minP);

    if(minP[nodCnt-1]==inf)
        printf("-1\n");
    else
        printf("%d\n", minP[nodCnt-1]-1);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
