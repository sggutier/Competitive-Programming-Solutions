#include <bits/stdc++.h>
using namespace std;
const int limN = 105 ;

vector <int> remLIS(vector <int> vec) {
    vector <int> ans ;
    int n = vec.size();
    vector <bool> usd(n);
    vector < pair<int,int> > maxL(n);
    pair<int, int> wpos ;

    for(int i=0; i<n; i++) {
        maxL[i] = {1, -1};
        for(int j=0; j<i; j++)
            if(maxL[j].first  <= vec[i])
                maxL[i] = max(maxL[i], {maxL[j].first + 1, j});
        wpos = max(wpos, make_pair(maxL[i].first, i));
    }

    for(int pos = wpos.second ; pos != -1; pos = maxL[pos].second)
        usd[pos] = true;

    for(int i=0; i<n; i++)
        if(!usd[i])
            ans.push_back(vec[i]);

    return ans ;
}

int main() {
    int n ;
    vector <int> nums ;

    scanf("%d", &n);
    nums.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());

    int ans = 0 ;
    for(; !nums.empty(); nums = remLIS(nums), ans ++);

    printf("%d\n", ans);
}
