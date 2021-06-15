#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 1e9;
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        if(K%a == 0)
            ans = min(ans, K/a);
    }
    printf("%d\n", ans);
}
