#include <bits/stdc++.h>
using namespace std;

struct item {
    int key, prior;
    int cnt;
    item *l, *r;
    item() {
    }
    item(int key) : key(key), prior(random()), cnt(1), l(NULL), r(NULL) {
    }
};
typedef item* pitem;

int cnt(const pitem t) {
    return t? t->cnt : 0;
}

void updCnt(const pitem t) {
    if(t)
        t -> cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(pitem t, int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updCnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

void insert(pitem &t, pitem it) {
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updCnt(t);
}

int kth(pitem t, int k) {
    while(true) {
        int a = cnt(t->l);
        if(k == a+1)
            return t->key;
        else if(k <= a)
            t = t->l;
        else {
            k -= a+1;
            t = t->r;
        }
    }
}

void printa(pitem t) {
    if(t==NULL)
        return;
    printf("%lld (%lld) =>", (ll) t->key, (ll) cnt(t));
    if(t->l)
        printf(" %lld", (ll) t->l->key);
    else
        printf(" x");
    if(t->r)
        printf(" %lld", (ll) t->r->key);
    else
        printf(" x");
    printf("\n");
    printa(t->l);
    printa(t->r);
}

int main() {
    pitem t = NULL;
    int N, Q;

    scanf("%d%d", &N, &Q);
    while(N--) {
        int a ;
        scanf("%d", &a);
        insert(t, new item(a));
    }
    //printa(t);
    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        if(a <= 2) {
            pitem l, r;
            split(t, b, l, r);
            int w = cnt(l);
            merge(t, l, r);
            if(a==1) {
                insert(t, new item(b+w));
            }
            else
                printf("%d\n", w);
        }
        else {
            if(cnt(t) < b)
                printf("invalid\n");
            else
                printf("%d\n", kth(t, b));
        }
        //printa(t);
    }
}
