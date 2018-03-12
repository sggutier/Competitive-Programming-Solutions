#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int  MAX_V = 105; // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
const int  INF = 1000000000;

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

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

void clearGlobs() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
}

void testCase(int V) {
    int k, vertex, weight, E;

    scanf("%d%d%d", &s, &t, &E);
    s--, t--;

    memset(res, 0, sizeof res);
    AdjList.assign(V, vi());
    for (int i = 0; i < E; i++) {
        scanf("%d", &k);
        scanf("%d%d", &vertex, &weight);
        k--, vertex--;
        res[k][vertex] += weight;
        res[vertex][k] += weight;
        AdjList[k].push_back(vertex);
        AdjList[vertex].push_back(k);
    }

    mf = 0;
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
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }

    printf("The bandwidth is %d.\n", mf);                              // this is the max flow value
}

int main() {
    int k;
    int tc = 1;
    while(scanf("%d", &k)!=EOF && k>0) {
        printf("Network %d\n", tc++);
        testCase(k);
        printf("\n");
    }
}
