#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calcaSuma(int n) {
    ll ans = 0;
    for(ll i=0; i<n; i++)
        ans += (n-i)*(n-i)*(i%2? -1 : 1);
    return ans;
}

int main() {
    int Q ;
    long long n;
    for(scanf("%d", &Q); Q; Q--) {
        scanf("%lld", &n);
        printf("%lld\n", (n*(n+1))/2);
    }
}
