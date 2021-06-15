#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
#define lch(x) (x*2 + 1)
#define rch(x) (x*2 + 2)

int N ;
int cols[limN];
ll crg[limN*6];
ll sms[limN*6];
int uniCol[limN*6];

void push(const int pos, const int len) {
    if(!crg[pos]) return;
    sms[pos] += crg[pos] * len;
    crg[lch(pos)] += crg[pos];
    crg[rch(pos)] += crg[pos];
    crg[pos] = 0;
}

void insert(const ll nv, const int tl, const int tr,
            const int pos = 0, const int L = 0, const int R = N-1) {
    push(pos, R-L+1);
    if(tr < L || R < tl)
        return;
    if(tl <= L && R <= tr) {
        crg[pos] += nv;
        push(pos, R-L+1);
        return;
    }
    const int piv = (L + R) / 2;
    insert(nv, tl, tr, lch(pos), L, piv);
    insert(nv, tl, tr, rch(pos), piv+1, R);
    sms[pos] = sms[lch(pos)] + sms[rch(pos)] ;
}

ll query(const int tl, const int tr,
         const int pos = 0, const int L = 0, const int R = N-1) {
    if(tr < L || R < tl)
        return 0;
    push(pos, R-L+1);
    if(tl <= L && R <= tr)
        return sms[pos];
    const int piv = (L + R) / 2;
    return query(tl, tr, lch(pos), L, piv)
        + query(tl, tr, rch(pos), piv+1, R);
}

void cmbCols(const int nv, const int tl, const int tr,
            const int pos = 0, const int L = 0, const int R = N-1) {
    if(tr < L || R < tl)
        return;
    if(tl <= L && R <= tr && uniCol[pos] != -1) {
        insert(abs(nv - uniCol[pos]), L, R);
        uniCol[pos] = nv;
        return ;
    }
    int &lc = uniCol[lch(pos)];
    int &rc = uniCol[rch(pos)];
    if(uniCol[pos] != -1)
        lc = rc = uniCol[pos];
    const int piv = (L + R) / 2;
    cmbCols(nv, tl, tr, lch(pos), L, piv);
    cmbCols(nv, tl, tr, rch(pos), piv+1, R);
    uniCol[pos] = (lc == rc)? lc : -1 ;
}

void hazArb(const int pos = 0, const int L = 0, const int R = N-1) {
    if(L == R) {
        uniCol[pos] = cols[L];
        return;
    }
    const int piv = (L + R) / 2;
    hazArb(lch(pos), L, piv);
    hazArb(rch(pos), piv+1, R);
    const int lc = uniCol[lch(pos)];
    const int rc = uniCol[rch(pos)];
    uniCol[pos] = (lc == rc)? lc : -1 ;
}

int main() {
    int Q ;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++)
        cols[i] = i+1;

    hazArb();
    for(int q=0, t, l, r, x; q<Q; q++) {
        scanf("%d%d%d", &t, &l, &r);
        l--, r-- ;
        if(t == 1) {
            scanf("%d", &x);
            cmbCols(x, l, r);
        }
        else
            printf("%lld\n", query(l, r));
    }
}
