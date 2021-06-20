#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int limN = 35;
const int limD = 11;
const int limE = 1e3 + 5;
const int  MAX_V = limN*limD + 5;
const int  inf = 1e9;

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;
vi AdjList[MAX_V];

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
        augment(t, inf);
        //printf("\n");
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

void clearGlobs(int N = MAX_V) {
    memset(res, 0, sizeof(res));
    //printf("Limpiando %d\n", N);
    for(int i=0; i<N; i++)
        AdjList[i].clear();
}

bool itWorks(const int maxC, const int N, const int D, const int E, const int* u, const int* v, const int* cap, const int* dt, const int* cst, const int *conts) {
    //printf("Here => %d %d => %d %d\n", N, D, N*D + 2, MAX_V);
    clearGlobs(N*(D+1) + 2);
    //printf("ptm\n");
    int ini = N*(D+1), fin = D*N + (N-1);//N*D+1;
    int sum = 0;

    for(int i=0; i<N; i++) {
        for(int d=1; d<=D; d++) {
            AdjList[(d-1)*N + i].push_back(d*N + i);
            AdjList[d*N + i].push_back((d-1)*N + i);
            res[(d-1)*N + i][d*N + i] = N*100;
            //printf("(%d) %d %d\n", (int) AdjList.size(), (d-1)*D + i, d*D + i);
        }        
        //printf("(%d) %d %d\n", (int) AdjList.size(), ini, i);
        AdjList[ini].push_back(i);
        AdjList[i].push_back(ini);
        res[ini][i] = conts[i];
        sum += conts[i];
    }

    for(int i=0; i<E; i++) {
        if(cst[i] > maxC || cap[i]==0)
            continue;
        int d = dt[i];
        int x = u[i] + d*N, y = v[i] + (d+1)*N;
        if(res[x][y] == 0) {
            AdjList[x].push_back(y);
            AdjList[y].push_back(x);
        }
        res[x][y] += cap[i];
    }

    return edmond_karps(ini, fin) == sum;
}

void testCase() {
    int N, D, E;
    int u[limE], v[limE], cap[limE], dt[limE], cst[limE];
    int conts[limN];
    int ini=0, fin=0;
    set <int> vals;
    vals.insert(0);

    scanf("%d%d%d", &N, &D, &E);
    for(int i=0; i<E; i++) {
        scanf("%d%d%d%d%d", &u[i], &v[i], &cap[i], &cst[i], &dt[i]);
        u[i]--, v[i]--;
        vals.insert(cst[i]);
    }
    for(int i=0; i<N; i++)
        scanf("%d", &conts[i]);

    vector <int> valsA(vals.begin(), vals.end());
    fin = valsA.size()-1;

    while(ini < fin) {
        int piv = (ini+fin)/2;
        if(itWorks(valsA[piv], N, D, E, u, v, cap, dt, cst, conts))
            fin = piv;
        else
            ini = piv+1;
    }

    if(!itWorks(valsA[ini], N, D, E, u, v, cap, dt, cst, conts)) {
        printf("Impossible\n");
        return;
    }

    printf("%d\n", valsA[ini]);
}

int main() {
    int tc;
    scanf("%d", &tc);

    for(int i=0; i<tc; i++) {
        printf("Case #%d: ", i+1);
        testCase();
    }
}
