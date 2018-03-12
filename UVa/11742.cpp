#include <bits/stdc++.h>
using namespace std;
const int limN = 9;

void testCase(int n, int m) {
    int arr[limN];
    int rs[m], A[m], B[m];
    int ans = 0;
    
    for(int i=0; i<m; i++)
        scanf("%d%d%d", &A[i], &B[i], &rs[i]);

    for(int i=0; i<n; i++)
        arr[i] = i;

    do {
        int works = 1;
        for(int i=0; i<m; i++) {
            if(rs[i]>0) {
                if(abs(arr[A[i]] - arr[B[i]]) > rs[i]) {
                    works = 0;
                    break;
                }
            }
            else {
                if(abs(arr[A[i]] - arr[B[i]]) < -rs[i]) {
                    works = 0;
                    break;
                }
            }
        }
        ans += works;
    } while(next_permutation(arr, arr+n));

    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
