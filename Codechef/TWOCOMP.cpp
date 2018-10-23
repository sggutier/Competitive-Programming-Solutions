#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> tri;

typedef ll Flow;
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

const pii inf(1 << 29, -1);

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


typedef vector<pii> vpi;
typedef vector<vpi> graph;

struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll> > q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

const int limN = 1e5 + 5;

bool esanc(LCA &lca, const int arb, const int abj) {
    return lca.query(arb, abj) == arb;
}

bool encam(LCA &lca, const int c, const int a, const int b, const int m) {
    return esanc(lca, c, m) && (esanc(lca, m, a) || esanc(lca, m, b));
}

bool isecan(LCA &lca, const int a, const int b, const int x, const int y) {
    const int p = lca.query(a, b), q = lca.query(x, y);
    return encam(lca, p, a, b, q) || encam(lca, q, x, y, p);
}

PushRelabel* hazArb(graph &g, vector <tri> *comps) {
    int C1 = comps[0].size();
    int C2 = comps[1].size();
    int ini = C1+C2, fin = C1+C2+1;
    PushRelabel *pr = new PushRelabel(fin+1);
    LCA lca (g);
    
    for(int i=0, p; i<C1; i++) {
        tie(ignore, ignore, p) = comps[0][i];
        pr->add_edge(ini, i, p);
    }
    for(int i=0, p; i<C2; i++) {
        tie(ignore, ignore, p) = comps[1][i];
        pr->add_edge(C1 + i, fin, p);
    }

    for(int i=0; i<C1; i++) {
        for(int j=0; j<C2; j++) {
            int a, b, x, y;
            tie(a, b, ignore) = comps[0][i];
            tie(x, y, ignore) = comps[1][j];
            if(isecan(lca, a, b, x, y))
                pr->add_edge(i, j+C1, 1e16);
        }
    }

    return pr;
}

int main() {
    int N, CS[2];
    graph adj ;
    PushRelabel *pr = NULL;
    ll sumT = 0;
    vector <tri> comps[2];

    scanf("%d%d%d", &N, &CS[0], &CS[1]);
    adj.resize(N);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
    }
    for(int w=0; w<2; w++) {
        for(int i=0, a, b, c; i<CS[w]; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            comps[w].push_back(tri(a, b, c));
            sumT += c;
        }
    }

    pr = hazArb(adj, comps);

    printf("%lld\n", sumT - pr->maxflow(CS[0] + CS[1], CS[0] + CS[1] + 1) );
}
