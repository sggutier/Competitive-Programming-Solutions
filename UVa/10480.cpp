#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook, http://www.cs.tau.ac.il/~zwick/grad-algo-08/gmc.pdf
 * Description: Find a global minimum cut in an undirected graph, as represented by an adjacency matrix.
 * Time: O(V^3)
 * Status: Lightly tested
 */
// #pragma once

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

void dfs(vector<vector<Edge>> &g, vi &tip, int pos) {
    if(tip[pos]) return;
    tip[pos] = true;
    // printf("==%d\n", pos);
    // for(const auto &e:g[pos])
    //     printf("[%d %d] %d %d\n", e.dest+1, e.back+1, e.f, e.c);
    for(const auto &e:g[pos])
        if(e.c > 0)
            dfs(g, tip, e.dest);
}

void testCase(int N, int E) {
    PushRelabel pr(N);
    vector <vi> adj(N, vi(N));
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        pr.add_edge(a, b, c);
        pr.add_edge(b, a, c);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int ans = pr.maxflow(0, 1);
    vi tip(N);
    dfs(pr.g, tip, 0);
    // cout << ans << endl;
    for(int t=tip[0], i=0; i<N; i++) {
        if(tip[i]!=t)
            continue;
        for(int j=0; j<N; j++) {
            if(tip[j] != t && adj[i][j]) {
                int a = i+1, b = j+1;
                printf("%d %d\n", a, b);
            }
        }
    }
}

int main() {
	int N, E;
    while(scanf("%d%d", &N, &E)!=EOF && (N || E)) {
        testCase(N, E);
        printf("\n");
    }
}
