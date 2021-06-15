#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int nums[limN];

void calcLis(int dir, int *ans) {
    static int W;
    static int minH[limN];    
    int ini = dir==1? 0 : N-1;
    int fin = dir==1? N : -1;
    W = 0;
    minH[0] = 0;

    // printf("En dir %d\n", dir);
    for(int i=ini; i!=fin; i+=dir) {
        int p = upper_bound(minH, minH+W, nums[i]) - minH;
        // printf("%d %d %d\n", i, nums[i], p);
        minH[p] = nums[i];
        ans[i] = p+1;
        W = max(W, p+1);
    }
}

int main() {
    int R ;
    int maxL[limN], maxR[limN];
    int ans = 0;
    
    scanf("%d%d", &R, &N);
    for(int i=0; i<R; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        nums[a-1]++;
        nums[b]--;
    }
    for(int i=0, s=0; i<N; i++) {
        s += nums[i];
        nums[i] = s;
    }

    calcLis(1, maxL);
    calcLis(-1, maxR);
    for(int i=0; i<N; i++)
        ans = max(ans, maxL[i]+maxR[i]-1);

    printf("%d\n", ans);
}
