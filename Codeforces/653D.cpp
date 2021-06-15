#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 55;
const double EPS = 1e-6 ;

typedef int Flow;
struct Edge {
    int dest, back;
    Flow f, c;
};

struct PushRelabel {
    vector<vector<Edge>> g;
    vector<Flow> ec;
    vector<Edge*> cur;
    vector<vi> hs; vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    void add_edge(int s, int t, Flow cap, Flow rcap=0) {
        if (s == t) return;
        Edge a = {t, sz(g[t]), 0, cap};
        Edge b = {s, sz(g[s]), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
    }

    void add_flow(Edge& e, Flow f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    Flow maxflow(int s, int t) {
        int v = sz(g); H[s] = v; ec[t] = 1;
        vi co(2*v); co[0] = v-1;
        rep(i,0,v) cur[i] = g[i].data();
        trav(e, g[s]) add_flow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i,0,v) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
};


int N, B;
vector <pii> adj[LIM_N];

Flow getFl(const double k) {
    int ini = N, fin = ini + 1;
    PushRelabel pr(fin + 1);
    pr.add_edge(ini, 0, B);
    pr.add_edge(N-1, fin, B);
    for(int pos=0; pos < N; pos++) {
        for(const auto &e : adj[pos]) {
            if(e.first < k) continue;
            pr.add_edge(pos, e.second, (Flow) (e.first / k));
        }
    }
    return pr.maxflow(ini, fin);
}


int main() {
    int E ;
    double ini = 0, fin = 1e6;

    scanf("%d%d%d", &N, &E, &B);
    for(int i=0, x, y, z; i < E; i++) {
        scanf("%d%d%d", &x, &y, &z);
        x--, y--;
        adj[x].push_back({z, y});
    }

    for(int i=0; i < 400; i++) {
        double piv = (ini + fin) / 2;
        if(getFl(piv) == B)
            ini = piv;
        else
            fin = piv;
    }

    printf("%.10lf\n", ini * B);
}
