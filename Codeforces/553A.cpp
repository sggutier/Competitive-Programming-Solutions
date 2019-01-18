#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1005;
const ll mod = 1e9 + 7;


bool usd[limN][limN];
ll dp[limN][limN];

ll ways(int a, int b) {
    if(a==0 || b==0)
        return 1;
    if(usd[a][b])
        return dp[a][b];
    usd[a][b] = true;
    return dp[a][b] = (ways(a-1, b) + ways(a, b-1)) % mod;
}

int main() {
    int s = 0;
    int N ;
    ll ans = 1;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        ans = (ans * ways(s, a-1)) % mod;
        s += a;
    }
    printf("%lld\n", ans);
}
