#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int G, B;

int main() {
    int gms[limN], bls[limN];
    int ans = 0;

    scanf("%d%d", &G, &B);
    for(int i=0; i<G; i++)
        scanf("%d", &gms[i]);
    for(int i=0; i<B; i++)
        scanf("%d", &bls[i]);

    for(int i=0, j=0; i<G && j<B; i++) {
        if(bls[j] >= gms[i]) {
            j++;
            ans ++;
        }
    }

    printf("%d\n", ans);
}
