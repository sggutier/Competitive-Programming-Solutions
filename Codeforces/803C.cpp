#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool funca(ll s, ll k) {
    return (k*(k+1))/2 <= s;
}

int main() {
    ll n, k ;
    set <ll> divs;
    scanf("%lld%lld", &n, &k);
    if(k > 1e6) {
        printf("-1\n");
        return 0;
    }
    for(ll i=1; i*i<=n; i++) {
        if(n%i) continue;
        divs.insert(-i);
        divs.insert(-n/i);
    }
    for(ll d : divs) {
        if(funca(-n/d, k)) {
            d *= -1;
            ll s = 0;
            for(int i=1; i<k; i++) {
                s += i*d;
                printf("%lld ", i*d);
            }
            printf("%lld\n", n-s);
            return 0;
        }
    }
    printf("-1\n");
}
