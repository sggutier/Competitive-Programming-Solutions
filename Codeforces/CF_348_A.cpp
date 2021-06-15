#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N ;
    int arr[100005];
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        ans = max(ans, arr[i]+1);
    }
    for(int i=0; i<N; i++)
        if(arr[i] == ans-3) {
            printf("%d\n", ans-1);
            return 0;
        }
    printf("%d\n", ans);
}
