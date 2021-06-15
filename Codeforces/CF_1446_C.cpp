#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;

int nums[LIM_N];

int cnts(const int ini, const int fin, const int maxB) {
    if(ini + 1 >= fin)
        return fin - ini + 1;
    int ans = 0 ;
    vector <int> inis(maxB+1, -1), fins(maxB+1, 0);
    int gtCnt = 0;
    for(int i=ini; i <= fin; i++) {
        int b ;
        for(b = maxB; b && ((1 << b) & nums[i])==0; b--) ;
        if(inis[b] == -1) {
            gtCnt ++;
            inis[b] = i;
        }
        fins[b] = i;
    }
    int ltCnt = 0 ;
    for(int i=0; i <= maxB; i++) {
        if(inis[i] == -1) continue;
        gtCnt --;
        int x = cnts(inis[i], fins[i], i-1);
        ans = max(ans, ltCnt + gtCnt + x);
        // printf("%d %d %d (%d %d %d) => %d %d %d >> %d\n", i, inis[i], fins[i], ini, fin, maxB, ltCnt, x, gtCnt, ltCnt + x + gtCnt);
        ltCnt = 1;
    }
    return ans;
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+N);
    // for(int i=0; i < N; i++)
    //     printf("%d ", nums[i]);
    // printf("\n");
    int ans = cnts(0, N-1, 30);
    printf("%d\n", N - ans);
}
