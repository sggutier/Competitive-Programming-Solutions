#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int N;
int nums[limN];
int rpos[limN];
int cnt[limN];

int main() {
    scanf("%d%d", &N, &nums[1]);
    for(int i=1, w=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        rpos[nums[i]] = i;
    }

    int ans = 0;
    for(int i=1, maxR = 0, a, maxC = 0, l=0; i<=N; i++) {
        a = nums[i];
        maxR = max(maxR, rpos[a]);
        maxC = max(maxC, ++cnt[a]);
        // printf("%d (%d) => %d %d %d\n", a, i, maxR, maxC, l);
        if(i==maxR) {
            ans += (i-l) - maxC;
            l = i;
            maxC = 0;
        }
    }

    printf("%d\n", ans);


}
