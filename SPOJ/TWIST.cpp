#include <bits/stdc++.h>
using namespace std;

struct item {
    int val, prior;
    bool crg;
    int cnt;
    item *l, *r;
    item() {}
    item(int val) : val(val), prior(random()), crg(false), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updCnt(pitem t) {
    if(t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void push(pitem t) {
    if(t && t->crg) {
        t->crg = 0;
        swap(t->l, t->r);
        if(t->l) t->l->crg ^= 1;
        if(t->r) t->r->crg ^= 1;
    }
}

void split(pitem t, int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < cnt(t->l) )
        split(t->l, k, l, t->l), r = t;
    else 
        split(t->r, k-cnt(t->l)-1, t->r, r), l = t;
    
    updCnt(t);
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

void printa(pitem t) {
    push(t);
    if(t->l) printa(t->l);
    printf("%d ", t->val);
    if(t->r) printa(t->r);
}

void cga(pitem t) {
    if(t)
        t->crg ^= 1;
}

int main() {
    srandom(time(NULL));
    pitem t = NULL;
    int N, Q;

    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        merge(t, t, new item(i));
    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        pitem x, y, z;
        split(t, a-1, x, y);
        split(y, b-a, y, z);
        cga(y);
        merge(y, y, z);
        merge(t, x, y);
    }
    printa(t);
    printf("\n");
}
