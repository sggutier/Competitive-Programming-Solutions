#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#include <bits/extc++.h> /** keep-include */

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;

    MCMF(int N) :
        N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
        seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;

        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});

        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };

        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            trav(i, ed[s]) if (!seen[i])
                relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            trav(i, red[s]) if (!seen[i])
                relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }

    // If some costs can be negative, call this before maxflow:
    void setpi(int s) { // (otherwise, leave this out)
        fill(all(pi), INF); pi[s] = 0;
        int it = N, ch = 1; ll v;
        while (ch-- && it--)
            rep(i,0,N) if (pi[i] != INF)
                trav(to, ed[i]) if (cap[i][to])
                    if ((v = pi[i] + cost[i][to]) < pi[to])
                        pi[to] = v, ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

const int LIM_N = 3e5 + 5;

int main() {
    int R, C ;
    char tmp[LIM_N];
    scanf("%d%d", &R, &C);

    MCMF fl(R*C*9 + 2);
    int ini = R*C*9, fin = ini + 1;
    printf("%d\n", fin+1);
    for(int i=1; i < R; i++) {
        for(int j = 1; j < C; j++) {
            for(int d=0; d < 4; d++) {
                fl.addEdge(ini, i*C + j + R*C*d, 1, 0);
                fl.addEdge(i*C + j + R*C*d, (i-0)*C + (j-0) + R*C*(d + 4), 1, 0);
                fl.addEdge(i*C + j + R*C*d, (i-0)*C + (j-1) + R*C*(d + 4), 1, 0);
                fl.addEdge(i*C + j + R*C*d, (i-1)*C + (j-0) + R*C*(d + 4), 1, 0);
                fl.addEdge(i*C + j + R*C*d, (i-1)*C + (j-1) + R*C*(d + 4), 1, 0);
            }
        }
    }

    for(int i=0; i < R; i++) {
        scanf("%s", tmp);
        for(int j=0; j < C; j++) {
            int v = tmp[j]=='A'? 0 : (tmp[j] == 'C'? 1 : (tmp[j] == 'G'? 2 : 3));
            printf("%d", v);
            for(int d=0; d < 4; d++) {
                fl.addEdge(i*C + j + R*C*(d+4), i*C + j + R*C*8, 1, v!=d);
            }
            fl.addEdge(i*C + j + R*C*8, fin, 1, 0);
        }
        printf("\n");
    }
    printf("\n");
        auto ans = fl.maxflow(ini, fin);
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            for(int d=0; d < 4; d++) {
                if(fl.flow[i*C + j + R*C*(d+4)][i*C + j + R*C*8] > 0)
                    printf("%d", d);
            }
        }
        printf("\n");
    }


    printf("%lld %lld\n", ans.first, ans.second);
}
