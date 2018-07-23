#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

typedef tuple<int, int, int> tri;

int N ;
char str[limN];
tri arb[5*limN];

tri comba(const tri l, const tri r) {
    int al, bl, cl, ar, br, cr;
    tie(al, bl, cl) = l;
    tie(ar, br, cr) = r;
    int t = min(bl, cr);
    return {al + ar + t,
            bl + br - t,
            cl + cr - t};
}

tri query(const int l, const int r, const int pos=0, const int L=1, const int R=N) {
    if(l <= L && R <= r)
        return arb[pos];
    if(r < L || R < l || L > R)
        return {0, 0, 0};
    int mt = (L + R) / 2;
    return comba(query(l, r, pos*2 + 1, L, mt),
                 query(l, r, pos*2 + 2, mt+1, R));
}

void mete(const int tgt, const tri nov, const int pos=0, const int L=1, const int R=N) {
    if(L==R) {
        arb[pos] = nov;
        return;
    }
    int mt = (L + R) / 2;
    if(tgt <= mt)
        mete(tgt, nov, pos*2 + 1, L, mt);
    else
        mete(tgt, nov, pos*2 + 2, mt+1, R);
    arb[pos] = comba(arb[pos*2+1], arb[pos*2 + 2]);
}

int main() {
    int Q ;
    scanf("%s", str);
    N = strlen(str);
    for(int i=0; i<N; i++) {
        tri nov ;
        if(str[i]=='(')
            nov = {0, 1, 0};
        else
            nov = {0, 0, 1};
        mete(i+1, nov);
    }
    scanf("%d", &Q);
    for(int i=0, a, b, w; i<Q; i++) {
        scanf("%d%d", &a, &b);
        tie(w, ignore, ignore) = query(a, b);
        printf("%d\n", 2*w);
    }
}
