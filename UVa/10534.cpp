#include <bits/stdc++.h>
using namespace std;

void calcLis(const int &numCnt, const int nums[], int ans[]) {
    int minH[numCnt], H=1;
    minH[0] = 0;
    for(int i=0; i<numCnt; i++) {
        int pos = lower_bound(minH, minH+H, nums[i]) - minH;
        if(pos==H)
            H++;
        minH[pos] = nums[i];
        ans[i] = pos;
    }
}

void testCase(int numCnt) {
    int nums[numCnt];
    int incr[numCnt], decr[numCnt];
    incr[0] = 1;
    decr[numCnt-1] = 1;

    for(int i=0; i<numCnt; i++)
        scanf("%d", &nums[i]);

    calcLis(numCnt, nums, incr);
    reverse(nums, nums+numCnt);
    calcLis(numCnt, nums, decr);
    reverse(decr, decr+numCnt);

    int ans = 1;
    for(int i=0; i<numCnt; i++)
        ans = max(ans, min(incr[i], decr[i])*2 -1);

    printf("%d\n", ans);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
