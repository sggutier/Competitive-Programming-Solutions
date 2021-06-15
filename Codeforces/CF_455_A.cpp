#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 10;

long long dp[limN];
long long reps[limN];

int main() {
    int N ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        reps[a]++;
    }

    for(int i=limN-1; i>=0; i--) {
        dp[i] = max(dp[i+1], i*reps[i] + dp[i+2]);
    }
    printf("%lld\n", dp[0]);
}
