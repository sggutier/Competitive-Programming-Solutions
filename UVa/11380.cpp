#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 2e3;
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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limN = 35;

int R, C, P, N;
char mapa[limN][limN];
int nums[limN][limN];

int toOut(int k) {
    return k+N;
}

bool isInside(int r, int c) {
    return 0 <=r && r <R && 0 <= c && c < C;
}

void clearGlobs() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
}

void testCase() {
    clearGlobs();
    N = R*C;
    for(int i=0; i<R; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<C; j++) {
            nums[i][j] = i*C + j;
        }
    }

    int ini = 2*N, fin = 2*N+1;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(mapa[i][j]=='~')
                continue;
            int num = nums[i][j];
            if(mapa[i][j]=='*') {
                res[ini][num] ++;
                AdjList[num].push_back(ini);
                AdjList[ini].push_back(num);
            }
            else if(mapa[i][j]=='#') {
                res[num][fin] += P;
                AdjList[num].push_back(fin);
                AdjList[fin].push_back(num);
            }
            else if(mapa[i][j]=='.') {
                res[num][toOut(num)]++;
                AdjList[num].push_back(toOut(num));
                AdjList[toOut(num)].push_back(num);
                num = toOut(num);
            }
            for(int d=0; d<4; d++) {
                int r = i+dr[d], c = j+dc[d];
                if(!isInside(r, c) || mapa[r][c]=='~' || mapa[r][c]=='*')
                    continue;
                int sig = nums[r][c];
                res[num][sig] += N;
                AdjList[num].push_back(sig);
                AdjList[sig].push_back(num);
            }
        }
    }

    // for(int i=0; i<=2*N+1; i++) {
    //     if(AdjList[i].empty())
    //         continue;
    //     printf("%d => ", i);
    //     for(const int &sig:AdjList[i]) {
    //         printf("(%d %d) ", sig, res[i][sig]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", edmond_karps(ini, fin));
}

int main() {
    while(scanf("%d%d%d", &R, &C, &P)!=EOF)
        testCase();
}
