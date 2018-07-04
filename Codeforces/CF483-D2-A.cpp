#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

bool itWorks(ll a) {
    ll b = a+1, c = a+2;
    return __gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1;
}

int main() {
    ll l, r ;
    cin >> l >> r;
    for(int d=0; d<2 && l+d+2<=r; d++) {        
        if(itWorks(l+d)) {
            printf("%lld %lld %lld\n", l+d, l+d+1, l+d+2);
            return 0;
        }
    }
    printf("-1\n");
}
