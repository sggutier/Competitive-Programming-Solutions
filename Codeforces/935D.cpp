#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 400005;
const int limB = 21;

struct Nodo {
    Nodo* ancos[limB];
    ll sumos[limB];
    ll w ;
    int dep;
    int id;
    Nodo() {
        for(int i=0; i<limB; i++) {
            ancos[i] = NULL;
            sumos[i] = 0;
        }
        w = 0;
        dep = 0;
    }
    Nodo(Nodo* p, ll _w, int _id) : w(_w), id(_id) {
        if(p->w < w) {
            for(int i=limB-1; i>=0 && p; i--) {
                Nodo *sg = p->ancos[i];
                if(sg && sg->w < w) {
                    p = sg;
                }
            }
            if(p && p->w < w)
                p = p->ancos[0];
        }
        dep = p? p->dep + 1 : 0;
        
        for(int i=0; i<limB; i++) {
            ancos[i] = NULL;
            sumos[i] = 0;
        }

        ll s = w;
        for(int i=0; i<limB; i++) {
            ancos[i] = p;
            sumos[i] = s;
            if(p) {
                s += p->sumos[i];
                p = p->ancos[i];
            }
        }
    }

    int buscaS(ll maxS) {
        if(w > maxS)
            return 0;
        Nodo* p = ancos[0];
        ll s = w;
        for(int i=limB-1; i>=0 && p; i--) {
            Nodo *sg = p->ancos[i];
            if(p->sumos[i] + s <= maxS) {
                s += p->sumos[i];
                p = sg;
            }
        }
        return dep - (p? p->dep : -1);
    }
};

Nodo* arbos[limN];

int main() {
    ll last = 0;
    int Q ;
    int t ;
    ll a, b ;
    int cnt = 1;

    arbos[1] = new Nodo();
    
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d%lld%lld", &t, &a, &b);
        a ^= last;
        b ^= last;
        if(t==1) {
            cnt ++;
            arbos[cnt] = new Nodo(arbos[a], b, cnt);
        }
        else {
            last = arbos[a]->buscaS(b);
            printf("%lld\n", last);
        }
    }
}
