#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(short i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef short ll;
typedef pair<short, short> pii;
typedef vector<short> vi;
const int LIM_N = 82;

typedef vector<double> vd;
bool zero(double x) { return fabs(x) < 1e-10; }
double MinCostMatching(const vector<vd>& cost, vi& L, vi& R) {
    int n = sz(cost), mated = 0;
    vd dist(n), u(n), v(n);
    vi dad(n), seen(n);

    /// construct dual feasible solution
    rep(i,0,n) {
        u[i] = cost[i][0];
        rep(j,1,n) u[i] = min(u[i], cost[i][j]);
    }
    rep(j,0,n) {
        v[j] = cost[0][j] - u[0];
        rep(i,1,n) v[j] = min(v[j], cost[i][j] - u[i]);
    }

    /// find primal solution satisfying complementary slackness
    L = R = vi(n, -1);
    rep(i,0,n) rep(j,0,n) {
        if (R[j] != -1) continue;
        if (zero(cost[i][j] - u[i] - v[j])) {
            L[i] = j;
            R[j] = i;
            mated++;
            break;
        }
    }

    for (; mated < n; mated++) { // until solution is feasible
        int s = 0;
        while (L[s] != -1) s++;
        fill(all(dad), -1);
        fill(all(seen), 0);
        rep(k,0,n)
            dist[k] = cost[s][k] - u[s] - v[k];

        int j = 0;
        for (;;) { /// find closest
            j = -1;
            rep(k,0,n){
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;
            int i = R[j];
            if (i == -1) break;
            rep(k,0,n) { /// relax neighbors
                if (seen[k]) continue;
                auto new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }

        /// update dual variables
        rep(k,0,n) {
            if (k == j || !seen[k]) continue;
            auto w = dist[k] - dist[j];
            v[k] += w, u[R[k]] -= w;
        }
        u[s] += dist[j];

        /// augment along path
        while (dad[j] >= 0) {
            int d = dad[j];
            R[j] = R[d];
            L[R[j]] = j;
            j = d;
        }
        R[j] = s;
        L[s] = j;
    }
    auto value = vd(1)[0];
    rep(i,0,n) value += cost[i][L[i]];
    return value;
}


const int LIM_D = 4;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int main() {
    int R, C ;
    int vals[LIM_N][LIM_N];
    vector <vd> cst;

    scanf("%d%d", &R, &C);
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            scanf("%d", &vals[i][j]);
            cst.push_back(vd());
        }
    }

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if((i + j) % 2) {
                continue;
            }
            cst[ini][i*C + j, 1, 0);
            for(int d=0; d < 4; d++) {
                int a = i + dr[d], b = j + dc[d];
                if(a < 0 || R <= a || b < 0 || C <= b)
                    continue;
                fl.addEdge(i*C + j, a*C + b, 1, vals[i][j] != vals[a][b]);
            }
        }
    }
    MinCostMatching(const vector<vd> &cost, vi &L, vi &R)

    int cst ;
    fl.mcmf(cst);
    printf("%d\n", cst);
}
