#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define REP(i, b) for(int i = 0; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace dinic {
    const int MAXV = 1000100;
    const int MAXE = 1000100;
    const ll oo = 1e18;

    int V, E;
    int last[MAXV], dist[MAXV], curr[MAXV];
    int next[MAXE], adj[MAXE]; ll cap[MAXE];

    void init(int n) {
        V = n;
        E = 0;
        REP(i, V) last[i] = -1;
    }

    void edge(int x, int y, ll c1, ll c2) {
        adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
        adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
    }

    ll push(int x, int sink, ll flow) {
        if (x == sink) return flow;

        for (int &e = curr[x]; e != -1; e = next[e]) {
            int y = adj[e];

            if (cap[e] && dist[x] + 1 == dist[y])
                if (ll f = push(y, sink, min(flow, cap[e])))
                    return cap[e] -= f, cap[e^1] += f, f;
        }
        return 0;
    }

    ll run(int src, int sink) {
        ll ret = 0;
        for (;;) {
            REP(i, V) curr[i] = last[i];
            REP(i, V) dist[i] = -1;

            queue<int> Q;
            Q.push(src), dist[src] = 0;

            while (!Q.empty()) {
                int x = Q.front(); Q.pop();

                for (int e = last[x]; e != -1; e = next[e]) {
                    int y = adj[e];
                    if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
                }
            }
            if (dist[sink] == -1) break;

            while (ll f = push(src, sink, oo)) ret += f;
        }
        return ret;
    }
}

void testCase(int N, int M) {
    int ini = N+M, fin = ini+1;
    dinic::init(fin+1);
    for(int i=0; i < M; i++) {
        int K ;
        scanf("%d", &K);
        for(int j=0, a; j < K; j++) {
            scanf("%d", &a);
            a--;
            dinic::edge(a, i+N, 1, 0);
        }
    }
    for(int i=0; i < M; i++) {
        dinic::edge(i+N, fin, 1, 0);
    }
    for(int i=0, mit = M / 2 + M % 2; i < N; i++) {
        dinic::edge(ini, i, mit, 0);
    }
    if(dinic::run(ini, fin) != M) {
        printf("NO\n");
        return ;
    }
    printf("YES\n");
    for(int i=0, j=0; i < M; i++) {
        for(; dinic::adj[j] != i + N || dinic::cap[j+1] < 1; j += 2) {
        }
        printf("%d ", dinic::adj[j+1] + 1);
    }
    printf("\n");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        testCase(a, b);
    }
}
