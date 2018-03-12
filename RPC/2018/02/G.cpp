#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef pair<int, int> par;
#define f first
#define s second

struct Nodo {
    int cnt, tot;
    par val;
    int prio;
    Nodo *l, *r;
    Nodo(const par _val) : cnt(1), tot(1), prio(rand()), val(_val), l(NULL), r(NULL) {}
    Nodo(const par _val, int n) : cnt(n), tot(n), prio(rand()), val(_val), l(NULL), r(NULL) {}
};
typedef Nodo* NodoP;

int tot(NodoP t) {
    return t? t->tot : 0;
}

void upd(NodoP t) {
    if(!t) return;
    t->tot = t->cnt + tot(t->l) + tot(t->r);
}

int poss(NodoP t) {
    if(!t) return 0;
    return tot(t->l);
}

void split(const NodoP t, const par k, NodoP &L, NodoP &R) {
    if(!t) L = R = NULL;
    else if(t->val <= k)
        split(t->r, k, t->r, R), L = t;
    else
        split(t->l, k, L, t->l), R = t;
    upd(t);
}

void merga(NodoP &t, const NodoP L, const NodoP R) {
    if(!L || !R)
        t = L? L : R;
    else if(L->prio > R->prio)
        merga(L->r, L->r, R), t = L;
    else
        merga(R->l, L, R->l), t = R;
    upd(t);
}

void printa(NodoP t) {
    if(!t) return;
    printf("%d => %d %d (%d %d)\n", t, t->val.f, t->val.s, t->tot, t->cnt);
    printf("\t%d %d\n", t->l, t->r);
    printa(t->l);
    printa(t->r);
}

int pty[limN], probs[limN];
NodoP t = NULL;

int main() {
    srand(time(NULL));
    int N, E;
    scanf("%d%d", &N, &E);
    t = new Nodo({0, 0}, N);
    for(int i=0, x, y; i<E; i++) {
        scanf("%d%d", &x, &y);
        x--;
        par ant({-probs[x], pty[x]});
        probs[x]++, pty[x] += y;
        par nov({-probs[x], pty[x]}), uno({-probs[0], pty[0]-1});
        NodoP a, b, c;

//        printf("Antes de todo el arbol es\n");
//        printa(t);
        split(t, ant, b, c);
        split(b, {ant.f, ant.s-1}, a, b);
        if(b->cnt > 1) {
//            printf("Aca %d %d\n", b->val.f, b->val.s);
            b->cnt --;
            b->tot--;
            merga(b, a, b);
            merga(t, b, c);
        }
        else {
            delete b;
            b = NULL;
            merga(t, a, c);
        }
//        printf("Despues del primer cambio es\n");
//        printa(t);

        split(t, nov, b, c);
        split(b, {nov.f, nov.s-1}, a, b);
//        printf("Los subarboles son\n");
//        printf("A:\n");
//        printa(a);
//        printf("B:\n");
//        printa(b);
//        printf("C:\n");
//        printa(c);
//        printf("Despues mete %d %d => %d %d\n", ant.f, ant.s, nov.f, nov.s);
        if(b) {
            b->cnt ++;
            b->tot++;
        }
        else
            b = new Nodo(nov);
//        printf("B especificamente es\n");
//        printa(b);
//        printf("Y A es\n");
//        printa(a);
        merga(b, a, b);
//        printf("La merga es\n");
//        printa(b);
        merga(t, b, c);
//        printf("El final es\n");
//        printa(t);

        split(t, uno, a, b);
        printf("%d\n", tot(a) + 1);
        merga(t, a, b);
    }
}
