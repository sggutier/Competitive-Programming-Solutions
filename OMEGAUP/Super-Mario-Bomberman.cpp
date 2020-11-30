#include <bits/stdc++.h>
using namespace std;
const int limN = 65;

unsigned long long depo[limN+1][limN+1][2];

void precarga() {
    depo[0][0][1] = depo[0][0][0] = 1LL;
    for(int L=1; L<=limN; L++) {
        // depo[L][0][0] = depo[L-1][0][0] + depo[L-1][0][1]
        depo[L][0][1] = depo[L-1][0][0];
        depo[L][0][0] = depo[L-1][0][1] + depo[L-1][0][0];
        for(int s=1; s<=L; s++) {
            depo[L][s][1] = depo[L-1][s-1][1] + depo[L-1][s][0];
            depo[L][s][0] = depo[L-1][s][1] + depo[L-1][s][0];
        }
    }
}

int main() {
    precarga();
    int a, b;

    int x ;
    scanf("%d", &x);
    while(scanf("%d%d", &a, &b)!=EOF && (a>=0 && b>=0)) {
        printf("%lld\n", depo[a][b][1]);
    }

    return 0;
}
