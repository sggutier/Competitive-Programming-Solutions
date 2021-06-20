#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 205;
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

typedef pair<double, double> par;
#define x first
#define y second

double dst(par A, par B) {
    double a = A.x - B.x, b = A.y - B.y;
    return a*a + b*b;
}

int org[MAX_V][MAX_V];

void clearGlobs() {
    memset(org, 0, sizeof(org));
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++) {
        AdjList[i].clear();
    }
}

void testCase() {
    clearGlobs();
    int N;
    double D;
    par cords[MAX_V];
    int tot = 0;
    scanf("%d%lf", &N, &D);
    for(int i=1; i<=N; i++) {
        int a, b;
        scanf("%lf%lf%d%d", &cords[i].x, &cords[i].y, &a, &b);
        if(a) {
            org[0][i] += a;
            AdjList[0].push_back(i);
            AdjList[i].push_back(0);
            tot += a;
        }
        org[i][i+N] += b;
        AdjList[i].push_back(i+N);
        AdjList[i+N].push_back(i);
    }
    D *= D;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(i==j || dst(cords[i], cords[j]) > D)
                continue;
            org[i+N][j] += N*300;
            AdjList[i+N].push_back(j);
            AdjList[j].push_back(i+N);
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++) {
        for(int x=2*N; x>=0; x--) {
            for(int y=2*N; y>=0; y--) {
                res[x][y] = org[x][y];
            }
        }
        if(edmond_karps(0, i) != tot)
            continue;
        if(cnt++)
            printf(" ");
        printf("%d", i-1);
    }
    if(cnt==0)
        printf("-1");
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
