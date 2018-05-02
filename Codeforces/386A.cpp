#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int limN = 1005;
#define f first
#define s second

int main() {
    int N ;
    pii nums[limN];
    pii maxW ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i].f);
        nums[i].s = i+1;
    }
    sort(nums, nums+N);

    printf("%d %d\n", nums[N-1].s, nums[N-2].f);
}
