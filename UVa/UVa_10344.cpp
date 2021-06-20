#include <bits/stdc++.h>
using namespace std;

bool ans ;
int nums[5];

void bruta(int pos, int res) {
    if(pos==5) {
        ans |= res==23;
        return ;
    }
    bruta(pos+1, res+nums[pos]);
    if(!ans)
        bruta(pos+1, res-nums[pos]);
    if(!ans)
        bruta(pos+1, res*nums[pos]);
}

void testCase() {
    ans = false;
    sort(nums, nums+5);
    do {
        bruta(1, nums[0]);
    } while(!ans && next_permutation(nums, nums+5));
    if(ans)
        printf("Possible\n");
    else
        printf("Impossible\n");
}

int main() {
    while(scanf("%d%d%d%d%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]) &&
          (nums[0] || nums[1] || nums[2] || nums[3] || nums[4]))
        testCase() ;
    
    return 0;
}
