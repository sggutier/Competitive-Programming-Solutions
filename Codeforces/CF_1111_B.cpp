#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

ll N, M, K;
ll nms[limN];

int main() {
    ll tot = 0;

    scanf("%lld%lld%lld", &N, &M, &K);
    for(int i=0; i<N; i++) {
        scanf("%lld", &nms[i]);
        tot += nms[i];
    }

    sort(nms, nms+N);
    ll crg = 0;
    long double ans = 0;
    for(int i=0; i<N && i<=K; i++) {
        ans = max(ans,
                  (min(K-i, (N-i) * M) + (tot - crg)) / (N - (long double) i) );
        // cout << i << " " << (min(K-i, (N-i) * M) + (tot - crg)) / (N - (long double) i) << endl;
        crg += nms[i];
    }

    cout << fixed << setprecision(9) << ans << endl;
}
