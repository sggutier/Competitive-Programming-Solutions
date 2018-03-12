#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item {
    int key, prior;
    int crg;
    int cnt;
    item *l, *r;
    item(int key) : key(key), prior(rand()), crg(0), cnt(1), l(NULL), r(NULL) {}
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
        t->key += t->crg;
        if(t->l) t->l->crg += t->crg;
        if(t->r) t->r->crg += t->crg;
        t->crg = 0;
    }
}

void cga(pitem t, int s=1) {
    if(t) t->crg += s;
}

void split(pitem t, int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updCnt(t);
}

void insert(pitem &t, pitem it) {
    push(t);
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updCnt(t);
}

void printa(pitem t) {
    if(t==NULL)
        return;    
    printa(t->l);
    printf("%d\n", t->key);
    printa(t->r);
}

int cntMen(pitem t, int k) {
    int ans = 0;
    while(t) {
        push(t);
        if(k < t->key)
            t = t->l;
        else {
            ans += cnt(t->l) + 1;
            t = t->r;
        }
    }
    return ans;
}

int main() {
    srand(time(NULL));
    pitem t = new item(0);
    int N, K;
    int ans = 0;
    scanf("%d%d", &N, &K);
    K --;
    for(int i=1; i<=N; i++) {
        int a ;
        scanf("%d", &a);
        a = max(a, i);
        cga(t, 1);
        insert(t, new item(a));
        // printf("T ahora es\n");
        // printa(t);
        ans = max(ans, cntMen(t, K)-1);
    }
    printf("%d\n", ans);
}
