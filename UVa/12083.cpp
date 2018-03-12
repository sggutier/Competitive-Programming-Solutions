#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 505;
const int INF = 1e9;

int N, M;
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

int kid(int a) {
    return a+1;
}

int toy(int a) {
    return a+N+1;
}

void testCase() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
    int fin;
    int heights[MAX_V];
    string sex[MAX_V];
    string music[MAX_V];
    string sport[MAX_V];

    scanf("%d", &N);
    fin = N+1;
    
    for(int i=1; i<=N; i++) {
        scanf("%d", &heights[i]);
        char tmp[105];
        scanf("%s", tmp);
        sex[i] = tmp;
        scanf("%s", tmp);
        music[i] = tmp;
        scanf("%s", tmp);
        sport[i] = tmp;
        if(sex[i][0]=='F') {
            res[0][i] = 1;
            AdjList[0].push_back(i);
            AdjList[i].push_back(0);
        }
        if(sex[i][0]=='M') {            
            res[i][fin] = 1;
            AdjList[i].push_back(fin);
            AdjList[fin].push_back(i);
        }
        for(int j=1; j<i; j++) {
            if(abs(heights[i] - heights[j])<=40 && sex[i]!=sex[j] && music[i]==music[j] && sport[i]!=sport[j]) {
                int a=i, b=j;
                if(sex[i][0]=='M')
                    swap(a, b);
                res[a][b] = 1;
                AdjList[a].push_back(b);
                AdjList[b].push_back(a);
            }
        }
    }

    // int W = fin+1;
    // for(int i=0; i<W; i++) {
    //     printf("%d => ", i);
    //     for(int j=0; j<W; j++) {
    //         if(res[i][j]) {
    //             printf("(%d %d) ", j, res[i][j]);
    //         }
    //     }
    //     for(const int sig:AdjList[i])
    //         printf("%d ", sig);
    //     printf("\n");
    // }

    printf("%d\n", N - edmond_karps(0, fin));

    //int W = fin+1;
    // for(int i=0; i<W; i++) {
    //     printf("%d => ", i);
    //     for(int j=0; j<W; j++) {
    //         if(res[i][j]) {
    //             printf("(%d %d) ", j, res[i][j]);
    //         }
    //     }
    //     // for(const int sig:AdjList[i])
    //     //     printf("%d ", sig);
    //     printf("\n");
    // }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
