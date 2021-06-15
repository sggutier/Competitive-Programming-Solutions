#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;

int main() {
    int N, K ;
    char A[LIM_N], B[LIM_N];
    int poss[LIM_N];
    int ans = 0 ;

    scanf("%d%d", &N, &K);
    scanf("%s%s", A, B);

    for(int i=N-1, j=K-1; j >= 0; j--, i--) {
        while(A[i] != B[j])
            i--;
        poss[j] = i;
    }

    for(int i=1; i < K; i++)
        ans = max(ans, poss[i] - poss[i-1]);

    for(int i=0, j=0; j + 1 < K; i++, j++) {
        while(A[i] != B[j])
            i++;
        ans = max(ans, poss[j+1] - i);
    }

    printf("%d\n", ans);
}
