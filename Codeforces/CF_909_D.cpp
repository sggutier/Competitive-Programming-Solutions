#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7 ;

ll pot2(const int n) {
    if(n == 0) return 1 ;
    ll mit = pot2(n >> 1) ;
    return ((mit * mit)<<(n % 2)) % MOD ;
}

ll pot2_1M(const int n) {
    return (pot2(n) + MOD - 1) % MOD;
}

map <ll, ll> dp;

ll clcPre(int y) {
    auto it = dp.find(y) ;
    if(it != dp.end())
        return it->second ;
    if(y == 1) return 1 ;
    ll &ans = dp[y];
    ans = pot2_1M(y-1);
    for(int d=2; d*d <= y; d++) {
        if(y % d) continue ;
        int r = y / d ;
        ans = (ans - clcPre(r) + MOD) % MOD;
        if(r == d) continue ;
        ans = (ans - clcPre(d) + MOD) % MOD;
    }
    return ans ;
}

int main() {
    int x, y ;
    scanf("%d%d", &x, &y);
    printf("%lld\n", y%x? 0 : clcPre(y / x));
}
