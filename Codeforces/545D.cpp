#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int W  = 0;
    int sums[limN];
    int N ;
    int arr[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    sums[0] = W;
    sort(arr, arr+N);
    for(int i=0; i<N; i++) {
        int p = upper_bound(sums, sums+W+1, arr[i]) - sums - 1;
        if(p!=W) continue;
        sums[++W] = sums[p] + arr[i];
    }

    printf("%d\n", W);
}
