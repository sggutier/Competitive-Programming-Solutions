#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i < (b); ++i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int limN = 105;

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


PushRelabel *fl;
int N, M ;

int edf(const int n) {
    return n+2;
}

int grua(const int n) {
    return n+M+2;
}
int gruaFant(const int n) {
    return n+N+M+2;
}

int toNd(const int n) {
    return n-(M+2);
}

int main() {
    int ws[limN], ls[limN];
    int ts[limN];
    int ini=0, fin=1;
    vector <int> ans[limN];
    bitset <limN> usd;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &ws[i], &ls[i]);
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d", &ts[i]);
    }

    fl = new PushRelabel(M+N+N+2);
    for(int i=0; i<N; i++) {
        fl->add_edge(grua(i), gruaFant(i), 1);
        if(ws[i]==0)
            fl->add_edge(gruaFant(i), fin, 1);
        for(int j=0; j<N; j++) {
            if(i==j || ws[i] > ls[j])
                continue;
            fl->add_edge(gruaFant(i), grua(j), 1);
        }
    }
    for(int i=0; i<M; i++) {
        fl->add_edge(ini, edf(i), 1);
        for(int j=0; j<N; j++) {
            if(ts[i] <= ls[j]) {
                fl->add_edge(edf(i), grua(j), 1);
            }
        }
    }

    if(fl->maxflow(ini, fin) < M) {
        printf("impossible\n");
        return 0;
    }

    for(int i=0; i<M; i++) {
        int pos = edf(i);
        do {
            for(const Edge &e:fl->g[pos]) {
                if(e.f > 0) {
                    pos = e.dest;
                    break;
                }
            }
            if(M+2 <= pos && pos < M+N+2)
                ans[i].push_back(toNd(pos));
        } while(pos != fin) ;
    }

    for(int i=0; i<M; i++) {
        int w = 0;
        reverse(ans[i].begin(), ans[i].end());
        for(const int &a:ans[i]) {
            if(w++)
                printf(" ");
            printf("%d", a+1);
        }
        printf("\n");
    }
}
