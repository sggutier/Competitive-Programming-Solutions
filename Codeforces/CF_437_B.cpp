#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int a, b ;
    vector <int> ans;
    vector <pair<int, int>> nums;
    
    cin >> a >> b ;

    for(int i=1; i<=b; i++) {
        nums.push_back( make_pair(i & -i, i));
    }
    sort(nums.begin(), nums.end());

    for(int i=nums.size()-1; i>=0; i--) {
        if(a >= nums[i].first) {
            a -= nums[i].first;
            ans.push_back(nums[i].second);
        }
    }

    if(a) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", (int) ans.size());
    for(int d:ans)
        printf("%d ", d);
    printf("\n");
}
