#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int l, r, x, y;
    set <ll> divs;
    int ans = 0;
    scanf("%d%d%d%d", &l, &r, &x, &y);
    
    for(int i=1; i*i<=y; i++) {
        if(y % i) continue;
        divs.insert(i);
        divs.insert(y/i);
    }

    for(ll a : divs) {
        if(a > r || a < l) continue;
        for(ll b : divs) {
            if(b > r || b < l) continue;
            ll g = __gcd(a, b);
            if(g != x) continue;
            if( (a/g)*b == y) {
                // printf("%lld %lld\n", a, b);
                ans ++;
            }
        }
    }
    printf("%d\n", ans);
}
