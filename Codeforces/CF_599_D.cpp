#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2e6 ;

bool calcC(ll n, ll r, ll &c) {
    ll num = (6*n + r*r*r - r);
    ll den = (3*r * (r + 1));
    if(num % den)
        return false;
    c = num / den;
    return true;
}

vector < pair<ll, ll> > ans;

int main() {
    ll n, r, c ;
    scanf("%lld", &n);

    for(r=1; r + 1 <= limN; r++)
        if(calcC(n, r, c)) {
            if( r > c ) break;
            ans.emplace_back(r, c);
        }
    for(r--; r > 0; r--)
        if(calcC(n, r, c))
            if( r != c)
                ans.emplace_back(c, r);
    printf("%d\n", (int) ans.size());
    for(const auto p : ans)
        printf("%lld %lld\n", p.first, p.second);
}
