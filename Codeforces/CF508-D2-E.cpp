#include <bits/stdc++.h>
using namespace std;
const int limN = 605;

int rngL[limN], rngR[limN];
bool dp[limN][limN];
int sigo[limN][limN];

bool funca(int l, int r) {
    if(l > r)
        return l==r+1;
    if(sigo[l][r])
        return dp[l][r];
    sigo[l][r] = -1;
    for(int i=rngL[l]; i<=rngR[l]; i++) {
        if(funca(l+1, l+i-1) && funca(l+i, r)) {
            sigo[l][r] = i;
            break;
        }
    }
    // printf("%d %d => %d\n", l, r, sigo[l][r]);
    return dp[l][r] = (sigo[l][r] != -1);
}

void reconstr(int l, int r) {
    if(l > r)
        return;
    printf("(");
    reconstr(l+1, l + sigo[l][r]-1);
    printf(")");
    reconstr(l + sigo[l][r], r);
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &rngL[i], &rngR[i]);
        // printf("%d %d => ", rngL[i], rngR[i]);
        rngL[i] = ceil((rngL[i] + 1) / 2.0);
        rngR[i] = floor((rngR[i] + 1) / 2.0);
        // printf("%d %d\n", rngL[i], rngR[i]);
        if(rngL[i] > rngR[i]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    if(!funca(0, N-1)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    reconstr(0, N-1);
    printf("\n");
}
