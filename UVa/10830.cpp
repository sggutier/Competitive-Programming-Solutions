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
