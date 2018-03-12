#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define x first
#define y second
const int maxD = 3000;
const int limRng = 5e4 + 5;
const int MAX_V = 105;
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

void clearGlobs() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
}

int dst(const par &A, const par &B) {
    int x = A.x - B.x, y = A.y - B.y;
    return x*x + y*y;
}

void makeGraph(vector <par> &reds, vector <par> &blus, int d) {
    d *= d;
    clearGlobs();
    int r=reds.size(), b = blus.size();
    for(int i=0; i<r; i++) {
        for(int j=0; j<b; j++) {
            if(dst(reds[i], blus[j]) > d)
                continue;
            AdjList[i+2].push_back(j+r+2);
            AdjList[j+r+2].push_back(i+2);
            res[i+2][j+r+2]++;
        }
    }
    for(int i=0; i<r; i++) {
        AdjList[i+2].push_back(0);
        AdjList[0].push_back(i+2);
        res[0][i+2]++;
    }
    for(int i=0; i<b; i++) {
        AdjList[i+r+2].push_back(1);
        AdjList[1].push_back(i+r+2);
        res[i+r+2][1]++;
    }
}

void testCase() {
    int N, k;
    vector <par> reds, blus;
    int ini=0, fin=maxD;
    scanf("%d%d", &N, &k);
    for(int i=0; i<N; i++) {
        par tmp;
        char col[7];
        scanf("%d%d%s", &tmp.x, &tmp.y, col);
        if(col[0]=='r')
            reds.push_back(tmp);
        else
            blus.push_back(tmp);
    }

    while(ini<fin) {
        int piv = (ini+fin)/2;
        makeGraph(reds, blus, piv);
        if(edmond_karps(0, 1) >= k)
            fin = piv;
        else
            ini = piv+1;
    }

    if(fin==maxD)
        printf("Impossible\n");
    else
        printf("%d\n", ini);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
