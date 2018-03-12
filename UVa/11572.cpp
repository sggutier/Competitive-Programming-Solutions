#include <bits/stdc++.h>
using namespace std;

void testCase() {
    map <int, int> nums;
    int n, ult = 1;
    int cnt = 0, ans = 0;
    int tmp;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &tmp);
        if(nums[tmp]>=ult) {
            cnt -= nums[tmp] - ult + 1;
            ult = nums[tmp]+1;
        }
        nums[tmp] = i;
        cnt ++;
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
