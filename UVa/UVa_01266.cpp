#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    int mat[N][N];
    int sumo = 0;
    int r=0, c=N/2;
    int w = 0;

    for(int k=0; k<N; k++) {
        mat[r][c] = ++w;
        //printf("%d %d => %d\n", r, c, w);
        for(int a=1; a<N; a++) {
            r=(r+N-1)%N, c=(c+1)%N;
            mat[r][c] = ++w;
            //printf("%d %d => %d\n", r, c, w);
        }
        //printf("\n");
        r = (r+1)%N;
    }

    for(int i=0; i<N; i++)
        sumo += mat[0][i];

    printf("n=%d, sum=%d\n", N, sumo);
    char stro[15];
    int maxo = 1;
    for(int k=w; k; k/=10, maxo++);
    sprintf(stro, "%%%dd", maxo);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf(stro, mat[i][j]);
        printf("\n");
    }
}

int main() {
    int tc = 0;
    int n;
    while(scanf("%d", &n)!=EOF && n) {
        if(tc++)
            printf("\n");
        testCase(n);
    }
}
