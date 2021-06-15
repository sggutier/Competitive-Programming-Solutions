#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

void testCase() {
    int reps[LIM_N] = {0};
    int N, MOD ;
    int ans = 0 ;
    scanf("%d%d", &N, &MOD) ;
    for(int i=0, a; i < N; i++) {
        scanf("%d", &a);
        reps[a % MOD] ++;
    }
    for(int i=0; i < MOD; i++) {
        int a = i, b = (MOD - i) % MOD;
        if(!reps[a] || !reps[b]) continue;
        if(reps[b] < reps[a]) {
            swap(a, b);
        }
        ans ++;
        reps[b] = max(0, reps[b] - (reps[a] + 1));
        reps[a] = 0 ;
    }
    for(int i=0; i < MOD; i++)
        ans += reps[i];
    printf("%d\n", ans);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
