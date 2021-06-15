#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int crg[limN];

int main() {
    int ans = 0;
    int N, A;

    scanf("%d%d", &N, &A);
    for(int i=0; i<A; i++) {
        int p ;
        scanf("%d", &p);
        crg[p]++;
        int mc = crg[1];
        for(int j=2; j<=N; j++) {
            mc = min(mc, crg[j]);
        }
        if(mc == 0) continue;
        ans += mc;
        for(int j=1; j<=N; j++)
            crg[j] -= mc;
    }

    printf("%d\n", ans);
}
