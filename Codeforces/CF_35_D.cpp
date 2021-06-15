#include <bits/stdc++.h>
using namespace std;

int N, X;
int arr[500];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int ans = 0;
    
    scanf("%d%d", &N, &X);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        arr[i] *= N-i;
    }
    sort(arr, arr+N);

    for(int i=0, s=0;  i<N; i++) {
        s += arr[i];
        if(s > X) break;
        ans = i+1;
    }

    printf("%d\n", ans);
}
