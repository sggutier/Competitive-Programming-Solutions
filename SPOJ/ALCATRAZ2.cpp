#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 8;
const int limB = 1<<limN;

ll nms[limN + 5];
int msks[limN + 5];
ll dp[limB + 5];

int main() {
    const int N = limN;
    for(int i=0; i<N; i++)
        scanf("%lld", &nms[i]);
    int E ;
    scanf("%d", &E);
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        if(b < a)
            swap(a, b);
        a--, b--;
        msks[b] |= (1<<a);
    }

    for(int i=0; i<N; i++) {
        for(int b = (1<<i)-1; b>=0; b--) {
            if(b & msks[i]) continue;
            dp[b | (1<<i)] = max(dp[b | (1<<i)], nms[i] + dp[b]);
        }
    }

    ll ans = 0;
    for(int i=0; i<limB; i++)
        ans = max(ans, dp[i]);

    printf("%lld\n", ans);
}
