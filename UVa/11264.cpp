#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

void testCase() {
    int N;
    int arr[limN];
    int maxLimito[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) 
        scanf("%d", &arr[i]);

    reverse(arr, arr+N);
    memset(maxLimito, 0, sizeof(maxLimito));
    maxLimito[1] = arr[0];
    for(int i=1; i<N; i++) {
        for(int j=N-1; j>0; j--) {
            if(arr[i]>=maxLimito[j])
                continue;
            maxLimito[j+1] = max(maxLimito[j+1], min(maxLimito[j]-arr[i], arr[i]));
        }
        for(int j=0; j<=N; j++) {
            maxLimito[j] = min(maxLimito[j], arr[i]);
        }
    }

    for(int i=N; i>0; i--) {
        if(maxLimito[i]) {
            printf("%d\n", i);
            return;
        }
    }
    printf("0\n");
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
