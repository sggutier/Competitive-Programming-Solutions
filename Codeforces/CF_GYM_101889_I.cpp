#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
typedef vector<pii> vti;
typedef vector<vpi> graph;


struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;
    RMQ<pii> *maxD;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll> > q(1);
		vpi ret;
        vpi novo;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) {
                ret.emplace_back(d, p);
                novo.emplace_back(-(di - dist[p]), 0);
            }
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
        printf(">> ");
        for(const pii w : novo)
            printf("%d ", w.first);
        printf("\n");
        printf(">> ");
        for(const pii w : ret)
            printf("[%d %d]", w.first, w.second);
        printf("\n");
        for(int i=0; i<sz(C); i++)
            printf("%d ", time[i]);
        printf("\n");
        maxD = new RMQ<pii>(novo);
		return ret;
	}

    int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}

    int getMaxD(int a, int b) {
		if (a == b) return 0;
		a = time[a], b = time[b];
        if(b < a)
            swap(a, b);
        printf("tims %d %d\n", a, b-1);
		return -maxD->query(min(a, b), max(a, b)-1).first;
	}
    
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

int N ;
const int limN = 1e5 + 5;
map <int, int> adj[limN];
LCA* lc;

ll mst(graph &ans) {
    ans.resize(N);
    priority_queue < tuple<int,int,int> > Q;
    bitset <limN> usd;
    ll tt = 0;

    Q.push({0, -1, 0});
    while(!Q.empty()) {
        int pos, pv, dst;
        tie(dst, pv, pos) = Q.top(); Q.pop();
        dst *= -1;
        if(usd[pos]) continue;
        tt += dst;
        usd[pos] = true;
        if(pv != -1)
            ans[pv].push_back({pos, dst});
        for(const auto &sg : adj[pos])
            Q.push({-sg.second, pos, sg.first});
    }

    for(int i=0; i<N; i++) {
        printf("%d => ", i + 1);
        for(const auto sg : ans[i])
            printf("[%d %d] ", sg.first + 1, sg.second);
        printf("\n");
    }
    
    return tt;
}

int main() {
	int E ;
    int Q ;

    scanf("%d%d", &N, &E);
    for(int i=0, a,b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    graph g;
    ll tt = mst(g);
    lc = new LCA(g);
    printf("tt is %lld\n", tt);
    
    scanf("%d", &Q);
    for(int i=0, a, b; i<Q; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        printf("%lld\n", tt - lc->getMaxD(a,b) + adj[a][b]);
    }
}
