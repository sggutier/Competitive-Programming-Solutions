#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N, M;
int arr[limN], sig[limN];
int X[limN], Y[limN];

int main() {
    int *A = X, *B = Y;
    int ans = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i+1<N; i++) {
        sig[i] = i+1;
        if(arr[i] > arr[i+1])
            X[M++] = i;
    }
    N = M;
    while(N > 0) {
        int u = A[0], s=-1;
        ans ++;
        M = 0;
        for(int i=0; i<N; i++) {
            // printf("%d mata a %d\n", arr[A[i]], arr[sig[A[i]]]);
            if(A[i] != s) {
                u = A[i];
                B[M++] = u;
                // printf("%d (%d) añadido\n", arr[u], u);
            }
            s = sig[A[i]];
            int sg = sig[sig[A[i]]];
            sig[u] = sg;
            if(sg == 0 || arr[sg] > arr[u])
                M--;
        }
        // printf("----\n");
        // getchar();
        N = M;
        swap(A, B);
    }
    printf("%d\n", ans);
}
