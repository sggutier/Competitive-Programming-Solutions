#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 110;
const int INF = 1e9;

int res[MAX_V][MAX_V], f, s, t;
vector <int> p;
vector <int> AdjList[MAX_V];

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    //printf("%d ", v);
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

// NOTA: ESTE CODIGO ES DEL LIBRO DE STEVE Y FELIX HALIM
int edmond_karps(int _s, int _t) {
    s = _s;
    t = _t;
    int mf = 0;
    while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
        f = 0;
        bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
        queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
                int v = AdjList[u][j];
                if (res[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        //printf("Augmenting thru: ");
        augment(t, INF);
        //printf("\n");
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

int nodCnt, edgCnt;

void clearGlobs() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
}

int outNode(int n) {
    return (n==0 || n==nodCnt-1)? n : n+nodCnt ;
}

void testCase() {
    clearGlobs();
    for(int i=1; i+1<nodCnt; i++) {
        int a, c;
        scanf("%d%d", &a, &c);
        a--;
        res[a][outNode(a)] += c;
        AdjList[a].push_back(outNode(a));
        AdjList[outNode(a)].push_back(a);
    }
    for(int i=0; i<edgCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        res[outNode(a)][b] += c;
        res[outNode(b)][a] += c;
        AdjList[outNode(a)].push_back(b);
        AdjList[b].push_back(outNode(a));
        AdjList[outNode(b)].push_back(a);
        AdjList[a].push_back(outNode(b));
    }
    printf("%d\n", edmond_karps(0, nodCnt-1));
}

int main() {
    while(scanf("%d%d", &nodCnt, &edgCnt)!=EOF && (nodCnt || edgCnt))
        testCase();
}
