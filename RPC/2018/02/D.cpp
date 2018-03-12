#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second

struct nodo {
    int dep;
    vector <int> xors;
    nodo *l, *r;
    nodo(int d) : dep(d), l(NULL), r(NULL) {}
    void mete(const int n) {
        if(dep==-1) return;
        if((1<<dep) & n) {
            if(!r) r = new nodo(dep-1);
            r->mete(n);
        }
        else {
            if(!l) l = new nodo(dep-1);
            l->mete(n);
        }
    }

    int calca(const int n) {
        if(dep==-1) return 0;
        if(xors.empty()) {
            xors.resize(1<<(dep+1));
            int w = 1<<dep;
            for(int b=(1<<(dep+1))-1; b>=0; b--) {
                if(b & w)
                    xors[b] = max(l? l->calca(b-w) : 0,
                                  r? 1 + r->calca(b-w) : 0);
                else
                    xors[b] = max(l? 1 + l->calca(b) : 0,
                                  r? r->calca(b) : 0);
            }
        }
        return xors[n];
    }

    void printa(int crg) {
        if(dep==-1) return;
        printf("%d => ", dep);
        for(int i=4; i>dep; i--)
            printf("%d", (1<<i) & crg? 1 : 0);
        printf("\n");
        for(int i=0; i<(1<<(dep+1)); i++)
            printf("%d %d\n", i, xors[i]);
        if(l) {
            l->calca(0);
            l->printa(crg);
        }
        if(r) {
            r->calca(0);
            r->printa(crg + 1<<dep);
        }
    }
};

nodo* T ;

int main() {
    int N, F;
    par ans(1e9, 0);

    scanf("%d%d", &N, &F);
    T = new nodo(F-1);
    for(int i=0; i<N; i++) {
        int s = 0;
        char tmp[30];
        scanf("%s", tmp);
        for(int j=0; j<F; j++)
            if(tmp[j]=='1')
                 s += (1<<(F-1-j));
//        for(int j=F-1; j>=0; j--)
//            printf("%d", (1<<j) & s? 1 : 0);
        T->mete(s);
    }

    for(int i=(1<<F)-1; i>=0; i--)
        ans = min(ans, {T->calca(i), i});
//    T->printa(0);
//    printf("%d %d\n", ans.f, ans.s);
    for(int i=F-1; i>=0; i--)
        printf("%d", (1<<i) & ans.s? 1 : 0);
    printf("\n");
}

