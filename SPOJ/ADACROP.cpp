#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef long long ll;

struct item {
    int key, prior;
    int cnt ;
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
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

void split(pitem t, const int k, pitem &l, pitem &r) {
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
        t = l? l : r ;
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

void erase(pitem &t, int k) {
    if(t->key == k) {
        pitem w;
        merge(w, t->l, t->r);
        delete t;
        t = w;
    }
    else
        erase(k < t->key? t->l : t->r, k);
    updCnt(t);
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
    map <int, pitem> aprs;
    int N, Q;
    int arr[limN];
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        insert(aprs[arr[i]], new item(i));
    }
    // for(auto p:aprs) {
    //     printf("Arbol de tipo %d\n", p.first);
    //     printa(p.second);
    // }
    while(Q--) {
        int idx, t ;
        scanf("%d%d", &idx, &t);
        auto ito = aprs.find(arr[idx]);
        erase(ito->second, idx);
        // printf("Borrado arbol de tipo %d\n", ito->first);
        // printa(ito->second);
        if(ito->second == NULL)
            aprs.erase(ito);
        pitem T = aprs[t];
        insert(T, new item(idx));
        // printf("Creando arbol de tipo %d\n", t);
        // printa(T);
        //printf("<%d %d>\n", pto->key, cnt(pto->l));
        pitem L, R;
        split(T, idx-1, L, R);
        printf("%d\n", cnt(L));
        merge(T, L, R);
        aprs[t] = T;
        arr[idx] = t;
    }
}
