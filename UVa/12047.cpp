#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
#define tri pair<int, par>
const int limN = 1e4 + 5;
const int limE = 1e5 + 5;
const int inf = 1e9 + 5;

int N, E;
tri edges[limE];
vector <par> adjIda[limN], adjVuelta[limN];

void dijkstra(vector <par> *adj, int pos, vector <int> &minP) {
    minP.resize(N, inf);
    minP[pos] = 0;
    priority_queue <par> Q;
    Q.push(par(0, pos));

    while(!Q.empty()) {
        int pos = Q.top().s, dst = -Q.top().f; Q.pop();
        if(minP[pos] < dst)
            continue;
        for(const par &sig:adj[pos]) {
            int dst2 = sig.f + dst;
            if(minP[sig.s] <= dst2)
                continue;
            minP[sig.s] = dst2;
            Q.push(par(-dst2, sig.s));
        }
    }
}

void testCase() {
    int ini, fin, maxC;
    vector <int> minPIda, minPVuelta;
    scanf("%d%d%d%d%d", &N, &E, &ini, &fin, &maxC);
    ini--, fin--;

    for(int i=0; i<N; i++) {
        adjIda[i].clear();
        adjVuelta[i].clear();
    }
    for(int i=0; i<E; i++) {
        scanf("%d%d%d", &edges[i].s.f, &edges[i].s.s, &edges[i].f);
        edges[i].s.f--, edges[i].s.s--;
        adjIda[edges[i].s.f].push_back(par(edges[i].f, edges[i].s.s));
        adjVuelta[edges[i].s.s].push_back(par(edges[i].f, edges[i].s.f));
    }

    dijkstra(adjIda, ini, minPIda);
    dijkstra(adjVuelta, fin, minPVuelta);
    int ans = -1;
    for(int i=0; i<E; i++) {
        int a = edges[i].s.f, b = edges[i].s.s, c = edges[i].f;
        if(minPIda[a] + minPVuelta[b] + c <= maxC)
            ans = max(ans, c);
    }

    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
