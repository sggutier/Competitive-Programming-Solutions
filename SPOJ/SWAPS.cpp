#include <bits/stdc++.h>
using namespace std;
const int H = 50000;
const int limN = 3e5 + 5;

struct Nodo {
    int cnt ;
    Nodo *ul, *ur, *dl, *dr;
    Nodo() : cnt(0), ul(NULL), ur(NULL), dl(NULL), dr(NULL){}
};

int N;
int txl, txr, tyl, tyr;

int _cnt(const Nodo* t, 
        const int xl=0, const int xr=N-1, const int yl=0, const int yr=H-1) {
    if(!t) return 0;
    if(xr < txl || txr < xl || yr < tyl || tyr < yl)
        return 0;
    if(xl > xr || yl > yr)
        return 0;
    // printf("Buscando intervalo %d %d a %d %d\n", txl, txr, tyl, tyr);
    // printf("\tActualmente en %d %d a %d %d\n", xl, xr, yl, yr);
    if(txl <= xl && xr <= txr && tyl <= yl && yr <= tyr) 
        return t->cnt;
    int px = (xl + xr) / 2, py = (yl + yr) / 2;
    return
        _cnt(t->dl,
            xl, px, yl, py) +
        _cnt(t->ul,
            xl, px, py+1, yr) +
        _cnt(t->dr,
            px+1, xr, yl, py) +
        _cnt(t->ur,
            px+1, xr, py+1, yr);
}

int cnt(const Nodo *t, const int _txl, const int _txr, const int _tyl, const int _tyr) {
    txl = _txl;
    txr = _txr;
    tyl = _tyl;
    tyr = _tyr;
    return _cnt(t);
}

void mete(Nodo* t, const int tx, const int ty, const int nov,
          int xl=0, int xr=N-1, int yl=0, int yr=H-1) {
    // printf("Metiendo %d en %d %d.\n  \tActualmente en %d %d a %d %d\n", nov, tx, ty, xl, xr, yl, yr);
    int px, py;
    while(true) {
        t->cnt += nov;
        if(xl == xr && yl == yr)
            return ;
        px = (xl + xr) / 2, py = (yl + yr) / 2;
        if(tx <= px) {
            if(ty <= py) {
                // printf("\tCuad dl\n");
                if(!t->dl)
                    t->dl = new Nodo();
                t = t->dl;
                xr = px, yr = py;
            }
            else {
                // printf("\tCuad ul\n");
                if(!t->ul)
                    t->ul = new Nodo();
                t = t->ul;
                xr = px, yl = py+1;
            }
        }
        else {
            if(ty <= py) {
                // printf("\tCuad dr\n");
                if(!t->dr)
                    t->dr = new Nodo();
                t = t->dr;
                xl = px+1, yr = py;
            }
            else {
                // printf("\tCuad ur\n");
                if(!t->ur)
                    t->ur = new Nodo();
                t = t->ur;
                xl = px+1, yl = py+1;
            }
        }
    }
}

Nodo *t = new Nodo();
long long ans = 0;
int arr[limN];

int main() {
    int Q;
    
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        a--;
        arr[i] = a;
        if(a+1 <= H-1 && i)
            ans += cnt(t, 0, i-1, a+1, H-1);
        mete(t, i, a, 1);
    }

    scanf("%d", &Q);
    while(Q--) {
        int x, y, z;
        scanf("%d%d", &x, &y);
        x--, y--;
        z = y;
        y = arr[x];
        if(y+1 <= H-1 && x)
            ans -= cnt(t, 0, x-1, y+1, H-1);
        if(y && x+1 <= N-1)
            ans -= cnt(t, x+1, N-1, 0, y-1);
        mete(t, x, y, -1);
        y = z;
        arr[x] = z;
        mete(t, x, y, 1);
        if(y+1 <= H-1 && x)
            ans += cnt(t, 0, x-1, y+1, H-1);
        if(y && x+1 <= N-1)
            ans += cnt(t, x+1, N-1, 0, y-1);
        printf("%lld\n", ans);
    }
}
