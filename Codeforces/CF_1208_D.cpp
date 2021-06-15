#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2e5 + 5;

class STree {
private:
    class Nodo {
    public:
        pair<ll, int> minP;
        ll crg;
        Nodo *lc, *rc;
        Nodo() : minP({0, 1}), crg(0), lc(NULL), rc(NULL) {}
    };

    void push(Nodo* nod);

    Nodo *rt;
    int N ;

    void createTree(Nodo* nod, const ll *arr, const int l, const int r);

    void update(const ll nov, const int tgtL, const int tgtR, Nodo* nod, const int l, const int r);
public:
    STree(const int N, const ll *arr) ;

    void update(const ll nov, const int ini, const int fin) {
        update(nov, ini, fin, rt, 0, N-1);
    }

    int getMinPos() {
        return -rt->minP.second;
    }
};

void STree::update(const ll nov, const int tgtL, const int tgtR, Nodo* nod, const int l, const int r) {
    if(r < tgtL || tgtR < l) {
        push(nod);
        return;
    }
    if(tgtL <= l && r <= tgtR) {
        nod->crg += nov;
        push(nod);
        // printf("Neoval de %d a %d: %lld y %d\n", l, r, nod->minP.first, nod->minP.second);
        return;
    }
    push(nod);
    const int mit = (l + r) / 2;
    update(nov, tgtL, tgtR, nod->lc, l, mit);
    update(nov, tgtL, tgtR, nod->rc, mit+1, r);
    nod->minP = min(nod->lc->minP, nod->rc->minP);
    // printf("Neoval de %d a %d: %lld y %d\n", l, r, nod->minP.first, nod->minP.second);
}

STree::STree(const int _N, const ll *arr) : N(_N){
    rt = new Nodo();
    createTree(rt, arr, 0, N-1);
}

void STree::push(Nodo* nod) {
    if(nod->crg == 0)
        return;
    nod->minP.first += nod->crg;
    if(nod->lc) {
        nod->lc->crg += nod->crg;
        nod->rc->crg += nod->crg;
    }
    nod->crg = 0;
}

void STree::createTree(Nodo* nod, const ll *arr, const int l, const int r) {
    if(l == r) {
        nod->minP.first = arr[l];
        nod->minP.second = -l;
        return;
    }
    nod->lc = new Nodo();
    nod->rc = new Nodo();
    const int mit = (l + r) / 2;
    createTree(nod->lc, arr, l, mit);
    createTree(nod->rc, arr, mit+1, r);
    nod->minP = min(nod->lc->minP, nod->rc->minP);
    // printf("arbol de %d a %d => %lld %d\n", l, r, nod->minP.first, nod->minP.second);
}

STree *arb;

int main() {
    int N ;
    ll nums[limN];
    int anso[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lld", &nums[i]);
    }
    arb = new STree(N, nums);

    for(int d=1; d<=N; d++) {
        int pos = arb->getMinPos();
        anso[pos] = d;
        if(pos + 1 <= N)
            arb->update(-d, pos+1, N);
        arb->update(1e18, pos, pos);
    }

    for(int i=0; i<N; i++)
        printf("%d%c", anso[i], i==N-1? '\n' : ' ');
}
