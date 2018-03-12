#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef vector<int> vi;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
const int MAX_V = 5005;

/**
 * Author: Simon Lindholm
 * Date: 2015-02-24
 * License: CC0
 * Source: Wikipedia, tinyKACTL
 * Description: Push-relabel using the highest label selection rule and the gap heuristic. Quite fast in practice.
 *  To obtain the actual flow, look at positive values only.
 * Time: $O(V^2\sqrt E)$
 * Status: Tested on kattis and SPOJ
 */
// #pragma once
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

// struct Edge {
//   int u, v;
//   LL cap, flow;
//   Edge() {}
//   Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
// };

// struct Dinic {
//   int N;
//   vector<Edge> E;
//   vector<vector<int>> g;
//   vector<int> d, pt;
  
//   Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

//   void AddEdge(int u, int v, LL cap) {
//     if (u != v) {
//       E.emplace_back(Edge(u, v, cap));
//       g[u].emplace_back(E.size() - 1);
//       E.emplace_back(Edge(v, u, 0));
//       g[v].emplace_back(E.size() - 1);
//     }
//   }

//   bool BFS(int S, int T) {
//     queue<int> q({S});
//     fill(d.begin(), d.end(), N + 1);
//     d[S] = 0;
//     while(!q.empty()) {
//       int u = q.front(); q.pop();
//       if (u == T) break;
//       for (int k: g[u]) {
//         Edge &e = E[k];
//         if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
//           d[e.v] = d[e.u] + 1;
//           q.emplace(e.v);
//         }
//       }
//     }
//     return d[T] != N + 1;
//   }

//   LL DFS(int u, int T, LL flow = -1) {
//     if (u == T || flow == 0) return flow;
//     for (int &i = pt[u]; i < g[u].size(); ++i) {
//       Edge &e = E[g[u][i]];
//       Edge &oe = E[g[u][i]^1];
//       if (d[e.v] == d[e.u] + 1) {
//         LL amt = e.cap - e.flow;
//         if (flow != -1 && amt > flow) amt = flow;
//         if (LL pushed = DFS(e.v, T, amt)) {
//           e.flow += pushed;
//           oe.flow -= pushed;
//           return pushed;
//         }
//       }
//     }
//     return 0;
//   }

//   LL MaxFlow(int S, int T) {
//     LL total = 0;
//     while (BFS(S, T)) {
//       fill(pt.begin(), pt.end(), 0);
//       while (LL flow = DFS(S, T))
//         total += flow;
//     }
//     return total;
//   }
// };


int main() {
    int N, E;
    set <int> es[MAX_V];

    scanf("%d%d", &N, &E);
    PushRelabel pr(N);
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        pr.add_edge(a, b, c);
        pr.add_edge(b, a, c);
    }

    printf("%lld\n", pr.maxflow(0, N-1));
}
