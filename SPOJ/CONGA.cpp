#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e6 + 5;

int nums[LIM_N];

void testCase(const int N) {
    for(int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    ll ans = 0 ;
    ll sm = 0 ;
    for(int i = 1; i < N; i++) {
        sm += nums[i] - (nums[0] + i);
    }
    ans = sm;
    ll izq = 0, der = N;
    // printf("%d => %lld\n", 0, sm);
    for(int i=1; i < N; i++) {
        izq ++;
        der --;
        sm -= (nums[i] - (nums[i-1] + 1)) * der;
        sm += ((nums[i] - 1) - nums[i-1]) * izq;
        // printf("%d => %lld\n", i, sm);
        ans = min(ans, sm);
    }
    printf("%lld\n", ans);
}

int main() {
    int N ;
    while(scanf("%d", &N) != EOF && N) {
        testCase(N);
    }
}
