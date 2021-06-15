#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int LIM_N = 14;
const int LIM_B = 1 << LIM_N;

struct Nod {
    int id;
    Nod* nxt;
    Nod(int _id) : id(_id), nxt(this) {}
    Nod(int _id, Nod *_nxt) : id(_id), nxt(_nxt) {}
};

ll L ;
ll adj[LIM_N][LIM_N];
Nod* lst ;
int lpid ;
set <ll> finMsks[LIM_B];

void dfs(const int pos, const int rem, const int msk, const ll sm = 0) {
    // Nod *x = lst;
    // do {
    //     printf("%d ", x->id);
    //     x = x->nxt;
    // }while(x != lst);
    // printf(" => %d %lld\n", msk, sm);
    if(pos == 0) {
        return ;
    }
    if(rem == 0) {
        return ;
    }
    dfs(pos-1, rem, msk, sm);
    if(lpid == pos)
        return ;
    Nod *nov = new Nod(pos);
    Nod *cur = lst, *nxt = cur->nxt ;
    ll df = 0 ;
    do {
        df = adj[cur->id][pos] + adj[pos][nxt->id] - adj[cur->id][nxt->id];
        cur->nxt = nov ;
        nov->nxt = nxt ;

        finMsks[msk | (1 << pos)].insert(sm + df);

        dfs(pos-1, rem-1, msk | (1 << pos), sm + df);
        cur->nxt = nxt;
        cur = nxt;
        nxt = nxt->nxt;
    }while(nxt != lst);
    delete nov ;
}

int main() {
    int N, N2 ;
    scanf("%d%lld", &N, &L);
    N2 = (N-2) / 2 + N % 2 ;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++)
            scanf("%lld", &adj[i][j]);
    }

    lst = new Nod(0);
    int fullB = (1 << N) - 1;
    auto otr = new Nod(1);
    lst->nxt = otr;
    otr->nxt = lst;
    for(int i=1; i < N; i++) {
        for(int j=fullB; j >= 0; j--)
            finMsks[j].clear();
        otr->id = i;
        lpid = i ;
        finMsks[0].insert(adj[0][i]);
        dfs(N-1, N2, 0, adj[0][i]);
        for(int j=fullB; j >= 0; j--) {
            if(j & ((1 << i) ^ 1))
                continue;
            // printf("\t%d %d\n", j, fullB ^ j ^ ((1 << i) ^ 1));
            auto fin = finMsks[fullB ^ j ^ ((1 << i) ^ 1)].rend();
            auto it = finMsks[fullB ^ j ^ ((1 << i) ^ 1)].rbegin();
            for(const ll sm : finMsks[j]) {
                while(it != fin && *it + sm > L) {
                    it ++ ;
                }
                if(it != fin && *it + sm == L) {
                    printf("possible\n");
                    return 0 ;
                }
            }
            // finMsks[fullB - j].clear();
        }
    }

    printf("impossible\n");
}
