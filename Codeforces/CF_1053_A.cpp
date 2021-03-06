#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;
ll pd;

bool fca(ll w) {
    ll rm = pd/w;
    return w <= n && rm <= m;
}

void psol(ll w) {
    ll rm = pd/w;
    printf("YES\n");
    printf("%lld %lld\n", 0LL, 0LL);
    printf("%lld %lld\n", w, 0LL);
    printf("%lld %lld\n", 0LL, rm);
}

vector <ll> getDs(ll w) {
    vector <ll> ans ;
    for(ll i=1; i*i<=w; i++) {
        if(w %i) continue;
        ll rm = w/i;
        ans.push_back(i);
        if(rm != i)
            ans.push_back(rm);
    }
    // for(const ll x : ans)
    //     printf("%lld\n", x);
    return ans;
}

int main() {
    cin >> n >> m >> k ;
    pd = n*m*2;
    if(pd % k) {
        printf("NO\n");
        return 0 ;
    }
    pd /= k;

    vector<ll> a = getDs(2*n), b = getDs(m);

    ll t ;
    // printf("pd = %lld\n", pd);
    for(const ll x : a) {
        for(const ll y : b) {
            t = x*y;
            if(pd % t == 0 && fca(t)) {
                psol(t);
                return 0;
            }
        }
    }

    printf("NO\n");
}
