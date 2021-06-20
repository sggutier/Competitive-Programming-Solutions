#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int dif(int a, int b) {
    int c = abs(a-b);
    return min(c, 24 - c);
}

void testCase(int N) {
    int nums[limN];
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+N);
    int sa = 0, sb = 0;
    for(int i=0; i<N; i+=2)
        sa += dif(nums[i], nums[i+1]);
    for(int i=1; i<N; i+=2)
        sb += dif(nums[i], nums[(i+1)%N]);
    printf("%d\n", min(sa, sb));
}

int main() {
    int N ;
    while(scanf("%d", &N) != EOF)
        testCase(N);
}
