#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 2e5 + 5;

int main() {
    int N, K;
    par arr[limN];
    int ans = 0;

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i].f);
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i].s);
        arr[i].f -= arr[i].s ;
    }

    sort(arr, arr+N);
    for(int i=0; i<N; i++) {
        arr[i].f += arr[i].s;
        ans += min(arr[i].f, i<K? (int) 1e9 : arr[i].s);
    }

    printf("%d\n", ans);    
}
