#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
#define f first
#define s second
const int limN = 1e6 + 5;

int N ;
par nums[limN];
int W = 0;
int minT[limN];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &nums[i].f, &nums[i].s);
    sort(nums, nums+N);

    for(int i=0; i<N; i++) {
        int p = lower_bound(minT, minT+W+1, nums[i].f) - minT;
        if(p > W)
            minT[p] = nums[i].s, W = p;
        minT[p] = min(nums[i].s, minT[p]);
    }

    printf("%d\n", W);
}
