#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5;

void testCase(int N, int S) {
    int arr[limN];
    int ans = (1<<30);
    for(int i=0, sum=0, j=0; i<N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        while(j<=i && sum>=S) {
            ans = min(ans, i-j+1);
            sum -= arr[j++];
        }
    }
    printf("%d\n", ans%(1<<30));
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
