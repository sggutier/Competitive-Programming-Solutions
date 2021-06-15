#include <bits/stdc++.h>
using namespace std;
const int limN = 18;
const int limB = 1<<limN;

int N ;
double mat[limN][limN];
double ans[limB][limN];
bool usd[limB];
int btNum[limB];

void pb(int w) {
    for(int i=0; i<N; i++)
        printf("%d", (1<<i) & w? 1 : 0);
}

void proca(int msk) {
    if(usd[msk])
        return;
    usd[msk] = true;
    if(msk == (msk & -msk)) {
        ans[msk][btNum[msk]] = 1.0;
        return;
    }
    int w = 0;
    for(int x=msk, i; x; x -= (1<<i)) {
        i = btNum[x & -x];
        for(int y=x - (1<<i), j, sg; y; y -= (1<<j)) {
            j = btNum[y & -y];
            w ++ ;
            sg = msk - (1<<i);
            proca(sg);
            for(int a=0; a<N; a++)
                ans[msk][a] += mat[j][i] * ans[sg][a];
            sg = msk - (1<<j);
            proca(sg);
            for(int a=0; a<N; a++)
                ans[msk][a] += mat[i][j] * ans[sg][a];
        }
    }
    for(int a=0; a<N; a++)
        ans[msk][a] /= w;


    // pb(msk);
    // printf("\n");
    // for(int x=msk, i; x; x -= (1<<i)) {
    //     i = btNum[x & -x];
    //     for(int y=x - (1<<i), j, sg; y; y -= (1<<j)) {
    //         j = btNum[y & -y];
    //         printf("\t %d %d | %d %d | %d %d\n", i, j, x, y, x & - x, y & -y);
    //     }
    // }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%lf", &mat[i][j]);
    for(int i=0; i<N; i++) {
        btNum[1<<i] = i;
        // printf("%d => %d\n", 1<<i, i);
    }
    int k = (1<<N) - 1;
    proca(k);
    for(int i=0; i<N; i++)
        printf("%.9lf ", ans[k][i]);
    printf("\n");
}
