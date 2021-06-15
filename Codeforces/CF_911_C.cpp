#include <bits/stdc++.h>
using namespace std;

int main() {
    bool funca = false;
    int nums[3] ;
    for(int i=0; i<3; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+3);
    for(int w=1; w<=3; w++) {
        int cnt = 0;
        for(int i=0; i<3; i++)
            if(nums[i] == w)
                cnt ++;
        funca |= (cnt >= w);
        if(cnt==1 && w==2) {
            funca |= (nums[1]==4 && nums[2]==4);
        }
    }
    printf("%s\n", funca? "YES" : "NO");
}
