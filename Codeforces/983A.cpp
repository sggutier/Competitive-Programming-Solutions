#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool funca(ll x, ll y, ll b) {
    ll g ;
    x = x%y;
    y /= __gcd(x, y);
    while(y>1) {
        g = __gcd(y, b);
        if(g==1)
            return false;
        while(y%g==0)
            y /= g;
    }
    return true;
}

int main() {
    int tc;
    ll a, b, c;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%s\n", funca(a,b,c)? "Finite": "Infinite");
    }
}
