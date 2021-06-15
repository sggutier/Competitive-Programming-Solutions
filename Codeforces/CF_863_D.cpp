#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef long long ll;

struct item {
    int val, prior;
    int cnt;
    bool swp;
    item *l, *r;
    item(int val) : val(val), prior(rand()), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updCnt(pitem t) {
    if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void push(pitem t) {
    if(t && t->swp) {
        t->swp = 0;
        swap(t->l, t->r);
        if(t->l) t->l->swp ^= 1;
        if(t->r) t->r->swp ^= 1;
    }
}

void cga(pitem t) {
    if(t) t->swp ^= 1;
}

void merge(pitem &t, pitem l, pitem r) {
    push(l), push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

void split(pitem t, int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else {
        int pos = cnt(t->l) + 1;
        if(k < pos)
            split(t->l, k, l, t->l), r = t;
        else
            split(t->r, k-pos, t->r, r), l = t;
    }
    updCnt(t);
}

void restora(pitem t, int* ans) {
    if(!t) return;
    push(t);
    restora(t->l, ans);
    *(ans + cnt(t->l)) = t->val;
    restora(t->r, ans+cnt(t->l)+1);
}

void printa(pitem t) {
    if(t==NULL)
        return;
    printf("%lld (%lld) =>", (ll) t->val, (ll) cnt(t));
    if(t->l)
        printf(" %lld", (ll) t->l->val);
    else
        printf(" x");
    if(t->r)
        printf(" %lld", (ll) t->r->val);
    else
        printf(" x");
    printf("\n");
    printa(t->l);
    printa(t->r);
}

int main() {
    srand(time(NULL));    
    pitem t = NULL;
    int N, Q, M;
    int ans[limN];

    scanf("%d%d%d", &N, &Q, &M);
    for(int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        merge(t, t, new item(a));
    }
    for(int i=0; i<Q; i++) {
        int x, y, z;
        scanf("%d%d%d", &z, &x, &y);
        if(z==1) {
            pitem a, b, c, d;
            split(t, y-1, b, c);
            split(b, x-1, a, b);
            split(c, 1, c, d);
            merge(t, a, c);
            merge(t, t, b);
            merge(t, t, d);
        }
        else if(z==2) {
            pitem a, b, c;
            split(t, y, b, c);
            split(b, x-1, a, b);
            cga(b);
            merge(t, a, b);
            merge(t, t, c);
        }
    }
    restora(t, ans);
    for(int i=0; i<M; i++) {
        int a;
        scanf("%d", &a);
        printf("%d ", ans[a-1]);
    }
    printf("\n");
}
