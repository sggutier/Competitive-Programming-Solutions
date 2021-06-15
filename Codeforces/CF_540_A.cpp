#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;

int main() {
    int N ;
    char A[limN], B[limN];
    int ans = 0;

    scanf("%d", &N);
    scanf("%s%s", A, B);

    for(int i=0; i<N; i++) {
        int d = abs(A[i]-B[i]);
        ans += min(d, 10-d);
    }

    printf("%d\n", ans);
}
