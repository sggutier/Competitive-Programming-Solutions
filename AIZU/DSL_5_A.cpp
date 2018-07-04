#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int crg[limN];

int main() {
    int N, T;
    int ans = 0;
    scanf("%d%d", &N, &T);
    for(int i=0, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        crg[a]++;
        crg[b]--;
    }
    for(int i=0, s=0; i<=T; i++) {
        s += crg[i];
        ans = max(ans, s);
    }
    printf("%d\n", ans);
}
