#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second
const int limB = 1<<22;
const int mt = 20;
const ll inf = 9223372036854775807;

int W = 1;
pll ords[limB];

void precalca(int N, ll* vals, ll* wts) {
    if(N<=0) return;
    for(int msk=(1<<N)-1; msk>=0; msk--) {
        ll a = 0, b = 0;
        for(int i=0; i<N; i++) {
            if((1<<i) & msk) continue;
            a += vals[i];
            b += wts[i];
        }
        ords[W++] = {b, a};
    }
    sort(ords, ords+W);
    for(int i=1; i<W; i++) {
        ords[i].s = max(ords[i].s, ords[i-1].s);
    }
}

ll maxVal(ll k) {
    if(k<0) return 0;
    int pos = upper_bound(ords, ords+W, pll(k, inf)) - ords;
    pos --;
    // printf("buscando %lld encontre %lld %lld\n", k, ords[pos-1].f, ords[pos-1].s);
    return ords[pos].s;
}

int main() {
    int N ;
    ll maxW ;
    ll vals[50], wts[50];
    ll ans = 0;
    scanf("%d%lld", &N, &maxW);
    for(int i=0; i<N; i++)
        scanf("%lld%lld", &vals[i], &wts[i]);
    precalca(N-mt, vals + mt, wts + mt);
    N = min(N, mt);
    for(int msk=(1<<N)-1; msk>=0; msk--) {
        ll a = 0, b = 0;
        for(int i=0; i<N; i++) {
            if((1<<i) & msk) continue;
            a += vals[i];
            b += wts[i];
        }
        if(b > maxW)
            continue;
        ans = max(ans, a + maxVal(maxW - b));
    }
    printf("%lld\n", ans);
}
