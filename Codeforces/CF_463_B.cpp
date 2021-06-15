#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int main() {
    int N ;
    long long ans = 0, crg = 0;

    scanf("%d", &N);
    for(int i=0, u=0, a; i<N; i++) {
        scanf("%d", &a);
        crg = max(crg, 0LL);
        crg += u-a;
        u = a;
        ans -= min(0LL, crg);
    }

    printf("%lld\n", ans);
}
