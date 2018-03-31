#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N, K ;
    int nums[limN] ;
    int ans = 0;

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    sort(nums, nums+N, [](int a, int b) { return 10 - a%10 < 10 - b % 10; } ) ;

    for(int i=0; i<N; i++) {
        if(nums[i] % 10 == 0) break;
        int w = 10 - nums[i] % 10;
        if(w > K) break;
        nums[i] += w;
        K -= w;
    }

    sort(nums, nums+N);
    for(int i=0; i<N; i++) {
        int w = min(100-nums[i], K);
        K -= w ;
        nums[i] += w;
        ans += nums[i] / 10;
    }

    printf("%d\n", ans);
}
