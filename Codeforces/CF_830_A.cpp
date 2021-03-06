#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    ll p;
    ll ppl[2005];
    ll keys[2005];
    ll ans = 1e18;

    scanf("%d%d%lld", &N, &K, &p);
    for(int i=0; i<N; i++)
        scanf("%lld", &ppl[i]);
    for(int i=0; i<K; i++) {
        scanf("%lld", &keys[i]);
    }

    sort(keys, keys+K);
    sort(ppl, ppl+N);
    for(int i=0; i+N<=K; i++) {
        ll sumo = 0;
        for(int j=0; j<N; j++) {
            sumo = max(sumo, abs(ppl[j]-keys[i+j]) + abs(p-keys[i+j]));
        }
        ans = min(ans, sumo);
    }

    printf("%lld\n", ans);
}
