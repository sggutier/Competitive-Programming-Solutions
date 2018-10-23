#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int mod = 1000000009;

struct nodo {
    nodo* padr = NULL ;
    nodo* raiz() {
        if(padr == NULL)
            return this;
        return padr = padr->raiz();
    }
    bool une(nodo *b) {
        nodo* a = raiz();
        b = b->raiz();
        if(a == b)
            return false;
        b->padr = a;
        return true;
    }
};

nodo uf[limN];

int main() {
    int N, E;
    int ans = 1;
    scanf("%d%d", &N, &E);
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        if(!uf[a].une(&uf[b]))
            ans = (ans * 2) % mod;
        printf("%d\n", (ans + mod - 1) % mod);
    }
}
