#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

struct item {
    int key, prior;
    int cnt;
    item *l, *r;
    item() {
    }
    item(int key) : key(key), prior(random()), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updCnt(pitem t) {
    if(t)
        t -> cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(const pitem t, const int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updCnt(t);
}

void merge(pitem &t, const pitem l, const pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

void insert(pitem &t, const pitem it) {
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updCnt(t);
}

void erase(pitem &t, const int k) {
    if(!t)
        return;
    else if(t->key == k) {
        pitem w ;
        merge(w, t->l, t->r);
        delete t;
        t = w;
    }
    else
        erase(k < t->key? t->l : t->r, k);
    updCnt(t);
}

int kth(pitem t, int k) {
    while(t) {
        int w = cnt(t->l) + 1;
        if(w == k)
            return t->key;
        else if(k < w)
            t = t->l;
        else {
            k -= w;
            t = t->r;
        }
    }
    return -1;
}

int getIdx(pitem t, int k) {
    int prec = 0;
    while(t) {
        if(t->key == k)
            return prec + cnt(t->l) + 1;
        else if(k < t->key)
            t = t->l;
        else {
            prec += cnt(t->l) + 1;
            t = t->r;
        }
    }
    return -1;
}

// void printa(pitem t) {
//     if(t==NULL)
//         return;
//     printf("%lld (%lld) =>", (ll) t->key, (ll) cnt(t));
//     if(t->l)
//         printf(" %lld", (ll) t->l->key);
//     else
//         printf(" x");
//     if(t->r)
//         printf(" %lld", (ll) t->r->key);
//     else
//         printf(" x");
//     printf("\n");
//     printa(t->l);
//     printa(t->r);
// }

int main() {
    pitem t = NULL;
    int d, n;
    while(scanf("%d", &d)!=EOF && d!=-1) {
        scanf("%d", &n);
        if(d==1)
            insert(t, new item(n));
        else if(d==2)
            erase(t, n);
        else if(d==3)
            printf("%d\n", getIdx(t, n));
        else {
            printf("%d\n", cnt(t) < n? -1 : kth(t, n));
        }
        //printa(t);
    }
}
