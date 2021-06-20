#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_V = 305;
//const double EPS = 1e-9;
//const double PI = acos(-1.0); // important constant; alternative #define PI (2.0 * acos(0.0))
const int limN = 305;

struct point { int x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(int _x, int _y) : x(_x), y(_y) {}        // user-defined
};

struct vec { int x, y;  // name: `vec' is different from STL vector
  vec(int _x, int _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

int cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept cointinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

int dst2(point A, point B) {
    int x = A.x - B.x;
    int y = A.y - B.y;
    return x*x + y*y;
}

/////////////////////////////////////////////////////////////////////////////////

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

//#############################################################################

void testCase(int N) {
    clearGlobs();
    
    point pts[limN];
    int power[limN];
    bool lad[limN];
    point L, R;
    int a, b, rad;
    int ini, fin;
    int lCnt=0, rCnt=0;

    for(int i=0; i<N; i++)
        scanf("%d%d%d", &pts[i].x, &pts[i].y, &power[i]);
    scanf("%d%d%d", &a, &b, &rad);

    a--, b--;
    ini = N;
    fin = N+1;
    L = pts[a];
    R = pts[b];
    rad *= rad;

    for(int i=0; i<N; i++) {
        if(!power[i])
        //if(i==a || i==b)
            continue;
        lad[i] = ccw(pts[i], L, R);
        if(!lad[i])
            lCnt++;
        else
            rCnt++;
    }

    bool flipo = lCnt > rCnt;
    for(int i=0; i<N; i++) {
        //if(i==a || i==b)
        if(!power[i])
            continue;
        bool lado = lad[i];

        if(lado!=flipo) {
            AdjList[i].push_back(fin);
            AdjList[fin].push_back(i);
            res[i][fin] ++;
        }
        else {
            AdjList[i].push_back(ini);
            AdjList[ini].push_back(i);
            res[ini][i] ++;
        }
        
        for(int j=0; j<N; j++) {
            //if(j==a || j==b)
            if(!power[j])
                continue;
            if(lado == lad[j] || dst2(pts[i], pts[j])>rad)
                continue;
            AdjList[i].push_back(j);
            if(lado==flipo && power[i] > power[j])
                res[i][j]++;
        }
    }

    // printf("%d %d\n", lCnt, rCnt);
    // for(int i=0; i<=fin; i++) {
    //     if(i<N)
    //         printf("%s ", lad[i]? "der":"izq");
    //     printf("[%d %d] => ", pts[i].x, pts[i].y);
    //     for(const int &sig:AdjList[i]) {
    //         if(res[i][sig]) {
    //             if(sig==ini)
    //                 printf("(x x) ");
    //             else if(sig==fin)
    //                 printf("(y y) ");
    //             else
    //                 printf("(%d %d) ", pts[sig].x, pts[sig].y);
    //         }
    //     }
    //     printf("\n");
    // }

    printf("%d\n", edmond_karps(ini, fin));
}

int main() {
    int a;
    int tc = 0;
    
    while(scanf("%d", &a)!=EOF && a) {
        printf("Case %d: ", ++tc);
        testCase(a);
    }
}
