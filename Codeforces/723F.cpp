#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<int, par> tri;
#define f first
#define s second
const int limN = 2e5 + 5;

struct nodo {
    nodo *pde;
    int dep;
    nodo() : pde(NULL), dep(0) {}
    nodo* root() {
        nodo* pos = this;
        while(pos->pde != NULL)
            pos = pos->pde;
        return pos;
    }
    bool mismo(nodo *b) {
        nodo *a = this->root();
        b = b->root();
        return a==b;
    }
    bool join(nodo *b) {
        nodo *a = this->root();
        b = b->root();
        if(a==b)
            return false;
        if(a->dep < b->dep)
            swap(a, b);
        b->pde = a;
        a->dep = max(a->dep, b->dep+1);
        return true;
    }
};

tri edges[2*limN];
int uneS[limN];
int uneT[limN];

int main() {
    int N, E;
    nodo nodos[limN];
    int s, t, ds, dt;

    scanf("%d%d", &N, &E);
    for(int i=1; i<=E; i++) {
        scanf("%d%d", &edges[i].s.f, &edges[i].s.s);
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt);
    for(int i=1; i<=E; i++) {
        if(edges[i].s.f == s || edges[i].s.s == s)
            continue;
        if(edges[i].s.f == t || edges[i].s.s == t)
            continue;
        if(nodos[edges[i].s.f].join(&nodos[edges[i].s.s])) {
            edges[i].f = -10;
            // printf("defo %d %d\n", edges[i].s.f, edges[i].s.s);
        }
        else
            edges[i].f = -5;
    }

    for(int i=1; i<=E; i++) {
        if(edges[i].f < 0)
            continue;
        if((edges[i].s.f == s || edges[i].s.s == s) && (edges[i].s.f == t || edges[i].s.s == t))
            continue;
        else if(edges[i].s.f == s || edges[i].s.s == s) {
            int p = edges[i].s.f != s? edges[i].s.f : edges[i].s.s;
            p = (nodos[p].root()) - nodos;
            uneS[p] = i;
        }
        else if(edges[i].s.f == t || edges[i].s.s == t) {            
            int p = edges[i].s.f != t? edges[i].s.f : edges[i].s.s;
            p = (nodos[p].root()) - nodos;
            uneT[p] = i;
        }
    }

    // for(int i=1; i<=N; i++) {
    //      printf("%d %d\n", uneS[i], uneT[i]);
    // }

    for(int i=1; i<=N; i++) {
        if( (uneS[i]!=0) ==  (uneT[i]!=0) )
            continue;
        if(uneS[i]) {
            int w = uneS[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            ds--;            
            // printf("Conectando %d %d\n", edges[w].s.f, edges[w].s.s);
        }
        else {
            int w = uneT[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            dt--;
            // printf("Conectando %d %d\n", edges[w].s.f, edges[w].s.s);
        }
    }
    bool funco = false;
    for(int i=1; i<=N; i++) {
        if(uneS[i]==0 || uneT[i]==0 )
            continue;
        if(!funco) {
            int w = uneS[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            // printf("doso %d %d Conectando %d %d\n", i, w, edges[w].s.f, edges[w].s.s);
            w = uneT[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            // printf("dosooo %d %d Conectando %d %d\n", i, w, edges[w].s.f, edges[w].s.s);
            ds--, dt--;
            funco = true;
        }
        else if(ds>0) {
            int w = uneS[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            // printf("doso %d %d Conectando %d %d\n", i, w, edges[w].s.f, edges[w].s.s);
            ds--;
        }
        else if(dt>0) {
            int w = uneT[i];
            edges[w].f = -10;
            nodos[edges[w].s.f].join(&nodos[edges[w].s.s]);
            // printf("doso %d %d Conectando %d %d\n", i, w, edges[w].s.f, edges[w].s.s);
            dt--;
        }
    }
    if(!funco) {
        for(int i=1; i<=E; i++) {
            if((edges[i].s.f == s || edges[i].s.s == s) && (edges[i].s.f == t || edges[i].s.s == t)) {
                nodos[edges[i].s.f].join(&nodos[edges[i].s.s]);
                edges[i].f = -10;
                ds--, dt--;
                // printf("abacadabs\n");
            }
        }
    }
    // printf("%d %d\n", ds, dt);
    // for(int i=1; i<=N; i++) {
    //     printf("%d => %d\n", i, (int) (nodos[i].root()-nodos));
    // }

    bool funca = true;
    if(ds < 0 || dt < 0) {
        funca = false;
    }
    else {
        for(int i=1; i<N; i++)
            if(nodos[i].root() != nodos[N].root())
                funca = false;
    }
    
    if (funca) {
        printf("Yes\n");
        for(int i=1; i<=E; i++)
            if(edges[i].f == -10)
                printf("%d %d\n", edges[i].s.f, edges[i].s.s);
    }
    else
        printf("No\n");

    return 0;
}
