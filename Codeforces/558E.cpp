#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limC = 26;

struct item {
    int prior, cnt;
    int val;
    int crg;
    int lets[limC];
    item *l, *r;

    item() {}
    item(int v) : prior(rand()), cnt(1), val(v), crg(0), l(NULL), r(NULL) {
        for(int i=0; i<limC; i++)
            lets[i] = 0;
        lets[v] = 1;
    }
};
typedef item* pitem;

int cnt(const pitem t) {
    return t? t->cnt : 0;
}

int ipos(const pitem t) {
    return cnt(t->l);
}

void push(const pitem t) {
    if(!t || !t->crg)
        return;
    int p = ipos(t);
    if(t->l) {
        for(int i=0; i<limC; i++)
            t->l->lets[i] = 0;
        t->l->crg = t->crg;
    }
    if(t->r) {
        for(int i=0; i<limC; i++)
            t->r->lets[i] = 0;
        t->r->crg = t->crg;
    }
    for(int i=0, s=0; i<limC; i++) {
        s += t->lets[i];
        if(s <= p) {
            if(t->lets[i]) {
                t->l->lets[i] = t->lets[i];
            }
        }
        else {
            int al, ar;
            ar = s-(p+1);
            al = t->lets[i] -ar-1;
            t->val = i;
            if(al > 0) {
                t->l->lets[i] = al;
            }
            if(ar > 0) {
                t->r->lets[i] = ar;
            }
            for(i++; i<limC; i++) {
                if(t->lets[i]) {
                    t->r->lets[i] = t->lets[i];
                }
            }
        }
    }
    if(t->crg > 1)
        swap(t->l, t->r);
    t->crg = 0;
}

void upd(pitem t) {
    if(!t) return;
    for(int i=0; i<limC; i++) {
        t->lets[i] = 0;
        if(t->l)
            t->lets[i] += t->l->lets[i];
        if(t->r)
            t->lets[i] += t->r->lets[i];
    }
    t->lets[t->val]++;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

void split(const pitem t, const int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < ipos(t))
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k-ipos(t)-1, t->r, r), l = t;
    upd(t);
}

void merge(pitem &t, const pitem l, const pitem r) {
    push(l), push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}


void printaT(pitem t)  {
    if(!t) return;
    push(t);
    printaT(t->l);
    printf("%c", t->val + 'a');
    printaT(t->r);
}

pitem t = NULL;

int main() {
    srand(time(NULL));
    int N, Q ;
    char str[limN];

    scanf("%d%d", &N, &Q);
    scanf("%s", str);
    for(int i=0; i<N; i++) {
        merge(t, t, new item(str[i]-'a'));
    }
    
    while(Q--) {
        int c, a, b;
        pitem x, y, z;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c = 2-c;
        split(t, a-1, x, y);
        split(y, b-a, y, z);
        y->crg = c;
        merge(y, y, z);        
        merge(t, x, y);
    }

    printaT(t);
    printf("\n");
}
