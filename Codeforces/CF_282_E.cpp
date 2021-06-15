#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const int W = 39;

struct nodo {
    nodo* l, *r;
    nodo() : l(NULL), r(NULL) {}
};
typedef nodo* nodop;

nodop arbo = new nodo();

void mete(const ll n, nodop t = arbo, const int k = W) {
    if(k==-1) return ;
    if((1LL<<k) & n) {
        if(!t->r)
            t -> r = new nodo();
        mete(n, t->r, k-1);
    }
    else {
        if(!t->l)
            t -> l = new nodo();
        mete(n, t->l, k-1);
    }
}

ll maxa(ll n) {
    ll ans = 0;
    nodop t = arbo;
    ll dc ;
    for(int k=W; k>=0; k--) {
        if(!t->l || !t->r)
            dc = t->l? 0LL : 1LL;
        else 
            dc = ((1LL<<k) & n)? 0LL : 1LL;
        ans += (dc<<k) ;
        t = dc? t->r : t->l;
    }
    // printf("\t %lld %lld => %lld\n", n, ans, ans^n);
    return ans^n;
}

int main() {
    int N ;
    ll nums[limN];
    ll tt = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &nums[i]);
        tt ^= nums[i];        
    }

    mete(0);
    ll k = 0;
    ll ans = tt;
    for(int i=1; i<=N; i++) {
        k ^= nums[i];
        ans = max(ans, maxa(tt ^ k));
        mete(k);
        // printf("%lld => %lld\n", k, k^tt);
    }

    printf("%lld\n", ans);
}
