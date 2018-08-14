#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 5e5;

int K, mod;
int minD[limN];

void calca(int ini) {
    minD[ini] = 0;
    for(int i=ini+1; i<mod; i++) {
        minD[i] = minD[i-1] + 1;
        for(int d=2; d<=K; d++)
            if(i - i%d >= ini)
                minD[i] = min(minD[i], minD[i - i%d] + 1);
    }
}

int main() {
    ll ini, fin;
    ll ans = 0;
    scanf("%lld%lld%d", &ini, &fin, &K);

    mod = 1;
    for(int i=2; i<=K; i++)
        mod *= i / __gcd(i, mod);

    calca(0);
    if(ini / mod != fin / mod) {
        ans += minD[ini % mod] + 1;
        ini = ini - ini%mod -1;
    }
    ans += (ini/mod - fin/mod) * (minD[mod-1] + 1);
    calca(fin % mod);
    ans += minD[ini%mod];

    printf("%lld\n", ans);
}
