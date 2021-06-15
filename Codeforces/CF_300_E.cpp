#include <bits/stdc++.h>
using namespace std;
const int limN = 1e7 ;
typedef long long ll;

bitset <limN> isComp;
int mca[limN + 5];

ll getR(ll n, const ll p) {
    ll ans = 0;
    while(n > 1) {
        n /= p;
        ans += n;
    }
    return ans;
}

ll getMaxN(ll p, ll req) {
    ll ini = 0, fin = 1e14;
    ll pv ;
    while(ini < fin) {
        pv = (ini + fin) / 2;
        if(getR(pv, p) < req)
            ini = pv + 1;
        else
            fin = pv;
    }
    return ini;
}

ll calcaPrim(ll p) {
    // printf("calcando prim %lld\n", p);
    ll crg = 0;
    int w, a ;
    for(int i=limN - limN % p; i > 0; i-= p) {
        w = 0;
        a = i;
        while(a % p == 0) {
            a /= p;
            w ++;
        }
        crg += mca[i] * w;
    }
    return getMaxN(p, crg);
}

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!isComp[i])
            for(int j=i*i; j<limN; j+=i)
                isComp[j] = true;    
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        mca[a] ++;
    }
    for(int i=limN; i>=0; i--)
        mca[i] += mca[i+1];

    criba();

    ll ans = 1, w;
    for(int i=2; i<limN; i++)
        if(!isComp[i]) {
            w = calcaPrim(i);
            ans = max(ans, w);
            // if(w)
            //     printf("%d => %lld\n", i, w);
        }

    printf("%lld\n", ans);
}
