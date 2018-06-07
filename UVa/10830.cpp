// - All the divisors of a number come in pairs.  For instance, for 24 its divisors are
//   - (1, 24)
//   - (2, 12)
//   - (3, 8)
//   - (4, 6)
// - A special case is when a number is a perfect square, since it has a divisor without pair.
// - The amount of times each number appears in a pair as the left one can be calculated overall.
//   For instance, for the CSOD of 100, 5 appears as a left one in
//   - 5*5 = 25
//   - 5*6 = 30
//   - 5*7 = 35
//   - ...
//   - 5*20 = 100
// - The amount of times k appears as a left part is the amount of integers in [k, floor(n/k)]
// - This also gives some numbers that appear in a right pair.  For the example of 100 and 5,
//   these are 5, 6, ..., 20.  In general, the total of right parts contributed by the left part
//   k  are sum_{i=k}^floor(n/k) i     .   This can be calculated using the sum formula of Gauss.
// - In the way described above, all the pairs cover all the divisors of all the numbers so
//   that sum is the wanted sum.
// - Only k's (left parts of a pair) between 1 and sqrt(n) have to be considered (otherwise they
//   cannot be left parts).  Therefore, this has a complexity of O(sqrt(n)).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll SOD(int n) {
    ll ans = 0;
    int i;
    for(i=2; i*i<n; i++) {
        if(n%i) continue;
        // printf("%d %d\n", i, n/i);
        ans += i;
        ans += n/i;
    }
    if(i*i == n)
        ans += i;
    return ans;
}

ll CSOD2(int n) {
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans += SOD(i);
    return ans;
}

ll gauss(ll n) {
    return (n*(n+1))/2;
}

ll CSOD(int n) {
    ll ans = 0;
    ll l, r;
    int i;
    for(i=2; i*i<=n; i++) {
        l = i;
        r = n/i;
        // printf("%d => %lld %lld\n", i, l, r);
        ans += i*(r-l+1);
        ans += gauss(r) - gauss(l);
    }
    return ans;
}

int main() {
    int tc = 1;
    int n ;
    while(scanf("%d", &n)!=EOF && n) {
        // printf("%lld\n", SOD(n));
        // printf("%lld\n", CSOD(n));
        printf("Case %d: %lld\n", tc++, CSOD(n));
    }
}
