#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int arr[limN];
    int Q ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    for(scanf("%d", &Q); Q; Q--) {
        int a, p ;
        scanf("%d", &a);
        p = upper_bound(arr, arr+N, a) - arr;
        printf("%d\n", p);
    }
}
