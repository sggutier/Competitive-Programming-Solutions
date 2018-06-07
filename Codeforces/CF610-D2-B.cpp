#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int main() {
    int N ;
    int nums[limN];
    long long minS = (1LL<<60);
    long long ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        minS = min(minS, (long long) nums[i]);
    }

    for(int i=0; i<N; i++) {
        nums[i] -= minS;
    }
    for(int p=0; p<N; p++) {
        if(nums[p]) continue;
        for(int i=0, u=-1; i<N; i++) {
            if(nums[(i+p)%N])
                ans = max(ans, (long long) i-u);
            else
                u = i;
        }
        break;
    }

    ans += minS*N;

    printf("%lld\n", ans);
}
