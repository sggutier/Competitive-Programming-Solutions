#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[3];
    int ans = 0;
    int ml=0, mr=0;
    
    for(int i=0; i<3; i++)
        cin >> nums[i];

    ml = max(nums[0]+nums[1], nums[0]*nums[1]);
    mr = max(nums[2]+nums[1], nums[2]*nums[1]);
    ans = max(ans, nums[0]*mr);
    ans = max(ans, nums[0]+mr);
    ans = max(ans, nums[2]*ml);
    ans = max(ans, nums[2]+ml);

    cout << ans << endl;
}
