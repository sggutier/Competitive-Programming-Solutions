#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int inf = (1<<30);

void dijkstra(const vector<list<par>> &edges, int ini, vector <int> &minP) {
    // minP[ini] = 0;
    priority_queue <par> Q ;
    Q.push(par(0, ini));
    while(!Q.empty()) {
        int pos = Q.top().s, crg = -Q.top().f;
        Q.pop();
        if(minP[pos]<=crg)
            continue;
        minP[pos] = crg;
        for(const auto &e: edges[pos]) {
            if(minP[e.s]==inf)
                Q.push(par(-crg - e.f, e.s));
        }
    }
}

void testCase() {
    int nodeCnt, edgeCnt, startNode, remTime;
    vector <int> minP;
    vector <list<par>> adj;
    int ans = 0;

    scanf("%d%d%d%d", &nodeCnt, &startNode, &remTime, &edgeCnt);
    startNode --;
    minP = vector<int>(nodeCnt, inf);
    adj = vector<list<par>>(nodeCnt);
    for(int i=0; i<edgeCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back(par(c,b));
        adj[b].push_back(par(c,a));
    }

    dijkstra(adj, startNode, minP);
    for(const auto &p:minP)
        if(p<=remTime)
            ans ++;

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }

    return 0;
}
