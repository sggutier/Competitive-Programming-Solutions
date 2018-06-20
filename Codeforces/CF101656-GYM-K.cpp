#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int limN = 35;
typedef pair<int, int> pii;
#define r first
#define c second
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

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

int R, C ;
char matr[limN][limN];

bool isVald(int r, int c, char t) {
	return 0 <= r && r < R && 0 <= c && c < C && matr[r][c] == t;
}

int apos(int r, int c, bool fant = false) {
    return r*C + c + (fant? R*C : 0);
}

int testCase() {
    C = strlen(matr[0]) - 1;
    int ini = R*C*2, fin = R*C*2+1;
    PushRelabel pr(R*C*2 + 2);
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            pr.add_edge(apos(i, j), apos(i, j, true), 1);
            if(matr[i][j] == 'W') {
                pr.add_edge(ini, apos(i, j), 1);
                for(int d=0; d<4; d++) {
                    if(!isVald(i + dr[d], j + dc[d], 'I')) continue;
                    pr.add_edge(apos(i, j, true), apos(i + dr[d], j + dc[d]), 1);
                    // printf("W a I en %d %d (%d) a %d %d (%d)\n", i, j, apos(i,j, true), i+ dr[d], j + dc[d], apos(i + dr[d], j + dc[d]));
                }
            }
            else if(matr[i][j]=='I') {
                for(int d=0; d<4; d++) {
                    if(!isVald(i + dr[d], j + dc[d], 'N')) continue;
                    pr.add_edge(apos(i, j, true), apos(i + dr[d], j + dc[d]), 1);
                    // printf("I a N en %d %d (%d)  a %d %d  (%d)\n", i, j, apos(i, j, true), i+ dr[d], j + dc[d], apos(i + dr[d], j + dc[d]));
                }
            }
            else
                pr.add_edge(apos(i, j, true), fin, 1);
        }
    }
    return pr.maxflow(ini, fin);
}

int main() {
	R = 0;
	while(fgets(matr[R], limN, stdin)) {
		if(matr[R][0]!='\n') {
			R++;
			continue;
		}
		//~ printf("Oh, un caso de prueba!\n");		
		printf("%d\n", testCase());
		R = 0;
	}
	if(R==0)
		return 0;
	//~ printf("Oh, un caso de prueba!\n");
	printf("%d\n", testCase());
}
