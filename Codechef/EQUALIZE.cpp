#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int R, C;
int mat[limN][limN];
int crg[limN][limN];

bool funca(int K, int L, int w) {
    int tot = (K*L) / 2;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            crg[i][j] = (mat[i][j] >= w? 1 : 0) - crg[i-1][j-1] + crg[i-1][j] + crg[i][j-1];
            if(i >= K && j >= L &&
               crg[i][j] - crg[i-K][j] - crg[i][j-L] + crg[i-K][j-L] > tot)
                return true;
        }
    }
    return false;
}

int query(int K, int L) {
    int ini = 0, fin = 1e7 + 1;
    while(ini+1 < fin) {
        int piv = (ini+fin)/2;
        if(funca(K, L, piv))
            ini = piv;
        else
            fin = piv;
    }
    return ini;
}

int main() {
    int Q ;

    scanf("%d%d%d", &R, &C, &Q);
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            scanf("%d", &mat[i][j]);
    for(int i=0; i<Q; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
}
