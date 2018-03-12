#include <bits/stdc++.h>
using namespace std;
const int limN = 10;

int ansCnt ;
int crg[limN];
int N, K;
int mat[limN][limN];

void bruta(int msk, int pos, int stp) {
    if(stp==K) {
        ansCnt = 1;
        printf("(");
        for(int i=0; i<K; i++) {
            if(i)
                printf(",");
            printf("%d", crg[i]+1);
        }
        printf(")\n");
        return;
    }
    for(int i=0; i<N; i++) {
        if(((1<<i) & msk) || !mat[pos][i])
            continue;
        crg[stp] = i;
        bruta(msk | (1<<i), i, stp+1);
    }
}

void testCase() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &mat[i][j]);
    K ++ ;
    ansCnt = 0;
    bruta(1, 0, 1);
    if(!ansCnt)
        printf("no walk of length %d\n", K-1);
}

int main() {
    int tc = 0;

    do {
        if(tc)
            printf("\n");
        testCase();
    } while( scanf("%d", &tc)!=EOF );
}
