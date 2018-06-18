#include <bits/stdc++.h>
using namespace std;
const int limN = 1000;

int N, M ;
bool utl[limN];
int nums[limN];
pair<int, int> dp[limN];

int main() {
    pair<int, int> ans = {0, -1};
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    for(int i=0, a; i<M; i++) {
        scanf("%d", &a);
        for(int j=0; j<N; j++)
            if(nums[j]==a)
                utl[j] = true;
    }
    for(int i=N-1; i>=0; i--) {
        if(!utl[i]) continue;
        dp[i].second = -1;
        for(int j=i+1; j<N; j++)
            if(utl[j])
                dp[i] = max(dp[i], {dp[j].first, j});
        dp[i].first++;
        ans = max(ans, {dp[i].first, i});
        //printf("%d => %d %d\n", i, dp[i].first, dp[i].second);
    }
    //return 0;
    int pos = ans.second;
    while(pos != -1) {
        printf("%d ", nums[pos]);
        pos = dp[pos].second;
    }
    printf("\n");
}
