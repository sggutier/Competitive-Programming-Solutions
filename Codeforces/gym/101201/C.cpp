#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int arr[limN];

int main() {
    int N, K, r;
    int ans = 0;
    scanf("%d%d%d", &N, &K, &r);
    for(int i=0; i<K; i++)
        scanf("%d", &arr[i]);
    r--;
    arr[K++] = N+1+r;
    arr[K++] = -r;
    sort(arr, arr+K);
    for(int i=1; i<K; i++) {
        printf("%d => %d\n", (arr[i-1]+r), (arr[i]-r));
        ans += max(0, (arr[i]-r) - (arr[i-1]+r) -1);
    }
    printf("%d\n", ans);
}
