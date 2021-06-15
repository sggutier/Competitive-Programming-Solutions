#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll div2 = 499122177;
const int limN = 1e6 + 5;

ll sums[limN];
ll dp[limN];

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &sums[i]);
        sums[i] += sums[i-1];
        sums[i] %= mod;
    }

    ll acum = 0, sdp = 0;
    ll potInv2 = 1;
    for(int r=1; r<=N; r++) {
        if(r > 1)
            potInv2 = (potInv2 * div2) % mod;
        acum += potInv2 * sums[r-1];
        acum %= mod;
        dp[r] = (potInv2 * sums[r]) % mod + acum + sdp;
        dp[r] %= mod;
        sdp = ((sdp + dp[r]) * div2) % mod ;
    }
    ll pot2 = 1;
    for(int i=1; i<N; i++)
        pot2 = (pot2 * 2) % mod;

    printf("%lld\n", (pot2 * dp[N]) % mod);
}
