#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

long long ans[limN];
int mat[limN][limN];

int main() {
    int N ;
    int ord[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &mat[i][j]);
    for(int i=0; i<N; i++) {
        scanf("%d", &ord[i]);
        ord[i] -- ;
    }

    for(int k=N-1; k>=0; k--) {
        int w = ord[k];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                mat[i][j] = min(mat[i][j], mat[i][w] + mat[w][j]);
        long long sm = 0;
        for(int i=k; i<N; i++) {
            for(int j=k; j<N; j++) {
                sm += mat[ord[i]][ord[j]] ;
            }
        }
        ans[k] = sm;
    }

    for(int i=0; i<N; i++)
        printf("%lld ", ans[i]);
    printf("\n");
}
