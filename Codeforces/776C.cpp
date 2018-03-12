#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const ll fino = 1e14;

int main() {
    int N, K ;
    map <ll, int> cnt;
    ll sumo = 0;
    ll ans = 0;

    scanf("%d%d", &N, &K);
    cnt[0]++;
    for(int i=0; i<N; i++) {
        int a; scanf("%d", &a);
        sumo += a;
        cnt[sumo]++;
        for(ll p=1; p<=fino; p*=K) {
            auto it = cnt.find(sumo-p);
            // printf("%d %lld => %lld\n", a, p, a-p);
            if(it!=cnt.end()) {
                ans += it->second;
                // printf("%d %d %lld %lld => %d\n", i, a, sumo, p, it->second);
            }
            if(p*K == 1)
                break;
        }
    }

    printf("%lld\n", ans);
}
