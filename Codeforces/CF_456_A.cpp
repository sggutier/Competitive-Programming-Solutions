#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5  + 5;
typedef pair<int,int> pii;

int main() {
    int N ;
    pii nums[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &nums[i].first, &nums[i].second);
    sort(nums, nums+N);

    for(int i=0, maxQ = -1e9; i<N; i++) {
        if(nums[i].second < maxQ) {
            printf("Happy Alex\n");
            return 0;
        }
        maxQ = max(maxQ, nums[i].second);
    }

    printf("Poor Alex\n");
}
