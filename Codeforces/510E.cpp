#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_P = 2e4 + 5;
const int LIM_N = 205 ;

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

bool isComp[LIM_P];

void init() {
    isComp[0] = isComp[1] = true;
    for(int i = 2; i*i < LIM_P; i++)
        if(!isComp[i])
            for(int j = i*i; j < LIM_P; j += i)
                isComp[j] = true;
}

int N ;
int nums[LIM_N];
pii nxt[LIM_N];

int main() {
    init();
    scanf("%d", &N);
    for(int i=0; i < N; i++)
        scanf("%d", &nums[i]);

    int ini = N, fin = ini + 1;
    PushRelabel pr(fin + 1);
    for(int i = 0; i < N; i++) {
        nxt[i] = {-1, -1};
        if(nums[i] & 1) {
            pr.add_edge(i, fin, 2);
            continue ;
        }
        pr.add_edge(ini, i, 2);
        for(int j=0; j < N; j++) {
            if(isComp[nums[i] + nums[j]])
                continue;
            pr.add_edge(i, j, 1);
        }
    }

    if(pr.maxflow(ini, fin) != N) {
        printf("Impossible\n");
        return 0 ;
    }

    for(int i = 0; i < N; i++) {
        if(nums[i] & 1)
            continue ;
        for(const auto &e : pr.g[i]) {
            if(e.f <= 0)
                continue ;
            int j = e.dest ;
            // printf("%d & %d\n", i + 1, j + 1);
            (nxt[i].first == -1? nxt[i].first : nxt[i].second) = j;
            (nxt[j].first == -1? nxt[j].first : nxt[j].second) = i;
        }
    }

    // for(int i=0; i < N; i++) {
    //     printf("%d (%d) => %d %d\n", i + 1, nums[i], nxt[i].first + 1, nxt[i].second + 1);
    // }

    vector <vi> cicls;
    for(int i = 0; i < N; i++) {
        if(nums[i] <= 0) continue;
        int pos = i, pv = -1;
        vi a;
        do {
            nums[pos] *= -1 ;
            // printf("%d %d\n", pv, pos);
            a.push_back(pos);
            int nv = nxt[pos].first != pv? nxt[pos].first : nxt[pos].second;
            pv = pos;
            pos = nv;
        } while(pos != i);
        cicls.push_back(a);
    }

    printf("%d\n", (int) cicls.size());
    for(auto &v : cicls) {
        printf("%d", (int) v.size());
        for(const int x : v)
            printf(" %d", x + 1);
        printf("\n");
    }
}
