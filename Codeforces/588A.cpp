#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    long long ans = 0;

    scanf("%d", &N);
    for(int i=0, mc=1e9; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        mc = min(mc, b);
        ans += a*mc;
    }

    printf("%lld\n", ans);
}
