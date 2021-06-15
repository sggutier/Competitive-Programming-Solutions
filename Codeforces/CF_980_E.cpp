#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e6 + 5;
const int LIM_B = 20;

struct Nodo {
    int id ;
    int dep;
    Nodo* ancs[LIM_B] ;
    Nodo(int id): id(id), dep(0) {
        for(int i = 0; i < LIM_B; i++)
            ancs[i] = this;
    }
    Nodo(int id, Nodo* prev): id(id), dep(prev->dep + 1) {
        ancs[0] = prev;
        for(int i=0; i < LIM_B - 1; i++) {
            ancs[i+1] = ancs[i]->ancs[i];
        }
    }
};

int usd[LIM_N];
vector<int> adj[LIM_N];
Nodo* nods[LIM_N];

void dfs(const int pos, const int pv = -1) {
    for(const int nxt : adj[pos]) {
        if(nxt == pv) continue;
        nods[nxt] = new Nodo(nxt, nods[pos]);
        dfs(nxt, pos);
    }
}

int cntDep(Nodo *cur) {
    int ans = 1 ;
    for(int b=LIM_B - 1; b >= 0; b--) {
        if((1 << b) <= cur->dep && !usd[cur->ancs[b]->id]) {
            ans += 1 << b;
            cur = cur->ancs[b];
        }
    }
    return ans;
}

void marcaPt(Nodo* pos) {
    // printf("Rt at %d\n", pos->id + 1);
    while(!usd[pos->id]) {
        // printf("\t%d\n", pos->id + 1);
        usd[pos->id] = true;
        pos = pos->ancs[0];
    }
}

int main() {
    int N, E ;
    scanf("%d%d", &N, &E);
    for(int i=1, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    usd[N-1] = true;
    nods[N-1] = new Nodo(N-1);
    dfs(N-1);
    E = N - E - 1 ;
    for(int i=N-2; E && i >= 0; i--) {
        if(usd[i]) continue;
        int c = cntDep(nods[i]);
        // printf(">>> %d %d\n", i+1, c);
        if(c <= E) {
            E -= c;
            marcaPt(nods[i]);
        }
    }
    for(int i=0; i < N; i++)
        if(!usd[i])
            printf("%d ", i + 1);
    printf("\n");
}
