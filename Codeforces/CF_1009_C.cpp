#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gauss(ll n) {
    return (n*(n+1)) / 2;
}

int main() {
    ll ans = 0;
    ll minS = 1e18, maxS = -minS;
    int N, Q;

    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++) {
        minS = min(minS, (gauss(i-1) + gauss(N-i)) );
        maxS = max(maxS, (gauss(i-1) + gauss(N-i)) );
    }

    for(int i=0; i<Q; i++) {
        int x, d;
        scanf("%d%d", &x, &d);
        ans += x*N;
        ans += d*(d>0? maxS : minS);
    }

    printf("%.15Lf\n", ans / (1.0L*N));
}
