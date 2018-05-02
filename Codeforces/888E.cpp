#include <bits/stdc++.h>
using namespace std;
const int limP = (1<<20);
const int limN = 40;

int W = 0;
int cmbs[limP];
int nums[limN];

int main() {
    int N, mod;
    int M ;
    int ans = 0;

    scanf("%d%d", &N, &mod);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    M = N - N/2;

    for(int b=(1<<(N-M))-1; b>=0; b--) {
        int s = 0;
        for(int i=N-M-1; i>=0; i--) {
            if((1<<i) & b) {
                s = (s + nums[i+M]) % mod;
                // printf("sumando %d (%d) => %d\n", i+M, i, nums[i+M]);
            }
        }
        cmbs[W++] = s;
        // printf("cmbs => %d\n", s);
    }
    sort(cmbs, cmbs+W);

    for(int b=(1<<M)-1; b>=0; b--) {
        int s = 0;
        for(int i=M-1; i>=0; i--)
            if((1<<i) & b) {
                s = (s + nums[i]) % mod;
                // printf("sumando %d => %d\n", i, nums[i]);
            }
        int p = lower_bound(cmbs, cmbs+W, mod-s) - cmbs - 1;
        // printf("%d => a %d le encontre %d\n", b, s, p>=0? cmbs[p]: s);
        if(p >= 0 && s + cmbs[p] < mod)
            ans = max(ans, s + cmbs[p]);
    }

    printf("%d\n", ans);
}
