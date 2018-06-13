#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 +5;
typedef pair<int, int> pii;
#define f first
#define s second

struct SegmTree {
    int n;
    vector <pii> arr;
    pii query(int l, int r) {
        if(r < l)
            swap(l, r);
        pii ans = {1e9, 0};
        for(l += n, r += n+1; l < r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, arr[l++]);
            if(r & 1)
                ans = min(ans, arr[--r]);
        }
        return ans;
    }
    SegmTree(vector <pii> &org) {
        n = org.size();
        arr.resize(n*2);
        for(int i=0; i<n; i++)
            arr[i+n] = org[i];
        for(int i=n-1; i>=0; i--)
            arr[i] = min(arr[i<<1], arr[(i<<1)|1]);
    }
};

SegmTree *st;
vector <pii> adj[limN];
int fapr[limN];
vector <pii> deps;
int cargs[limN];
int acum[limN], idsEdgPadr[limN];

void dfs(int pos = 1, int dep = 0, int padr = 0, int idEdgPadr = 0) {
    fapr[pos] = deps.size();
    deps.push_back({dep, pos});
    idsEdgPadr[pos] = idEdgPadr;
    for(const auto & sig : adj[pos])
        if(sig.s != padr) {            
            dfs(sig.s, dep+1, pos, sig.f);
            deps.push_back({dep, pos});
        }
}

int calcaAcums(int pos = 1, int padr = 0) {
    int &ans = acum[idsEdgPadr[pos]];
    ans += cargs[pos];
    for(const auto & sig : adj[pos])
        if(sig.s != padr) {            
            ans += calcaAcums(sig.s, pos);
        }
    return ans;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back({i, b});
        adj[b].push_back({i, a});
    }
    dfs();
    st = new SegmTree(deps);
    
    scanf("%d", &Q);
    while(Q--) {
        int a, b ;
        int lca ;
        scanf("%d%d", &a, &b);
        lca = st->query(fapr[a], fapr[b]).s;
        // printf("%d %d have lca %d\n", a, b, lca);
        cargs[a]++;
        cargs[b]++;
        cargs[lca]-=2;
    }
    calcaAcums();

    for(int i=1; i<N; i++)
        printf("%d ", acum[i]);
    printf("\n");
}
