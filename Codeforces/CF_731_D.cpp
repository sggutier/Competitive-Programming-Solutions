#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 5e5 + 5;
const int LIM_K = 1e6 + 5;

int lens[LIM_N];
vector <int> dks[LIM_N];
int acms[LIM_K];

int main() {
    int N, K ;

    scanf("%d%d", &N, &K);
    for(int i=0, a; i < N; i++) {
        scanf("%d", &lens[i]);
        dks[i].resize(lens[i]);
        for(int j=0; j < lens[i]; j++) {
            scanf("%d", &a);
            a--;
            dks[i][j] = a;
            // printf("%d ", a);
        }
        // printf("\n");
    }

    int gtL = 0, gtR = K-1;
    // printf("--------\n");
    // printf("> %d %d\n", gtL, gtR);
    for(int i=1; i < N; i++) {
        int p = min(lens[i], lens[i-1]);
        int j ;
        for(j=0; j < p && dks[i][j] == dks[i-1][j]; j++) ;
        if(j >= lens[i] && lens[i-1] > lens[i]) {
            printf("-1\n");
            return 0 ;
        }
        if(j >= p) {
            continue;
        }
        int x = K - dks[i-1][j], y = K - dks[i][j];
        // printf("%d (%d %d %d) => %d %d\n", i, lens[i], p, j, x, y);
        if(x > y) {
            acms[y] ++;
            acms[x] --;
        }
        else {
            gtL = max(gtL, x);
            gtR = min(gtR, y-1);
        }
    }
    // gtR = min(gtR, K-1);
    if(gtR < gtL) {
        printf("-1\n");
        return 0 ;
    }
    for(int i=0, sm=0; i < K; i++) {
        sm += acms[i];
        if(sm == 0 && gtL <= i && i <= gtR) {
            printf("%d\n", i);
            return 0 ;
        }
    }
    printf("-1\n");
}
