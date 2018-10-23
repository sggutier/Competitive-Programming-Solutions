#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int nums[100005];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    sort(nums, nums+N);
    for(int i=N-1; i>=2; i--) {
        if(nums[i-2] + nums[i-1] > nums[i]) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
