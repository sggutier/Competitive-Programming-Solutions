#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second

ll MOD ;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}


pll getCyclLen(ll pos, ll a, ll x, ll y, ll &ciclT) {
    vector <int> lastT(MOD, -1);
    int t;
    ll firstApr = -1;
    for(t=0; lastT[pos] == -1; t++, pos = (pos * x + y) % MOD) {
        // printf("%lld\n", pos);
        lastT[pos] = t;
        if(pos == a)
            firstApr = t;
    }
    ciclT = lastT[pos] ;
    // printf("-- %d %d %lld\n", lastT[pos], t, pos);
    return {t - lastT[pos], firstApr};
}

int main() {
    scanf("%lld", &MOD);
    pll cs[2];
    ll cts[2];
    for(int i=0, h, a, x, y; i < 2; i++) {
        scanf("%d%d%d%d", &h, &a, &x, &y);
        cs[i] = getCyclLen(h, a, x, y, cts[i]);
    }
    if(cs[0].second == -1 || cs[1].second == -1) {
        printf("-1\n");
        return 0;
    }
    ll a = cs[0].first, b = -cs[1].first, c = cs[1].second - cs[0].second ;
    ll x, y ;
    if(c == 0) {
        printf("%lld\n", cs[0].second);
        return 0 ;
    }
    // printf(">> %lld, %lld  ==  %lld %lld\n", cs[0].second, cts[0], cs[1].second, cts[1]);
    ll g = euclid(a, b, x, y);
    // printf("%lld %lld\n", x, y);
    // printf("> %lld %lld\n", c, g);
    // printf("(%lld %lld),  (%lld, %lld)\n", cs[0].first, cs[0].second, cs[1].first, cs[1].second);
    if(c % g != 0) {
        printf("-1\n");
        return 0 ;
    }
    ll res = (c / g) *  a * x + cs[0].second;
    ll m = abs(b * (a / g));
    if(res < 0) {
        res += (-res / m) * m ;
        if(res < 0)
            res += m;
    }
    res %= m;
    if(res < cs[0].second || res < cs[1].second) {
        ll mx = max(cs[0].second, cs[1].second) ;
        res += ((mx - res) / m) * m;
        if(res < mx)
            res += m;
    }
    // printf("-- %lld\n", res);
    for(int i=0; i < 2; i++)
        if(cs[i].second < cts[i] && cs[i].second < res) {
            printf("-1\n");
            return 0 ;
        }
    printf("%lld\n", res);
}
