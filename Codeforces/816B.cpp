#include <bits/stdc++.h>
using namespace std;
const int limN = 200005;

int crg[limN];
int sum[limN];

int main() {
    int N, K, Q;

    scanf("%d%d%d", &N ,&K, &Q);
    for(int i=0; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        crg[a]++, crg[b+1]--;
    }
    for(int i=0, s=0, t=0; i<limN; i++) {
        s += crg[i];
        if(s >= K)
            t++;
        sum[i] = t;
    }
    for(int i=0; i<Q; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[b] - sum[a-1]);
    }
}
