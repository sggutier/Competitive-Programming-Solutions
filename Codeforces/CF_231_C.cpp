#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

int main() {
    int N ;
    ll w ;
    ll nums[limN];
    pair <ll, ll> ans(0,-1);

    scanf("%d%lld", &N, &w);
    for(int i=0; i<N; i++)
        scanf("%lld", &nums[i]);

    sort(nums, nums+N);
    for(int l=0, r=0; r<N; r++) {
        if(r && nums[r]!=nums[r-1])
            w -= (nums[r]-nums[r-1])*(r-l);
        while(l<r && w<0)
            w += nums[r]-nums[l++];
        ans = min(ans, make_pair(-(r-l+1LL), nums[r]));
    }

    printf("%lld %lld\n", -ans.first, ans.second);
}

