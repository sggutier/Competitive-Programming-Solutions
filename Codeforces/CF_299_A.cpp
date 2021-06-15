#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int nums[limN];
    int maxn = 1e9 + 7;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        maxn = min(maxn, nums[i]);
    }

    for(int i=0; i<N; i++) {
        if(nums[i] % maxn) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", maxn);
}
