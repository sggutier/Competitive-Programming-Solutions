#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

void testCase(int N, int d, int r) {
    int A[N], B[N];
    int ans = 0;
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &B[i]);
    sort(A, A+N);
    sort(B, B+N);
    for(int i=0; i<N; i++) {
        ans += max(0, (A[i] + B[N-1-i]) - d)*r;
    }
    printf("%d\n", ans);
}

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c))
        testCase(a, b, c);
    
    return 0;
}
