#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int nums[limN], dep[limN];
    map <int,int> revo;

    scanf("%d%d", &N, &nums[0]);
    revo[nums[0]] = 0;
    dep[0] = 0;
    for(int i=1; i<N; i++) {
        scanf("%d", &nums[i]);
        auto it = revo.upper_bound(nums[i]);
        int pat;
        if(it==revo.end()) {
            it--;
            pat = it->second;
        }
        else if(it==revo.begin()) {
            pat = it->second;
        }
        else {
            auto it2 = it;
            it2--;
            pat = ((dep[it->second] < dep[it2->second])? it2 : it)->second;
        }
        printf("%d ", nums[pat]);
        dep[i] = dep[pat]+1;
        revo[nums[i]] = i;
    }
    printf("\n");
}
