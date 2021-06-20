#include <bits/stdc++.h>
const int limN = 40;

long long ans[limN+1];

void precarga() {
    ans[0] = ans[1] = 1LL;
    ans[2] = 5LL;
    for(int i=3; i<=limN; i++) 
        ans[i] = ans[i-1] + 4LL*ans[i-2] + 2LL*ans[i-3];
}

int main() {
    precarga();
    int tc, a;

    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &a);
        printf("%lld\n", ans[a]);
    }
}
