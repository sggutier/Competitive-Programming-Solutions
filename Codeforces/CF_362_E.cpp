#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
const int MAXE = MAXN*MAXN*2  + 5;

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

    ll maxflow(int s, int t, ll K) {
        ll totflow = 0;
        while (path(s), seen[t]) {
            ll totcost = 0;
            ll fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p) {
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
                totcost += r? cost[p][x] : 0;
            }
            if(totcost > K)
                break;
            if(totcost)
                fl = min(fl, K / totcost);
            K -= totcost * fl;
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        // for(int i=0; i < N; i++) {
        //     for(int j=0; j < N; j++) {
        //         if(flow[i][j])
        //             printf("%d %d    %lld\n", i, j, flow[i][j]);
        //     }
        // }
        return totflow;
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

int main() {
    int N, K ;
    scanf("%d%d", &N, &K);
    MCMF mcmf(N + N*N);
    for(int i=0; i < N; i++) {
        for(int j=0, a; j < N; j++) {
            scanf("%d", &a);
            if(a) {
                // printf("%d %d   %d\n", i, j, a);
                int ij = N * (i + 1) + j;
                mcmf.addEdge(i, j, a, 0);
                mcmf.addEdge(i, ij, 1000, 1);
                mcmf.addEdge(ij, j, 1000, 0);
                // printf("%d %d          %d\n", i, ij, 1000);
                // printf("%d %d          %d\n", ij, j, 1000);
            }
        }
    }
    // printf("------------\n");
    printf("%lld\n", mcmf.maxflow(0, N-1, K));
}
