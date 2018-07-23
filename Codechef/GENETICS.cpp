#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 30005;

struct item {
    int ka, kb, kc, kd;
    int cnt, sa, sb, sc, sd;
    item *l, *r;
    item() {
    }
    item(int t) : cnt(1), l(NULL), r(NULL) {
        if(t==0) {
            sa = ka = 1;
            kb = kc = kd = sb = sc = sd = 0;
        }
        else if(t==1) {
            sb = kb = 1;
            ka = kc = kd = sa = sc = sd = 0;
        }
        else if(t==2) {
            sc = kc = 1;
            ka = kb = kd = sa = sb = sd = 0;
        }
        else {
            sd = kd = 1;
            ka = kb = kc = sa = sb = sc = 0;
        }
    }
    item(item *otr) ;
};
typedef item* pitem;

item::item(const pitem otr) {
    cnt = otr->cnt;
    l = otr->l;
    r = otr->r;
    ka = otr->ka;
    kb = otr->kb;
    kc = otr->kc;
    kd = otr->kd;
    sa = otr->sa;
    sb = otr->sb;
    sc = otr->sc;
    sd = otr->sd;
}

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void upd(pitem t) {
    if(t) {
        t -> cnt = 1 + cnt(t->l) + cnt(t->r);
        t -> sa = t->ka;
        t -> sb = t->kb;
        t -> sc = t->kc;
        t -> sd = t->kd;
        if(t->l) {
            t->sa += t->l->sa;
            t->sb += t->l->sb;
            t->sc += t->l->sc;
            t->sd += t->l->sd;
        }
        if(t->r) {
            t->sa += t->r->sa;
            t->sb += t->r->sb;
            t->sc += t->r->sc;
            t->sd += t->r->sd;
        }
    }
}

bool ordo(pitem A, pitem B) {
    return (ll)random() * (((ll) cnt(A)) + cnt(B)) < (ll)cnt(A) * RAND_MAX;
}

void split(pitem t, const int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < cnt(t->l) ) {
        t = new item(t);
        split(t->l, k, l, t->l), r = t;
    }
    else {
        t = new item(t);
        split(t->r, k-cnt(t->l)-1, t->r, r), l = t;
    }
    upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(ordo(l, r)) { //if(l->prior > r->prior)
        l = new item(l) ;
        merge(l->r, l->r, r), t = l;        
    }
    else {
        r = new item(r);
        merge(r->l, l, r->l), t = r;
    }
    upd(t);
}

tuple<int, int, int, int> getSum(pitem t, int k) {
    k++;
    int a=0, b=0, c=0, d=0;
    while(t) {
        int w = cnt(t->l) + 1;
        if(k < w)
            t = t->l;
        else {
            a += t->ka;
            b += t->kb;
            c += t->kc;
            d += t->kd;
            if(t->l) {
                a += t->l->sa;
                b += t->l->sb;
                c += t->l->sc;
                d += t->l->sd;
            }
            k -= w;
            t = t->r;
        }
    }
    return {a, b, c, d};
}

void printa(pitem t) {
    if(!t) return;
    printa(t->l);
    if(t->ka)
        printf("A");
    else if(t->kb)
        printf("G");
    else if(t->kc)
        printf("T");
    else if(t->kd)
        printf("C");
    printa(t->r);
}

void parb(pitem t) {
    printf("Arbo: ");
    printa(t);
    printf("\n");
}

int N ;
int vals[300];
pitem arbos[limN];

void count(int id, int l, int r) {
    int a, b, c, d;
    int w, x, y, z;
    tie(a, b, c, d) = getSum(arbos[id], r);
    tie(w, x, y, z) = getSum(arbos[id], l-1);
    printf("%d %d %d %d\n", a-w, b-x, c-y, d-z);
}

void mutate(int i, int pos, int nv) {
    // printf("Pos a mutar es %d, nv es %d\n", pos, nv);
    pitem x, y, z;
    split(arbos[i], pos-1, x, y);
    split(y, 0, y, z);
    // printf("X es "); parb(x);
    // printf("Y es "); parb(y);
    // printf("Z es "); parb(z);
    merge(y, new item(nv), z);
    merge(arbos[i], x, y);
    // printf("Nuevo arbol ahora es ");
    // parb(arbos[i]);
}

void cross(int a, int b, int k1, int k2) {
    pitem al, ar, bl, br;
    split(arbos[a], k1, al, ar);
    split(arbos[b], k2, bl, br);
    merge(arbos[N  ], al, br);
    merge(arbos[N+1], bl, ar);
    // printf("R1 es "); parb(arbos[N]);
    // printf("R2 es "); parb(arbos[N+1]);
    N += 2;
}

int main() {
    srandom(time(NULL));
    vals['A'] = 0;
    vals['G'] = 1;
    vals['T'] = 2;
    vals['C'] = 3;
    
    int Q;
    char tmp[limN];
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        for(char *c = tmp; *c; c++) {
            int w = vals[(int) *c];
            merge(arbos[i], arbos[i], new item(w));
        }
        // parb(arbos[i]);
    }
    // printf("-------\n");
    scanf("%d", &Q);
    while(Q--) {
        scanf("%s", tmp);
        if(tmp[1]=='O') {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            count(a-1, b-1, c-1);
        }
        else if(tmp[1]=='U') {
            int a, b;
            scanf("%d%d", &a, &b);
            scanf("%s", tmp);
            mutate(a-1, b-1, vals[(int) tmp[0]]);
        }
        else {
            int a, b, k1, k2;
            scanf("%d%d%d%d", &a, &b, &k1, &k2);
            a--, b--, k1--, k2--;
            cross(a, b, k1, k2);
        }
    }
}
