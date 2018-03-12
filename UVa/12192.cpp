#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

int R, C;
int mat[limN][limN];

int query(int minH, int maxH) {
    int ans = -1;
    //printf("=== %d %d\n", minH, maxH);
    for(int j=0; j<C; j++) {
        int ini = 0, fin = R;
        while(ini < fin) {
            int piv = (ini+fin)/2 ;
            if(mat[piv][j] >= minH)
                fin = piv;
            else
                ini = piv+1;
        }
        //printf("%d => %d", j, ini);
        if(ini==R || mat[ini][j]>maxH)
            continue;
        int i = ini;
        ini = 0, fin = min(R-i, C-j)-1;
        while(ini < fin) {
            int piv = (ini+fin)/2 + 1;
            if(mat[i + piv][j + piv] <= maxH)
                ini = piv;
            else
                fin = piv-1;
        }
        //printf(" %d\n", ini);
        ans = max(ans, ini);
    }
    return ans+1;
}

void testCase() {
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            scanf("%d", &mat[i][j]);
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
    printf("-\n");
}

int main() {
    while(scanf("%d%d", &R, &C)!=EOF && (R || C))
        testCase();
}
