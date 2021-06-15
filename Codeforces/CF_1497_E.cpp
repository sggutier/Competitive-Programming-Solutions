#include <bits/stdc++.h>
using namespace std;
const int LIM_A = 1e7 + 5;
const int LIM_N = 2e5 + 5;

int sgnt[LIM_A];


void precalc() {
    static bool isComp[LIM_A] = {0};
    for(int i=1; i < LIM_A; i++)
        sgnt[i] = 1;
    for(int i=2; i < LIM_A; i++) {
        if(isComp[i]) continue;
        for(int j=i; j < LIM_A; j += i) {
            isComp[j] = true;
            int x = j;
            int cnt = 0;
            while(x % i == 0) {
                x /= i;
                cnt ^= 1;
            }
            if(cnt)
                sgnt[j] *= i;
        }
    }
}


int firstApr[LIM_A];


void testCase() {
    static int N ;
    static int nums[LIM_N];
    static int maxD[LIM_N];
    scanf("%d%d", &N, &nums[0]);
    for(int i=0; i < N; i++) {
        scanf("%d", &nums[i]);
        firstApr[sgnt[nums[i]]] = N;
        maxD[i] = N;
    }
    for(int i=N-1; i >= 0; i--) {
        int s = sgnt[nums[i]];
        maxD[i] = firstApr[s]-1;
        firstApr[s] = i;
    }
    // for(int i=0; i < N; i++)
    //     printf("%d ", maxD[i]);
    // printf("\n");
    int ans = 0 ;
    for(int i=0, r = -1; i < N; i++) {
        // printf("> %d %d\n", i, r);
        if(r < i) {
            ans ++;
            r = maxD[i];
        }
        r = min(r, maxD[i]);
        // printf("< %d %d\n", i, r);
    }
    printf("%d\n", ans);
}

int main() {
    precalc();
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
