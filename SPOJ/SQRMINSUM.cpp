#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int ro[limN];

void precarga() {
    for(int i=1; i<limN; i++)
        ro[i] = sqrt(i);
}

void testCase() {
    static int crg[limN];
    int l, k, u;
    scanf("%d%d", &l, &k);
    for(int i=1; i<=l; i++)
        crg[i] = 1;
    for(u=l; k; k--) {
        while(crg[u]==0)
            u--;
        crg[u]--;
        crg[ro[u]]++;
    }
    int ans = 0;
    for(int i=0; i<=u; i++)
        ans += crg[i]*i;
    printf("%d\n", ans);
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
