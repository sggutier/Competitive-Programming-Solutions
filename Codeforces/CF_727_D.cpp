#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<int, int> par;
typedef vector<int> vi;
const int limN = 1e5 + 15;

struct Edge {
    int u, v;
    ll cap, flow;
    Edge() {}
    Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
  
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

    void AddEdge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }

    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }

    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < (int) g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};

int getTS(char* &c) {
    if(*c=='S') { c++; return 0; }
    if(*c=='M') { c++; return 1; }
    if(*c=='L') { c++; return 2; }
    int ans = 1;
    while(*c && *c!=',') ans++, c++;
    return ans;
}

int main() {
    Dinic fl(limN);
    int ini=0, fin=1, et=8;
    int N ;
    char stSizNms[6][5] = {"S", "M", "L", "XL", "XXL", "XXXL"};
    int ans[limN];

    for(int i=fin+1; i<et; i++) {
        int a ;
        scanf("%d", &a);
        if(a)
            fl.AddEdge(i, fin, a);
    }
    scanf("%d", &N);
    for(int i=0; i<N; i++) {        
        fl.AddEdge(ini, i+et, 1);
        char str[50];
        char *c=str;
        scanf("%s", str);
        do {
            int w = getTS(c);
            fl.AddEdge(i+et, 2 + w, 1);
        } while(*(c++));
    }

    // printf("%d\n", fl.MaxFlow(ini, fin));
    if(fl.MaxFlow(ini, fin)!=N) {
        printf("NO\n");
        return 0 ;
    }
    printf("YES\n");
    for(const Edge &e:fl.E) {
        if(e.u==ini || e.v==fin || e.flow<=0)
            continue;
        //printf("%d %d %d %d\n", e.u, e.v, e.cap, e.flow);
        ans[e.u-et] = e.v-2;
    }
    for(int i=0; i<N; i++)
        printf("%s\n", stSizNms[ans[i]]);
}
