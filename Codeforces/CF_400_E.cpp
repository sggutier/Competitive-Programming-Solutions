#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 1e5 + 5;
const int limB = 17;

int nums[limN];
ll crgs[limB];
set <pii> rngs[limB];

ll gauss(ll n) {
    return (n * (n+1)) / 2;
}

void remS(const int t, const set<pii> :: iterator it) {
    crgs[t] -= gauss(it->s - it->f + 1);
    rngs[t].erase(it);
}

void addS(const int t, const pii nov) {
    if(nov.f > nov.s)
        return ;
    crgs[t] += gauss(nov.s - nov.f + 1);
    rngs[t].insert(nov);
}

void saca(const int t, const int p) {
    // printf("sacando %d %d\n", t, p);
    auto it = rngs[t].upper_bound({p+1, 0});
    it --;
    // printf("\t rng sac : %d %d\n", it->f, it->s);
    pii vl = *it;
    remS(t, it);
    addS(t, {vl.f, p-1});
    addS(t, {p+1, vl.s});
}

void mete(const int t, const int p) {
    // printf("metiendo %d %d\n", t, p);
    pii nv = {p, p};
    auto it = rngs[t].lower_bound(nv);
    if( it != rngs[t].begin() ) {
        it -- ;
        if(it != rngs[t].end() && it->s == p-1) {
            remS(t, it);
            nv.f = it->f;
        }
    }
    it = rngs[t].upper_bound(nv);
    if(it != rngs[t].end() && it->f == p+1) {
        remS(t, it);
        nv.s = it->s;
    }
    // printf("\t mt = %d %d\n", nv.f, nv.s);
    addS(t, nv);
}

int main() {
    int N, Q ;
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    nums[N] = 0;

    for(int b=0; b<limB; b++) {
        int msk = 1<<b;
        int up = 0;
        for(int i=0; i<=N; i++) {
            if(nums[i] & msk)
                continue ;
            if(up != i) {
                // printf("%d => %d %d\n", b, up, i);
                addS(b, {up, i-1});
                // printf("\t %lld\n", crgs[b]);
            }
            up = i+1;
            
        }
    }
    
    for(int q=0, p, v; q<Q; q++) {
        scanf("%d%d", &p, &v);
        p --;
        ll ans = 0;
        for(int b=0; b<limB; b++) {
            int msk = 1<<b;
            if( (msk & nums[p]) == (msk & v) )
                continue ;
            if(msk & v)
                mete(b, p);
            else
                saca(b, p);
        }
        nums[p] = v;
        for(int i=0; i<limB; i++)
            ans += (1LL << i) * crgs[i];
        // for(int b=0; b<limB; b++) {            
        //     printf("@ %d => %lld || ", b, crgs[b]);
        //     for(auto &p : rngs[b])
        //         printf("[%d %d] ", p.f,p.s);
        //     printf("\n");
        // }
        printf("%lld\n", ans);
    }
    
}
