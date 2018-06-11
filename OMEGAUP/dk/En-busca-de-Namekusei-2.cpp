#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int main() {
    int N ;
    long long ans[limN];
    long long x[limN], y[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        long long w, dx, dy ;
        scanf("%lld%lld", &x[i], &y[i]);
        ans[i] = 3e18;
        for(int j=0; j<i; j++) {
            dx = x[i] - x[j];
            dy = y[i] - y[j];
            w = dx*dx + dy*dy;
            ans[i] = min(ans[i], w);
            ans[j] = min(ans[j], w);
        }
    }

    for(int i=0; i<N; i++) {
        printf("%.9lf\n", sqrt(ans[i]));
    }
}
