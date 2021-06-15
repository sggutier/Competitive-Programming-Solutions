#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;

struct BIT {
    int maxV[LIM_N] = {0};
    void mete(int pos, const int v) {
        pos ++;
        for(; pos < LIM_N; pos += pos & -pos)
            maxV[pos] = max(maxV[pos], v);
    }
    int saca(int pos) {
        pos ++;
        int ans = 0 ;
        for(; pos; pos -= pos & -pos)
            ans = max(ans, maxV[pos]);
        return ans;
    }
};

int N ;
int vals[LIM_N];
int ansL[LIM_N], ansR[LIM_N];

void caso(int ini, int fin, int dir, int *ans) {
    BIT bt;
    for(int i=ini; i != fin; i += dir) {
        ans[i] = bt.saca(vals[i]) + 1;
        bt.mete(vals[i], ans[i]);
    }
}

int main() {
    freopen("improvements.in", "r", stdin);
    freopen("improvements.out", "w", stdout);
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        int a ;
        scanf("%d", &a);
        vals[a-1] = i;
    }
    caso(0, N, 1, ansL);
    caso(N-1, -1, -1, ansR);
    int ans = 0 ;
    for(int i=0; i < N; i++)
        ans = max(ans, ansL[i] + ansR[i] - 1);
    printf("%d\n", ans);
}
