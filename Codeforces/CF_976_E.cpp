#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second

int N ;
ll hs[limN], ds[limN];
int ords[limN];

ll calc(int forb, int b) {
    ll ans = 0;
    for(int i=0, p; i<N; i++) {
        p = ords[i];
        if(p == forb) continue;
        if(hs[p] > ds[p] && b > 0) {
            b--;
            ans += hs[p];
        }
        else
            ans += ds[p];
    }
    return ans;
}

int main() {
    int a, b;
    pll maxA = {0, -1};
    pll maxB = {0, -1};
    pll maxC = {0, -1};
    ll ans = 0;

    scanf("%d%d%d", &N, &a, &b);
    for(int w=0; w<N; w++) {
        scanf("%lld%lld", &hs[w], &ds[w]);
        ans += ds[w];
        ords[w] = w;
        maxC = max(maxC, {hs[w], w});
        if(hs[w] <= ds[w])
            maxA = max(maxA, {(hs[w]<<a) - ds[w], w});
        else
            maxB = max(maxB, {(hs[w]<<a) - ds[w], w});
    }

    // printf("%lld %lld\n", maxA.f, maxA.s);
    // printf("%lld %lld\n", maxB.f, maxB.s);

    sort(ords, ords+N,
         [](const int a, const int b) {
             return hs[a] -ds[a] > hs[b] - ds[b];
         });
    ans = max(ans, calc(-1, b));

    // for(int i=0; i<N; i++) {
    //     int p = ords[i];
    //     printf("%lld %lld\n", hs[p], ds[p]);
    // }

    if(b) {
        ans = max(ans, (hs[maxC.s]<<a) + calc(maxC.s, b-1));
        ans = max(ans, (hs[maxA.s]<<a) + calc(maxA.s, b-1));
        ans = max(ans, (hs[maxB.s]<<a) + calc(maxB.s, b-1));
        // for(int i=0; i<N; i++) {
        //     ans = max(ans, (hs[i]<<a) + calc(i, b-1));
        // }
    }

    printf("%lld\n", ans);
}
