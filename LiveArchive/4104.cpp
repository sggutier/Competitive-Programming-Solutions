#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;

ll expBin(ll n, ll k) {
    if(k==0)
        return 1;
    ll mit = expBin(n, k/2);
    return (((mit*mit) % mod) * (k%2? n : 1)) % mod;
}

void testCase() {
    ll n, k ;
    scanf("%lld%lld%lld", &n, &k, &mod);
    n %= mod;
    printf("%lld\n", expBin(n, k));
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
