#include <bits/stdc++.h>
using namespace std;

long long testCase(long long int N) {
    if(N<=0LL)
        return 0LL;
    long long ult = 0;
    long long ans = 0LL;
    for(long long i=1; i*i<=N; i++) {
        ult = i;
        ans += N/i;
    }
    long long div = N/ult -1;
    while(div>0) {
        //printf("=> %d %d > %d\n", ult, N/div, div);
        ans += (N/div-ult)*div;
        ult = N/div;
        div --;
    }
    return ans;
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int n; scanf("%d", &n);
        printf("%lld\n", testCase(n));
    }
    return 0;
}
