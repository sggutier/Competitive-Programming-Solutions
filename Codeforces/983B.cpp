#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

int arr[limN];
int mat[limN][limN];
int ans[limN][limN];

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        mat[i][i] = arr[i];
    }

    for(int d=1; d<N; d++) {
        for(int i=0, j=d; j<N; i++, j++) {
            mat[i][j] = mat[i][j-1] ^ mat[i+1][j];
        }
    }
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         printf("%3d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("------\n");
    for(int i=N-1; i>=0; i--) {
        int w = 0;
        for(int j=i; j<N; j++) {
            w = max(w, mat[i][j]);
            w = max(w, ans[i+1][j]);
            ans[i][j] = w;
        }
    }
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         printf("%3d ", ans[i][j]);
    //     }
    //     printf("\n");
    // }

    int  Q;
    for(scanf("%d", &Q); Q; Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a-1][b-1]);
    }
}
