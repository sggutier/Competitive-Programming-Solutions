#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, int> pli;
#define f first
#define s second

struct Nod {
    Nod *par ;
    Nod(): par(this) {}
    Nod* root() {
        if(par == this) return this;
        return par = par->root();
    }
    void join(Nod* y) {
        Nod* x = this->root();
        y = y->root();
        if(x == y) return;
        y->par = x;
    }
};

ll dijkstra(const int ini, const int fin, const int N, const vector<pli> *adj) {
    vector<ll> minD(N, 1e18);
    vector<int> pv(N, -1);
    priority_queue <pli> Q ;
    minD[fin] = 0 ;
    Q.push({0, fin});
    while(!Q.empty()) {
        int pos = Q.top().s;
        ll dst = -Q.top().f;
        Q.pop();
        if(dst > minD[pos]) continue ;
        for(const auto &e : adj[pos]) {
            ll totD = e.f + dst;
            int nxt = e.s;
            if(totD >= minD[nxt]) continue;
            minD[nxt] = totD;
            pv[nxt] = pos;
            Q.push({-totD, nxt});
        }
    }
    for(int pos=ini; pos != fin; pos = pv[pos]) {
        printf("%d ", pos+1);
    }
    printf("%d\n", fin+1);
    return minD[ini];
}

void testCase(int N, int E) {
    int ini, fin ;
    vector <pli> adj[N];
    vector <pair<pair<ll, ll>, pii>> egs(E);
    vector <Nod> nods(N);
    ll maxT = 0 ;
    scanf("%d%d", &ini, &fin);
    ini--, fin--;
    for(int i=0, a, b; i < E; i++) {
        ll c, d, c_d, d_d ;
        scanf("%d %d %lld.%lld %lld.%lld", &a, &b, &c, &c_d, &d, &d_d);
        c = c*10 + c_d;
        d = d*10 + d_d;
        a--, b--;
        egs[i] = {{c, d}, {a, b}};
    }
    sort(egs.begin(), egs.end());
    for(const auto &e : egs) {
        if(e.f.f > maxT && nods[ini].root() == nods[fin].root()) {
            break;
        }
        int x = e.s.f, y = e.s.s;
        nods[x].join(&nods[y]);
        adj[x].emplace_back(e.f.s, y);
        adj[y].emplace_back(e.f.s, x);
        maxT = e.f.f;
    }

    ll totD = dijkstra(ini, fin, N, adj);
    printf("%lld.%lld %lld.%lld\n", totD / 10, totD % 10, maxT / 10, maxT % 10);
}

int main() {
    int N, E ;
    while(scanf("%d%d", &N, &E) != EOF) {
        testCase(N, E);
    }
}
