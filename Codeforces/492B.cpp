#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int nums[1005];
    double ans = 0;
    
    cin >> N >> K ;
    for(int i=0; i<N; i++)
        cin >> nums[i] ;
    sort(nums, nums+N);

    ans = max(nums[0], K - nums[N-1]);
    for(int i=1; i<N; i++)
        ans = max(ans, (nums[i]-nums[i-1])/2.0);

    printf("%.9lf\n", ans);
}
