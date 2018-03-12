#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

struct Nodo {
    int id;
    Nodo* dad = NULL;
    int maxD = 0;
    Nodo() {
    }
    Nodo(int k) {
        id = k;
    }
    Nodo* root() {
        Nodo* pos = this;
        while(pos->dad != NULL)
            pos = pos->dad;
        return pos;
    }
    void join(Nodo* otr) {
        Nodo *a = root(), *b = otr->root();
        if(a == b)
            return;
        if(a->maxD < b->maxD)
            swap(a, b);
        b->dad = a;
        a->maxD = max(a->maxD, b->maxD+1);
    }
};

int main() {
    int N, Q ;
    int csts[limN];
    Nodo nods[limN];

    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &csts[i]);
        nods[i].id = i;
    }
    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        nods[a].join(&nods[b]);
    }

    ll ans = 0;
    for(int i=0; i<N; i++) {
        int r = nods[i].root()->id;
        csts[r] = min(csts[i], csts[r]);
    }

    for(int i=0; i<N; i++)
        if(nods[i].root()->id == i)
            ans += csts[i];

    cout << ans << endl;
}
