#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N;
    int nums[limN], maxL[limN], maxR[limN];
    int ans = 0;

    scanf("%d", &N);
    nums[0] = nums[N+1] = 1e9;
    maxL[0] = maxR[N+1] = 0;
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
    }

    for(int i=1; i<=N; i++) {
        maxL[i] = 1 + ((nums[i] > nums[i-1])? maxL[i-1] : 0);
        ans = max(ans, maxL[i]);
    }
    for(int i=N; i>=1; i--) {
        maxR[i] = 1 + ((nums[i] < nums[i+1])? maxR[i+1] : 0);
        ans = max(ans, maxR[i]);
    }

    // for(int i=1; i<=N; i++)
    //     printf("%d ", maxL[i]);
    // printf("\n");
    // for(int i=1; i<=N; i++)
    //     printf("%d ", maxR[i]);
    // printf("\n");

    for(int i=1; i<=N; i++) {
        if(i > 1)
            ans = max(ans, maxL[i-1] + 1);
        if(i < N)
            ans = max(ans, maxR[i+1] + 1);
        if(nums[i-1]+2 <= nums[i+1])
            ans = max(ans, maxL[i-1] + maxR[i+1] + 1);
    }

    printf("%d\n", ans);
}

