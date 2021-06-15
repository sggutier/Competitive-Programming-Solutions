#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef pair<int,int> pii;
#define f first
#define s second

int N, T;
int nums[limN];
int tgt[limN];
int ord[limN];
int maxL[limN], maxR[limN];
bitset <limN> forb;
pii pst[limN];
int BIT[limN];

void mete(int pos, int nov = 1) {
    for(; pos<limN; pos+=(pos & -pos))
        BIT[pos] += nov;
}

int saca(int pos) {
    int ans = 0;
    for(; pos; pos -= (pos &-pos))
        ans += BIT[pos];
    return ans;
}

void marca(int ini, int fin, int dir, int *ans) {
    int W = 1, p;
    pst[0] = {0, ini-dir};
    for(int i=ini; i!=fin; i+=dir) {
        p = lower_bound(pst, pst+W, pii(nums[i], -1)) - pst;
        if(!forb[i]) {
            ans[i] = pst[p-1].s ;
            continue;
        }
        pst[p] = {nums[i], i};
        W = p+1;
    }
}

int main() {
    
    scanf("%d%d", &N, &T);
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        ord[i-1] = i;
    }
    for(int i=1; i<=T; i++)
        scanf("%d", &tgt[i]);

    for(int i=1, j=1; j<=T; i++, j++) {
        for(; nums[i] != tgt[j]; i++);
        forb[i] = true;        
    }

    marca(1, N+1, 1, maxL);
    marca(N, 0, -1, maxR);
    sort(ord, ord+N,
         [](const int a, const int b) {
             return nums[a] < nums[b];
         });
    for(int i=1; i<=N; i++)
        mete(i);

    // for(int i=1; i<=N; i++)
    //     printf("%d ", !forb[i]? maxL[i] : -1);
    // printf("\n");
    // for(int i=1; i<=N; i++)
    //     printf("%d ", !forb[i]? maxR[i] : -1);
    // printf("\n");

    long long ans = 0;
    for(int i=0, p; i<N; i++) {
        p = ord[i];
        // printf(">> %d\n", p);
        // continue ;
        if(forb[p]) continue;
        // printf("%d %d => %d %d\n", p, nums[p], maxL[p], maxR[p]);
        ans += saca(maxR[p] -1) - saca(maxL[p]);
        mete(p, -1);
    }

    printf("%lld\n", ans);
}
