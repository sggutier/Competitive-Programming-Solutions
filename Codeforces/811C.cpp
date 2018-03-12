#include <bits/stdc++.h>
using namespace std;
const int limN = 5e3 + 5;

bool mkd[limN];
bool pp[limN];
int up[limN];
int dp[limN];
int mko[limN];

int main() {
    int N ;
    int nums[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        if(!mkd[nums[i]]) {
            pp[i] = true;
            mkd[nums[i]] = true;
        }
        up[nums[i]] = i;
        mko[nums[i]] = -1;
    }

    for(int i=N-1; i>=0; i--) {
        dp[i] = dp[i+1];
        if(!pp[i])
            continue;
        int s = 0, f = up[nums[i]];
        // printf("%d (%d) => ", i, f);
        for(int j=i; j<=f; j++) {
            f = max(f, up[nums[j]]);
            // printf("[%d %d (%d)] ", j, nums[j], f);
            if(mko[nums[j]]!=i) {
                if(!pp[j]) {
                    s = 0;
                    f = i;
                    break;
                }
                s ^= nums[j];
                mko[nums[j]] = i;
            }
        }
        // printf("\n");
        // printf("{%d %d %d}\n", dp[i], dp[f+1], s);
        dp[i] = max(dp[i], dp[f+1]+s);
    }

    printf("%d\n", dp[0]);
}
