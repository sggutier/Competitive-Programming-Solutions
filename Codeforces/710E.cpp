#include <bits/stdc++.h>
using namespace std;
const int limN = 2e7 + 5;
typedef long long ll;
const ll tope = 1e16;

int n;
ll dp[limN];
bool usd[limN];
bool mdo[limN];
priority_queue < pair<ll, int> > Q;

void ppush(const int pos, const ll dst) {
    if(usd[pos]) return;
    if(!mdo[pos] || dst < dp[pos]) {
        dp[pos] = dst;
        mdo[pos] = true;
        Q.push({-dst, pos});
    }
}

int main() {
    ll x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    Q.push({0, 0});
    dp[n] = x*24 + y*24;
    Q.push({-x*24 - y*24, n});
    while(!Q.empty()) {
        int pos = Q.top().second;
        ll dst = -Q.top().first;
        Q.pop();
        if(pos==n) {
            printf("%lld\n", dp[n]);
            return 0;
        }
        if(usd[pos])
            continue;
        usd[pos] = true;
        if(dst >= dp[n])
            continue;
        // printf("Lleva a :\n");
        if(pos && dst + x < dp[n]) ppush(pos-1, dst + x);
        if(pos + 1 <= n && dst + x < dp[n]) ppush(pos+1, dst + x);
        if(pos*2 <= n && dst + y < dp[n])
            ppush(pos*2, dst + y);
        if(pos*2 > n)
            ppush(n, dst + y + (pos*2-n)*x);
    }    
    // for(int pos=1; pos<n; pos++) {
    //     if(usd[pos] && pos*2 >= n)
    //         dp[n] = min(dp[n], dp[pos] + y + ((ll) ( (pos*2) -n))*x);
    // }
    printf("%lld\n", dp[n]);
}
