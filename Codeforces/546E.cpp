#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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

int ans[105][105];

int main() {
	int N, E;
    PushRelabel *pr;
    int A[105], B[105];
    int sa = 0, sb = 0;

    scanf("%d%d", &N, &E);
    int ini = 2*N, fin = 2*N+1;
    pr = new PushRelabel(2*N + 2);

    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        pr->add_edge(ini, i, A[i]);
        pr->add_edge(i, i+N, A[i]);
        sa += A[i];
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &B[i]);
        pr->add_edge(i+N, fin, B[i]);
        sb += B[i];
    }

    if(sa != sb) {
        printf("NO\n");
        return 0;
    }

    for(int i=0, x, y; i<E; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;
        pr->add_edge(x, y+N, 1e9);
        pr->add_edge(y, x+N, 1e9);
    }

    if(pr->maxflow(ini, fin) != sb) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(int i=0; i<N; i++) {
        for(const auto e : pr->g[i]) {
            // printf("%d => %d %d %d %d\n", i, e.back, e.dest - N, e.c, e.f);
            ans[i][e.dest - N] = max(0, e.f);
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

