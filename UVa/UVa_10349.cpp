#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;
const int limN = 50;
const int MAX_V = 405;
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

int cnts[2];
int R, C;
char mapa[limN][limN];

bool isValid(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C && mapa[r][c]=='*';
}

int toNum(int r, int c) {
    return r*C + c + 1;
}

void dfs(int r, int c) {
    cnts[(r+c)%2]++;
    mapa[r][c] = 'o';
    int pos = toNum(r, c);
    if((r+c)%2) {
        res[pos][MAX_V-1] = 1;
        AdjList[pos].push_back(MAX_V-1);
        AdjList[MAX_V-1].push_back(pos);
        for(int d=0; d<4; d++) {
            if(isValid(r+dr[d], c+dc[d])) {
                int sig = toNum(r+dr[d], c + dc[d]);
                res[sig][pos] = 1;
                AdjList[pos].push_back(sig);
                AdjList[sig].push_back(pos);
            }
        }
    }
    else {
        res[0][pos] = 1;
        AdjList[pos].push_back(0);
        AdjList[0].push_back(pos);
        for(int d=0; d<4; d++) {
            if(isValid(r+dr[d], c+dc[d])) {                
                int sig = toNum(r+dr[d], c + dc[d]);
                res[pos][sig] = 1;
                AdjList[pos].push_back(sig);
                AdjList[sig].push_back(pos);
            }
        }        
    }
    for(int d=0; d<4; d++) {
        if(isValid(r+dr[d], c+dc[d])) {
            dfs(r+dr[d], c + dc[d]);
        }
    }
}

void testCase() {
    int ans = 0;
    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++) {
        scanf("%s", mapa[i]);
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(mapa[i][j]=='o')
                continue;
            cnts[0] = cnts[1] = 0;
            memset(res, 0, sizeof(res));
            for(int k=R*C+1; k>=0; k--)
                AdjList[i].clear();
            AdjList[MAX_V-1].clear();
            dfs(i, j);
            ans += (cnts[0] + cnts[1]) - edmond_karps(0, MAX_V-1);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
