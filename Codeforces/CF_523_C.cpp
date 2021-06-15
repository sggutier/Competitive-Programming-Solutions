#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char A[limN], B[limN];
int lo[limN], ro[limN];

int main() {
    int N, M ;
    int ans = 0 ;
    
    fgets(A+1, limN, stdin);
    fgets(B+1, limN, stdin);
    N = strlen(A+1)-1;
    A[N+1] = 0;
    M = strlen(B+1)-1;
    B[M+1] = 0;

    for(int i=1, j=1; j<=M; j++) {
        if(A[i] == B[j])
            i++;
        lo[j] = i-1;
    }
    for(int i=N, j=M; j>0; j--) {
        if(A[i] == B[j])
            i--;
        ro[j] = N-i;
    }
    for(int i=1; i+1<=M; i++) {
        if(lo[i]==N && ro[i+1]==N)
            ans ++;
    }

    printf("%d\n", ans);
}
