#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 +5;

struct item {
    int key, prior;
    int maxR, cnt, totC;
    int crg ;
    item *l, *r;
    item(int key) : key(key), prior(rand()), maxR(1), cnt(1), totC(1), crg(1), l(NULL), r(NULL) {
    }
    item(int a, int b) : key(a), prior(rand()), maxR(b-a+1), cnt(b-a+1), totC(b-a+1), crg(1), l(NULL), r(NULL) {
    }
};
typedef item* pitem;

int cnt(const pitem t) {
    return t? t->cnt : 0;
}

void push(const pitem t) {
    if(!t) return;
    if(t->crg >= 0) return;
    if(t->l)
        t->l->crg = t->crg;
    if(t->r)
        t->r->crg = t->crg;
    t->crg += 2;
    t->cnt = t->crg? t->totC : 0;
}

void upd(const pitem t) {
    if(!t) return;
    // push(t);
    push(t->l), push(t->r);
    t->totC = (t->l? t->l->totC : 0)  + (t->r? t->r->totC : 0) + t->maxR;
    t->cnt = cnt(t->l) + cnt(t->r) + (t->crg? t->maxR : 0);
}

void split(pitem t, const int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    upd(t);
}

void merge(pitem &t, const pitem l, const pitem r) {
    push(l), push(r);
    if(!l || !r)
        t = l? l : r ;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

pitem t = NULL;
set <int> poss;
int ls[limN], rs[limN], ks[limN];

int main() {
    srand(time(NULL));
    int N, Q;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<Q; i++) {
        scanf("%d%d%d", &ls[i], &rs[i], &ks[i]);
        poss.insert(ls[i]);
        poss.insert(rs[i]);
        ks[i] --;
    }
    poss.insert(1);
    poss.insert(N);

    int ult = 1;
    for(const int c:poss)  {
        if(ult + 1 < c)
            merge(t, t, new item(ult+1, c-1));
        merge(t, t, new item(c));
        ult = c;
    }

    // printf("%d %d %d\n", t->cnt, t->key, t->maxR);
    for(int i=0; i<Q; i++) {
        int l = ls[i], r = rs[i], k = ks[i];
        pitem a, b, c;
        split(t, l-1, a, b);
        split(b, r, b, c);
        // if(a)
        // printf("a: %d => %d %d %d\n", a->key, a->key, a->maxR, a->cnt);
        // if(b)
        // printf("b: %d => %d %d %d\n", b->key, b->key, b->maxR, b->cnt);
        // if(c)
        // printf("c: %d => %d %d %d\n", c->key, c->key, c->maxR, c->cnt);
        b->crg = k - 2;
        // if(b)
        //     printf("B: %d => %d %d %d (%d)\n", b->key, b->key, b->maxR, b->cnt, b->crg);
        merge(b, b, c);
        // if(b)
        //     printf("BC: %d => %d %d %d (%d)\n", b->key, b->key, b->maxR, b->cnt, b->crg);
        merge(t, a, b);
        printf("%d\n", cnt(t));
    }
}
