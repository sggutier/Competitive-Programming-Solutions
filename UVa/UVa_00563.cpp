#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;

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

int R, C, P ;
int aNum(int r, int c) {
    if(r%(R+1)==0 || c%(C+1)==0)
        return 1;
    r--, c--;
    return r*C + c + 2;
}

void testCase() {
    int B ;
    scanf("%d%d%d", &R, &C, &B);
    P = R*C;
    PushRelabel pr(2*P+2);
    for(int i=0; i<B; i++) {
        int r, c, w;
        scanf("%d%d", &r, &c);
        w = aNum(r, c);
        pr.add_edge(0, w, 1);
    }
    for(int r=1; r<=R; r++) {
        for(int c=1; c<=C; c++) {
            int w = aNum(r, c);
            pr.add_edge(w, w+P, 1);
            w += P;
            for(int d=0; d<limD; d++) {
                pr.add_edge(w, aNum(r+dr[d], c+dc[d]), 1);
            }
        }
    }
            
    // cout << pr.maxflow(0, 1) << endl;
    printf("%spossible\n", pr.maxflow(0, 1)==B? "" : "not ");
}

int main() {
	int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
