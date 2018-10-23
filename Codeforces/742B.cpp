#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int cnt[limN * 10];

int main() {
    int N, x ;
    int nums[limN];
    long long ans = 0;
    scanf("%d%d", &N, &x);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        cnt[nums[i]] ++;
    }
    for(int i=0; i<N; i++) {
        cnt[nums[i]] --;
        ans += cnt[x ^ nums[i]];
    }
    printf("%lld\n", ans);
}
