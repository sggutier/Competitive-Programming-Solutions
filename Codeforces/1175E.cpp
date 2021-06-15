#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 5e5 + 5;
const int LIM_B = 19;

int maxV[LIM_N];
int nexts[LIM_N][LIM_B];

void init() {
    int mx = -1;
    for(int i=0; i < LIM_N; i++) {
        mx = max(maxV[i], mx);
        maxV[i] = mx;
    }
    for(int i=LIM_N - 1; i >= 0; i--) {
        for(int j=0; j < LIM_B; j++) {
            nexts[i][j] = i;
        }
        if(maxV[i] < i)
            continue ;
        nexts[i][0] = maxV[i];
        for(int j=1, p = maxV[i]; j < LIM_B; j++) {
            nexts[i][j] = p = nexts[p][j-1];
        }
    }
}

int query(int a, int b) {
    int p = a;
    int ans = 0 ;
    for(int i=LIM_B - 1; i >= 0; i--) {
        if(nexts[p][i] < b) {
            p = nexts[p][i];
            ans += 1 << i;
        }
    }
    // printf("%d %d ==> %d\n", a, b, p);
    if(p < b) {
        p = nexts[p][0];
        ans ++;
    }
    return p < b? -1 : ans;
}

int main() {
    maxV[0] = -1;
    int N, Q ;
    scanf("%d%d", &N, &Q);
    for(int i=0; i < N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        maxV[a] = max(maxV[a], b);
    }
    init();

    for(int i=0; i < Q; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
}
