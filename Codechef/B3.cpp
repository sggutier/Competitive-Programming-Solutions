// - The position (x, y) can be sunk iff gcd(x, y) = 1
// - The problem also can be seen as solving x1 = 0, x2 = (something positive), then adding
//   and substracting as necessary.
// - gcd(x, y) =/= 1 iff x is a multiple of some divisor of y, hence all the divisors of 
//   y can be obtained, then for each one count the times it appears between 1 and x.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e6 + 5;

int D = 0;
ll divs[limN];
ll reps[limN];

void calcDivs(ll y) {
    D = 0;
    if(y != 1)
        divs[D++] = y;
    ll i ;
    for(i=2; i*i<y; i++)
        if(y%i==0) {
            divs[D++] = i;
            divs[D++] = y/i;
        }
    if(i*i == y)
        divs[D++] = i;
    sort(divs, divs+D);
    // for(int i=0; i<D; i++)
    //     printf("%lld ", divs[i]);
    // printf("\n");
}

ll cnt(ll y, ll x) {
    if(!x) return 0;
    ll ans = 0;
    for(int i=D-1; i>=0; i--) {
        reps[i] = x/divs[i];
        for(int j=i+1; j<D; j++)
            if(divs[j] % divs[i] == 0)
                reps[i] -= reps[j];
        ans += reps[i];
    }
    // printf("%lld %lld => %lld\n" ,y, x, ans);
    return ans;
}

ll testCase(ll y, ll xl, ll xr) {
    y = abs(y);    
    ll ans = abs(xr - xl) + 1;
    if(xr < xl)
        swap(xr, xl);
    calcDivs(y);
    if(xl <= 0 && 0 <= xr)
        ans --;
    if(xr < 0)
        xl *= -1, xr *= -1;
    if(xr < xl)
        swap(xl, xr);
    if(xl < 0)
        ans -= cnt(y, xr) + cnt(y, abs(xl));
    else
        ans -= cnt(y, xr) - cnt(y, max(0LL, xl-1));
    return ans;
}

int main() {
    int tc;
    ll a, b, c;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", testCase(a, b, c));
    }
}
