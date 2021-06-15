#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e5 + 5 ;

int main() {
    int N ;
    ll nums[LIM_N];

    scanf("%d", &N);
    for(int i=0; i < N; i++)
        scanf("%lld", &nums[i]);

    if(N == 1) {
        printf("0\n");
        return 0 ;
    }

    bool ans[3] = {false, false, true};
    for(int w=0; w < 2; w++) {
        for(int i=0; i < 3 && i < N; i++) {
            for(int j=i+1; j < 3 && j < N; j++) {
                if(nums[i] && nums[j] % nums[i]) continue;
                ll c = nums[i];
                ll b = c? nums[j] / c : 1 ;
                if(b == 0 && w)
                    continue ;
                int rep = 0 ;
                for(int k=0; k < N && rep < 2; k++) {
                    if(nums[k] != c) {
                        rep ++;
                        continue;
                    }
                    c *= b ;
                }
                if(rep < 2)
                    ans[rep] = true;
            }
        }
        reverse(nums, nums+N);
    }

    for(int i=0; i < 3; i++)
        if(ans[i]) {
            printf("%d\n", i);
            return 0 ;
        }
}
