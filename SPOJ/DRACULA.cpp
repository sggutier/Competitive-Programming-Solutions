#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_D = 18;
const int LIM_C = 9 * LIM_D;

bool usdDpInt[LIM_D + 5][LIM_C + 1];
ll dpInt[LIM_D + 5][LIM_C + 1];

ll memoInt(int remP, int remC) {
    if(remP == 0)
        return remC == 0? 1 : 0;
    if(usdDpInt[remP][remC])
        return dpInt[remP][remC];
    usdDpInt[remP][remC] = true;
    auto &ans = dpInt[remP][remC];
    for(int i=min(9, remC); i >= 0; i--) {
        ans += memoInt(remP - 1, remC - i);
    }
    return ans;
}

ll countCoinWays(const ll n, const ll c, const ll pot10 = 1e18, const int pos = 18) {
    if(c == 0)
        return 1 ;
    if(c < 0)
        return 0 ;
    if(pos == -1)
        return 0 ;
    int d = n / pot10;
    ll ans = countCoinWays(n - pot10 * d, c - d, pot10 / 10, pos - 1) ;
    for(int i=min(d-1LL, c); i >= 0; i--)
        ans += memoInt(pos, c - i);
    return ans;
}

ll testCase(ll a, ll b, ll k) {
    if(b < a)
        swap(a, b);
    a = max(0LL, a-1);
    ll ans = 0 ;
    for(ll i=1; i <= LIM_C; i++) {
        ll cnt = countCoinWays(b, i) - countCoinWays(a, i);
        ll rp = min(k / i, cnt);
        ans += rp;
        k -= rp * i;
    }
    return ans ;
}

int smDig(ll n) {
    int ans = 0 ;
    while(n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

ll chafTC(ll a, ll b, ll k) {
    vector <ll> cntDigs(LIM_C);
    for(ll i=a; i <= b; i++) {
        cntDigs[smDig(i)]++;
    }
    ll ans = 0 ;
    for(ll i=1; i <= LIM_C; i++) {
        ll cnt = cntDigs[i];
        ll rp = min(k / i, cnt);
        ans += rp;
        k -= rp * i;
    }
    return ans ;
}

int main() {
    int tc ;
    ll a, b, c ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", testCase(a, b, c));
    }
}
