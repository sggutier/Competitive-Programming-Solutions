#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int nums[limN];
    int ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    sort(nums, nums+N);
    for(int i=0; i<N; i++) {        
        ans = (ans + (nums[i]%mod)*(nums[N-1-i]%mod))%mod;
    }

    printf("%d\n", ans);
}
