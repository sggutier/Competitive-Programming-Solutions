#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int arr[1005];
    int ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0, c=0, d=1; c<N; i+=d) {
        if(i < 0 || i >= N) {
            d *= -1;
            ans ++;
            continue;
        }
        if(arr[i] <= c)  {
            arr[i] = N;
            c ++;
        }
    }

    printf("%d\n", ans);
}
