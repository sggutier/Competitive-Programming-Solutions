#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

bool itWorks(int N, int *cst, int* hav, ll req, ll p) {
    for(int i=0; i<N; i++) {
        ll w = max(0LL, req*cst[i] - hav[i]);
        if(p < w)
            return false;
        p -= w;
    }
    return true;
}

int main() {
    int N, p;
    int cst[limN], hav[limN];
    ll ini=0, fin=2000000000;

    scanf("%d%d", &N, &p);
    for(int i=0; i<N; i++)
        scanf("%d", &cst[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &hav[i]);

    while(ini < fin) {
        ll piv = (ini+fin)/2 + 1;
        if(itWorks(N, cst, hav, piv, p))
            ini = piv;
        else
            fin = piv-1;
    }

    printf("%d\n", (int) ini);
}
