#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int N;
int mat[limN][limN];

void testCase()  {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &mat[i][j]);
    int tot = 0;
    for(int i=0; i<N; i++) {
        for(int j=1; j<i; j++) {
            for(int k=0; k<j; k++) {
                if(mat[i][j] && mat[j][k] && mat[k][i]) {
                    printf("%d %d %d\n", i+1, j+1, k+1);
                    tot ++;
                }
            }
        }
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if(mat[i][j] && mat[j][k] && mat[k][i]) {
                    printf("%d %d %d\n", i+1, j+1, k+1);
                    tot ++;
                }
            }
        }
    }
    printf("total:%d\n", tot);
}

int main() {
    while(scanf("%d", &N)!=EOF) {
        testCase();
        printf("\n");
    }
    
    return 0;
}
