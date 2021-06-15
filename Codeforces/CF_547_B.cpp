#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 2e5 + 5;

set <int> nms;

set <int> bks;
set < pair<int, pii> > rngs;

map <int, vector <int> > pss;
int ans[limN];

void quita(const int p) {
    auto it = bks.insert(p).first;
    auto pv = it, sg = it;
    pv--, sg++;
    rngs.erase({-(*sg - *pv - 1), {*pv+1, *sg-1}});
    if(*pv+1 <= p-1)
        rngs.insert({-(p - *pv - 1), {*pv+1, p-1}});
    if(*sg-1 >= p+1)
        rngs.insert({-(*sg - p - 1), {p+1, *sg-1}});
}

int main() {
    int N ;
    int w = 0;

    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        pss[a].push_back(i);
        w = max(w, a);
    }
    bks.insert(-1);
    bks.insert(N);
    rngs.insert({-N, {0, N-1}});

    for(auto &prr : pss) {
        for(const int p : prr.s)
            quita(p);
        // printf("%d => ", prr.f);
        // for(auto &r : rngs) {
        //     printf("[%d, (%d %d)] ", r.f, r.s.f, r.s.s);
        // }
        // printf("\n");
        if(!rngs.empty() && !ans[-rngs.begin()->f])
            ans[-rngs.begin()->f] = prr.f;
    }

    for(int i=1; i<=N; i++) {
        printf("%d ", w);
        if(ans[i])
            w = min(w, ans[i]);
    }
    printf("\n");
}
