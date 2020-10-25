#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int main() {
        int N ;
        int nums[limN];

        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%d", &nums[i]);
        }

        sort(nums, nums+N);
        double ans = 1e18;
        for(int i=0; i<N; i++) {
                if(i+1 < nums[i]) {
                        printf("impossible\n");
                        return 0 ;
                }
                ans = min(ans, nums[i] / (i+ 1.0));
        }

        printf("%.9lf\n", ans);
}
