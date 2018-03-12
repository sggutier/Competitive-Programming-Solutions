#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, x;
    int ans = 0;

    scanf("%d%d%d", &N, &K, &x);
    N -= K;
    for(int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        ans += a;
    }
    ans += x*K;

    printf("%d\n", ans);
}
